#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/Base.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestBase)
    {
    public:
        
        TEST_METHOD(BaseTypeWorksAsExpected)
        {
            Base item;
            std::wstring expected1 = L"DkiuYcvD";
            
            item.SetBaseType(expected1);
            std::wstring actual = item.GetBaseType();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"cMlRgUYh";
            
            item.SetBaseType(expected2);
            actual = item.GetBaseType();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            Base item;
            std::wstring baseType = L"DkiuYcvD";
            
            item.SetBaseType(baseType);
            
            std::wstring expected = L"{\"baseType\":\"DkiuYcvD\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
