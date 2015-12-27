#include "targetver.h"
#include "specializations.h"
#include "CppUnitTest.h"
#include "TelemetryContext.h"
#include "TelemetryClient.h"
#include "Contracts/Contracts.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef std::wstring wstr;

namespace core {
	namespace tests
	{
		namespace telemetryClient
		{
			class MockTelemetryChannel : public TelemetryChannel
			{
			public:
				MockTelemetryChannel(TelemetryClientConfig config)
					: TelemetryChannel(config), recvTelemetry(nullptr)
				{
				}

				std::vector<std::wstring> GetBuffer()
				{
					return m_buffer;
				}

			private:
				Domain* recvTelemetry;
			};

			class MockTelemetryClient : public TelemetryClient
			{
			public:
				MockTelemetryClient(std::wstring& iKey) :
					TelemetryClient(iKey)
				{
				}

				MockTelemetryChannel *GetChannel() const { return (MockTelemetryChannel*)m_channel.get(); }

			};

			TEST_CLASS(TestTelemetryClient)
			{
			public:

				TEST_METHOD(GetConfigWorksAsExpected)
				{
					std::wstring iKey = L"MY IKEY";
					TelemetryClient tc(iKey);
					TelemetryClientConfig *config = tc.GetConfig();

					Assert::AreEqual(iKey, config->GetIKey());
				};

				TEST_METHOD(TrackEventWorksAsExpected)
				{
					std::wstring eventName = L"MY TRACK EVENT";
					std::wstring iKey = L"MY_IKEY";
					MockTelemetryClient tc(iKey);
					tc.Flush();
					tc.TrackEvent(eventName);

					std::vector<std::wstring> data = tc.GetChannel()->GetBuffer();
					Assert::AreEqual(1, (int)data.size());
					Assert::IsTrue(data[0].find(eventName) != std::string::npos, L"Unable to find track event name");
				};

				TEST_METHOD(DisableTrackingWorksAsExpected)
				{
					std::wstring eventName = L"MY TRACK EVENT";
					std::wstring iKey = L"MY_IKEY";
					MockTelemetryClient tc(iKey);
					tc.Flush();
					tc.DisableTracking();

					tc.TrackEvent(eventName);

					std::vector<std::wstring> data = tc.GetChannel()->GetBuffer();
					Assert::AreEqual(0, (int)data.size());
				}

				TEST_METHOD(TogglingTrackingWorksAsExpected)
				{
					std::wstring eventName = L"MY TRACK EVENT";
					std::wstring iKey = L"MY_IKEY";
					MockTelemetryClient tc(iKey);
					tc.Flush();
					tc.DisableTracking();
					tc.TrackEvent(eventName);
					std::vector<std::wstring> data = tc.GetChannel()->GetBuffer();
					Assert::AreEqual(0, (int)data.size());

					tc.EnableTracking();
					tc.TrackEvent(eventName);
					data = tc.GetChannel()->GetBuffer();
					Assert::AreEqual(1, (int)data.size());
					Assert::IsTrue(data[0].find(eventName) != std::string::npos, L"Unable to find track event name");
				}
			};
		}
	}
}
