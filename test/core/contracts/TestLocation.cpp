#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/Location.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestLocation)
    {
    public:
        
        TEST_METHOD(IpWorksAsExpected)
        {
            Location item;
            Nullable<std::wstring> expected1(L"hmrnPNLx");
            
            item.SetIp(expected1);
            Nullable<std::wstring> actual = item.GetIp();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"WjNsWtwq");
            
            item.SetIp(expected2);
            actual = item.GetIp();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            Location item;
            Nullable<std::wstring> ip(L"hmrnPNLx");
            
            item.SetIp(ip);
            
            std::wstring expected = L"{\"ai.location.ip\":\"hmrnPNLx\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
