#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/MessageData.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestMessageData)
    {
    public:
        
        TEST_METHOD(VerWorksAsExpected)
        {
            MessageData item;
            int expected1 = 38;
            
            item.SetVer(expected1);
            int actual = item.GetVer();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 92;
            
            item.SetVer(expected2);
            actual = item.GetVer();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(MessageWorksAsExpected)
        {
            MessageData item;
            std::wstring expected1 = L"cYQXvzXJ";
            
            item.SetMessage(expected1);
            std::wstring actual = item.GetMessage();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"ULhtEnAd";
            
            item.SetMessage(expected2);
            actual = item.GetMessage();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SeverityLevelWorksAsExpected)
        {
            MessageData item;
            Nullable<SeverityLevel> expected1((SeverityLevel)91);
            
            item.SetSeverityLevel(expected1);
            Nullable<SeverityLevel> actual = item.GetSeverityLevel();
            Assert::AreEqual(expected1, actual);
            
            Nullable<SeverityLevel> expected2((SeverityLevel)30);
            
            item.SetSeverityLevel(expected2);
            actual = item.GetSeverityLevel();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(PropertiesWorksAsExpected)
        {
            MessageData item;
            std::map<std::wstring, std::wstring> expected1 = { { L"yCBA", L"KevMpBvm" } };
            
            item.SetProperties(expected1);
            std::map<std::wstring, std::wstring> actual = item.GetProperties();
            Assert::AreEqual(expected1, actual);
            
            std::map<std::wstring, std::wstring> expected2 = { { L"IMVY", L"KevMpBvm" } };
            
            item.SetProperties(expected2);
            actual = item.GetProperties();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            MessageData item;
            int ver = 38;
            std::wstring message = L"cYQXvzXJ";
            Nullable<SeverityLevel> severityLevel((SeverityLevel)91);
            std::map<std::wstring, std::wstring> properties = { { L"yCBA", L"KevMpBvm" } };
            
            item.SetVer(ver);
            item.SetMessage(message);
            item.SetSeverityLevel(severityLevel);
            item.SetProperties(properties);
            
            std::wstring expected = L"{\"ver\":38,\"message\":\"cYQXvzXJ\",\"severityLevel\":91,\"properties\":{\"yCBA\":\"KevMpBvm\"}}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
