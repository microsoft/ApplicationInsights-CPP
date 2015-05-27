#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/User.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestUser)
    {
    public:
        
        TEST_METHOD(AccountAcquisitionDateWorksAsExpected)
        {
            User item;
            Nullable<std::wstring> expected1(L"kQRXjtex");
            
            item.SetAccountAcquisitionDate(expected1);
            Nullable<std::wstring> actual = item.GetAccountAcquisitionDate();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"IDfJdAQj");
            
            item.SetAccountAcquisitionDate(expected2);
            actual = item.GetAccountAcquisitionDate();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(AccountIdWorksAsExpected)
        {
            User item;
            Nullable<std::wstring> expected1(L"KvBXxURr");
            
            item.SetAccountId(expected1);
            Nullable<std::wstring> actual = item.GetAccountId();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"GMHatHCH");
            
            item.SetAccountId(expected2);
            actual = item.GetAccountId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(UserAgentWorksAsExpected)
        {
            User item;
            Nullable<std::wstring> expected1(L"WSOZIoCZ");
            
            item.SetUserAgent(expected1);
            Nullable<std::wstring> actual = item.GetUserAgent();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"kXIuMSWo");
            
            item.SetUserAgent(expected2);
            actual = item.GetUserAgent();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(IdWorksAsExpected)
        {
            User item;
            Nullable<std::wstring> expected1(L"yqjDGfyE");
            
            item.SetId(expected1);
            Nullable<std::wstring> actual = item.GetId();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"rPqqKNPC");
            
            item.SetId(expected2);
            actual = item.GetId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(StoreRegionWorksAsExpected)
        {
            User item;
            Nullable<std::wstring> expected1(L"bCyqrnEO");
            
            item.SetStoreRegion(expected1);
            Nullable<std::wstring> actual = item.GetStoreRegion();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"pdzGcZdC");
            
            item.SetStoreRegion(expected2);
            actual = item.GetStoreRegion();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
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
            
            std::wstring expected = L"{\"ai.user.accountAcquisitionDate\":\"kQRXjtex\",\"ai.user.accountId\":\"KvBXxURr\",\"ai.user.userAgent\":\"WSOZIoCZ\",\"ai.user.id\":\"yqjDGfyE\",\"ai.user.storeRegion\":\"bCyqrnEO\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
