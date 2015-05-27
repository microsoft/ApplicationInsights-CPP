#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/Application.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestApplication)
    {
    public:
        
        TEST_METHOD(VerWorksAsExpected)
        {
            Application item;
            Nullable<std::wstring> expected1(L"GLvyAJsZ");
            
            item.SetVer(expected1);
            Nullable<std::wstring> actual = item.GetVer();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"eMtJfeXF");
            
            item.SetVer(expected2);
            actual = item.GetVer();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(BuildWorksAsExpected)
        {
            Application item;
            Nullable<std::wstring> expected1(L"GQZwnwSD");
            
            item.SetBuild(expected1);
            Nullable<std::wstring> actual = item.GetBuild();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"bkKvAVtR");
            
            item.SetBuild(expected2);
            actual = item.GetBuild();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            Application item;
            Nullable<std::wstring> ver(L"GLvyAJsZ");
            Nullable<std::wstring> build(L"GQZwnwSD");
            
            item.SetVer(ver);
            item.SetBuild(build);
            
            std::wstring expected = L"{\"ai.application.ver\":\"GLvyAJsZ\",\"ai.application.build\":\"GQZwnwSD\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
