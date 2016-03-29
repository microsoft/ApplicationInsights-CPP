#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Channel/TelemetryChannel.h"
#include "TelemetryClientConfig.h"
#include "TelemetryContext.h"
#include <regex>

#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Windows phone or store
#include <memory>
#include <ppltasks.h>
using namespace concurrency;
#endif
#endif

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef std::wstring wstr;
typedef std::string str;
typedef std::map<std::wstring, std::wstring> map_wstr_wstr;
typedef std::regex re;
#define re_match(input, regex) std::regex_match(input, regex)

namespace core {
	namespace tests
	{
		class MockTelemetryChannel : public TelemetryChannel
		{
		public:
			MockTelemetryChannel(TelemetryClientConfig &config) : TelemetryChannel(config) {}
			int GetChannelId() { return m_channelId; }
			int GetSeqNum() { return m_seqNum; }
			const TelemetryClientConfig *GetConfig() { return m_config; }
			const std::vector<std::wstring> GetBuffer() { return m_buffer; }

			void SetBufferSize(int maxSize) { m_maxBufferSize = maxSize; }

#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Windows phone or store
			DWORD WaitForResponse()
			{
				DWORD dwRet = WaitForSingleObjectEx(hRespRecv, 5000, TRUE);

				if (dwRet == (DWORD)WAIT_FAILED)
				{
					LPVOID lpMsgBuf;
					DWORD error = GetLastError();
					FormatMessage(
						FORMAT_MESSAGE_FROM_SYSTEM |
						FORMAT_MESSAGE_IGNORE_INSERTS,
						nullptr,
						error,
						MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
						(LPTSTR)&lpMsgBuf,
						0, nullptr);
					int i = 0;
				}
				return dwRet;
			}
#endif
#endif
			const HttpResponse& GetResponse() const {
				return resp;
			}
		};

		TEST_CLASS(TestTelemetryChannel)
		{
		public:

			TEST_METHOD(CtorWorksAsExpected)
			{
				wstr iKey = L"foo";
				TelemetryClientConfig config(iKey);

				MockTelemetryChannel channel(config);
				
				Assert::AreNotEqual(0, channel.GetChannelId());
				Assert::AreEqual(0, channel.GetSeqNum());
				Assert::AreEqual(iKey, channel.GetConfig()->GetIKey());
			};

			TEST_METHOD(EnqueueWorksAsExpected)
			{
				wstr iKey = L"foo";
				TelemetryClientConfig config(iKey);
				TelemetryContext context(iKey);
				context.InitContext();

				MockTelemetryChannel channel(config);
				std::vector<std::wstring> buffer;
				int channelId = channel.GetChannelId();
				for (int i = 0; i < 5; i++)
				{
					MessageData telemetry;
					telemetry.SetMessage(L"Hello");

					channel.Enqueue(context, (Domain)telemetry);

					buffer = channel.GetBuffer();
					Assert::AreEqual(i + 1, (int)buffer.size());
					Assert::AreEqual(channelId, channel.GetChannelId());
					Assert::AreEqual(i+1, channel.GetSeqNum());

					std::wstring envelope = *buffer.rbegin();
					std::wstring::size_type namePos = envelope.find(L"Microsoft.ApplicationInsights.Message");
					Assert::AreNotEqual(std::wstring::npos, namePos);

					int timePos = envelope.find(L"time");
					int timeBegin = timePos + 7;
					re dateMatcher("\\d{4}-\\d{2}-\\d{2}T\\d{2}:\\d{2}:\\d{2}.\\d\\d?\\d?Z");
					std::string date = str(&envelope[timeBegin], &envelope[timeBegin + 24]);
					Assert::IsTrue(re_match(date, dateMatcher), L"Invalid regex for date");

					int seqPos = envelope.find(L"seq");
					int channelBegin = seqPos + 6;
					int channelEnd = envelope.find(L":", channelBegin);
					int seqBegin = channelEnd + 1;
					int seqEnd = envelope.find(L"\"", channelBegin);
					std::wstring strChannel = wstr(&envelope[channelBegin], &envelope[channelEnd]);
					std::wstring seq = wstr(&envelope[seqBegin], &envelope[seqEnd]);

					wchar_t channelIdString[256];
					wchar_t indexString[8];
					swprintf_s(channelIdString, 256, L"%d", channelId);
					swprintf_s(indexString, 8, L"%d", i);

					Assert::AreEqual(strChannel.c_str(), channelIdString, L"ChannelId does not match");
					Assert::AreEqual(seq.c_str(), indexString, L"Seq does not match");
				}

			};

			TEST_METHOD(EnqueueAutoSendsWhenMaxBufferSizeIsReached)
			{
				wstr iKey = L"foo";
				TelemetryClientConfig config(iKey);
				TelemetryContext context(iKey);
				context.InitContext();

				MockTelemetryChannel channel(config);
				channel.SetBufferSize(2);
				std::list<std::wstring> buffer;
				int channelId = channel.GetChannelId();

				for (int i = 1; i < 5; i++)
				{
					Assert::AreEqual(channel.GetSeqNum(), i - 1, L"Failed: seq number is not updating");
					
#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Windows phone or store

					auto testTask = create_task([&channel, &context, &i]() -> bool {
#endif	
#endif
					MessageData telemetry;
					telemetry.SetMessage(L"Hello");

					channel.Enqueue(context, (Domain)telemetry);

#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Windows phone or store
					if (i % 2 == 0)
					{
						channel.WaitForResponse();
					}
					return true;
					});
					Sleep(1000);
#endif
#endif
					
					if (i % 2 == 0)
					{
						Assert::AreEqual((int)channel.GetBuffer().size(), 0, L"Failed to auto send");
					}
					else
					{
						Assert::IsTrue((int)channel.GetBuffer().size() > 0, L"Failed to queue data");
					}

					Assert::AreEqual(channel.GetSeqNum(), i, L"Failed: seq number updates after enqueue");
					Assert::AreEqual(channel.GetChannelId(), channelId, L"Failed: channel ID changed");
				}
			};

			TEST_METHOD(SendWorksAsExpected)
			{
				wstr iKey = L"foo";
				TelemetryClientConfig config(iKey);
				TelemetryContext context(iKey);
				context.InitContext();

				MockTelemetryChannel channel(config);
				std::list<std::wstring> buffer;
				int channelId = channel.GetChannelId();
				int seqNum = -1;

#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Windows phone or store
				auto testTask = create_task([&channel, &context, &seqNum]() -> bool {
#endif	
#endif
				MessageData telemetry;
				telemetry.SetMessage(L"Hello");

				channel.Enqueue(context, (Domain)telemetry);
				seqNum  = channel.GetSeqNum();
				Assert::IsTrue((channel.GetBuffer().size() > 0), L"Failed to queue data");
				channel.Send();

#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Windows phone or store
				DWORD ret = channel.WaitForResponse();
				return true;
				});
				Sleep(5000);
#endif
#endif
				Assert::AreEqual((int)channel.GetBuffer().size(), 0, L"Failed to clear queue");
				Assert::AreEqual(channel.GetSeqNum(), seqNum, L"Failed: seq number changed from sending");
				Assert::AreEqual(channel.GetChannelId(), channelId, L"Failed: channel ID changed");
			};
		};
	}
}