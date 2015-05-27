#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/SessionStateData.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestSessionStateData)
    {
    public:
        
        TEST_METHOD(VerWorksAsExpected)
        {
            SessionStateData item;
            int expected1 = 4;
            
            item.SetVer(expected1);
            int actual = item.GetVer();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 35;
            
            item.SetVer(expected2);
            actual = item.GetVer();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(StateWorksAsExpected)
        {
            SessionStateData item;
            SessionState expected1 = (SessionState)52;
            
            item.SetState(expected1);
            SessionState actual = item.GetState();
            Assert::AreEqual(expected1, actual);
            
            SessionState expected2 = (SessionState)87;
            
            item.SetState(expected2);
            actual = item.GetState();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            SessionStateData item;
            int ver = 4;
            SessionState state = (SessionState)52;
            
            item.SetVer(ver);
            item.SetState(state);
            
            std::wstring expected = L"{\"ver\":4,\"state\":52}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
