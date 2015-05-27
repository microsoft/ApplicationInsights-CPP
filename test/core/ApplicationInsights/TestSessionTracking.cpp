#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "TelemetryClient.h"

using namespace ApplicationInsights::CX;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::Foundation;
using namespace Windows::Storage;

namespace core {
	namespace tests
	{
		namespace ApplicationInsights
		{
			TEST_CLASS(TestSessionTracking)
			{
			public:

				TEST_METHOD(CtorWorksAsExpected)
				{
					SessionTracking ^session = ref new SessionTracking();
				};
				
				TEST_METHOD(InitializeWorksAsExpected)
				{
					String^ iKey = L"IKEYSTRING";
					SessionTracking ^session = ref new SessionTracking();
					session->Initialize(nullptr, nullptr, iKey);
				};

				TEST_METHOD(InitializeWorksWithNullsAsExpected)
				{
					SessionTracking ^session = ref new SessionTracking();
					session->Initialize(nullptr, nullptr, nullptr);
				};

				TEST_METHOD(SuspendWorksAsExpected)
				{
					String^ iKey = L"IKEYSTRING";
					String^ object = L"OBJECT";
					SessionTracking ^session = ref new SessionTracking();
					session->Initialize(nullptr, nullptr, iKey);

					Windows::Globalization::Calendar^ beforeCal = ref new Windows::Globalization::Calendar();
					Windows::Foundation::DateTime before = beforeCal->GetDateTime();

					session->OnSuspending(object, nullptr);

					Windows::Globalization::Calendar^ afterCal = ref new Windows::Globalization::Calendar();
					Windows::Foundation::DateTime after = afterCal->GetDateTime();

					ApplicationDataContainer^ localSettings = ApplicationData::Current->LocalSettings;
					ApplicationDataContainer^ container = localSettings->CreateContainer("AppInsights", ApplicationDataCreateDisposition::Always);
					auto values = localSettings->Containers->Lookup("AppInsights")->Values;

					DateTime lastBackground;
					if (values->HasKey("lastBackground"))
					{
						lastBackground = (DateTime)values->Lookup("lastBackground");
					}
					else
					{
						Assert::IsTrue(false, L"Failed to get last backgrounded time");
					}

					Assert::IsTrue(lastBackground.UniversalTime > before.UniversalTime);
					Assert::IsTrue(lastBackground.UniversalTime < after.UniversalTime);
				};

				TEST_METHOD(ResumeWithoutRenewWorksAsExpected)
				{
					String^ object = L"OBJECT";
					String^ iKey = L"IKEYSTRING";
					SessionTracking ^session = ref new SessionTracking();
					session->Initialize(nullptr, nullptr, iKey);

					session->OnSuspending(object, nullptr);
					session->OnResume(object, object);
				};

				/*TEST_METHOD(ResumeWithRenewWorksAsExpected)
				{
					String^ object = L"OBJECT";
					String^ iKey = L"IKEYSTRING";
					SessionTracking ^session = ref new SessionTracking();
					session->Initialize(nullptr, iKey);

					session->OnSuspending(object, nullptr);
					Sleep(21 * 1000);
					session->OnResume(object, object);
				};*/
			};
		}
	}
}
