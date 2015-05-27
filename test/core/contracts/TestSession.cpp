#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/Session.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestSession)
    {
    public:
        
        TEST_METHOD(IdWorksAsExpected)
        {
            Session item;
            Nullable<std::wstring> expected1(L"loQoJqjW");
            
            item.SetId(expected1);
            Nullable<std::wstring> actual = item.GetId();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"wqzRpTBu");
            
            item.SetId(expected2);
            actual = item.GetId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(IsFirstWorksAsExpected)
        {
            Session item;
            Nullable<std::wstring> expected1(L"XoyYwPiz");
            
            item.SetIsFirst(expected1);
            Nullable<std::wstring> actual = item.GetIsFirst();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"hZyQkrHb");
            
            item.SetIsFirst(expected2);
            actual = item.GetIsFirst();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(IsNewWorksAsExpected)
        {
            Session item;
            Nullable<std::wstring> expected1(L"zFBXDCpK");
            
            item.SetIsNew(expected1);
            Nullable<std::wstring> actual = item.GetIsNew();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"VpGpWUFE");
            
            item.SetIsNew(expected2);
            actual = item.GetIsNew();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            Session item;
            Nullable<std::wstring> id(L"loQoJqjW");
            Nullable<std::wstring> isFirst(L"XoyYwPiz");
            Nullable<std::wstring> isNew(L"zFBXDCpK");
            
            item.SetId(id);
            item.SetIsFirst(isFirst);
            item.SetIsNew(isNew);
            
            std::wstring expected = L"{\"ai.session.id\":\"loQoJqjW\",\"ai.session.isFirst\":\"XoyYwPiz\",\"ai.session.isNew\":\"zFBXDCpK\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
