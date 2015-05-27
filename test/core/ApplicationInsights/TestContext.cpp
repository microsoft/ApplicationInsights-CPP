#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "TelemetryClient.h"
#include "Contracts/Session.h"


using namespace ApplicationInsights::CX;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

namespace core {
	namespace tests
	{
		namespace ApplicationInsights
		{
			TEST_CLASS(TestContext)
			{
			public:
				TEST_METHOD(SessionContextWorksAsExpected)
				{
					Session item;
					Nullable<std::wstring> expectedId(L"loQoJqjW");
					Nullable<std::wstring> expectedIsFirst(L"XoyYwPiz");
					Nullable<std::wstring> expectedIsNew(L"zFBXDCpK");

					item.SetId(expectedId);
					item.SetIsFirst(expectedIsFirst);
					item.SetIsNew(expectedIsNew);

					Session item2;
					Assert::AreEqual(expectedId, item2.GetId(), L"Session ids don't match");
					Assert::AreEqual(expectedIsFirst, item2.GetIsFirst(), L"Session isFirsts don't match");
					Assert::AreEqual(expectedIsNew, item2.GetIsNew(), L"Session isNews don't match");
				};

				TEST_METHOD(UserContextWorksAsExpected)
				{
					User item;
					Nullable<std::wstring> accountAcquisitionDate(L"kQRXjtex");
					Nullable<std::wstring> accountId(L"KvBXxURr");
					Nullable<std::wstring> userAgent(L"WSOZIoCZ");
					Nullable<std::wstring> id(L"yqjDGfyE");
					Nullable<std::wstring> storeRegion(L"bCyqrnEO");

					item.SetAccountAcquisitionDate(accountAcquisitionDate);
					item.SetAccountId(accountId);
					item.SetUserAgent(userAgent);
					item.SetId(id);
					item.SetStoreRegion(storeRegion);

					User item2;
					Assert::AreEqual(accountAcquisitionDate, item2.GetAccountAcquisitionDate(), L"User acquisition dates don't match");
					Assert::AreEqual(accountId, item2.GetAccountId(), L"User account ids don't match");
					Assert::AreEqual(userAgent, item2.GetUserAgent(), L"User agents don't match");
					Assert::AreEqual(id, item2.GetId(), L"User ids don't match");
					Assert::AreEqual(storeRegion, item2.GetStoreRegion(), L"User store regions don't match");
				};
			};
		}
	}
}