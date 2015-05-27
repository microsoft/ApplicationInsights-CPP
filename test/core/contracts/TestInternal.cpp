#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/Internal.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestInternal)
    {
    public:
        
        TEST_METHOD(SdkVersionWorksAsExpected)
        {
            Internal item;
            Nullable<std::wstring> expected1(L"fmwchHWF");
            
            item.SetSdkVersion(expected1);
            Nullable<std::wstring> actual = item.GetSdkVersion();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"eqmowGLD");
            
            item.SetSdkVersion(expected2);
            actual = item.GetSdkVersion();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(AgentVersionWorksAsExpected)
        {
            Internal item;
            Nullable<std::wstring> expected1(L"eMUeMREZ");
            
            item.SetAgentVersion(expected1);
            Nullable<std::wstring> actual = item.GetAgentVersion();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"QkYKBHbG");
            
            item.SetAgentVersion(expected2);
            actual = item.GetAgentVersion();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            Internal item;
            Nullable<std::wstring> sdkVersion(L"fmwchHWF");
            Nullable<std::wstring> agentVersion(L"eMUeMREZ");
            
            item.SetSdkVersion(sdkVersion);
            item.SetAgentVersion(agentVersion);
            
            std::wstring expected = L"{\"ai.internal.sdkVersion\":\"fmwchHWF\",\"ai.internal.agentVersion\":\"eMUeMREZ\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
