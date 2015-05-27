#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/ExceptionDetails.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestExceptionDetails)
    {
    public:
        
        TEST_METHOD(IdWorksAsExpected)
        {
            ExceptionDetails item;
            int expected1 = 98;
            
            item.SetId(expected1);
            int actual = item.GetId();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 57;
            
            item.SetId(expected2);
            actual = item.GetId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(OuterIdWorksAsExpected)
        {
            ExceptionDetails item;
            int expected1 = 27;
            
            item.SetOuterId(expected1);
            int actual = item.GetOuterId();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 51;
            
            item.SetOuterId(expected2);
            actual = item.GetOuterId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(TypeNameWorksAsExpected)
        {
            ExceptionDetails item;
            std::wstring expected1 = L"tqoEGGgl";
            
            item.SetTypeName(expected1);
            std::wstring actual = item.GetTypeName();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"WYBOaGPb";
            
            item.SetTypeName(expected2);
            actual = item.GetTypeName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(MessageWorksAsExpected)
        {
            ExceptionDetails item;
            std::wstring expected1 = L"qThIpXfu";
            
            item.SetMessage(expected1);
            std::wstring actual = item.GetMessage();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"xqpwFlLr";
            
            item.SetMessage(expected2);
            actual = item.GetMessage();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(HasFullStackWorksAsExpected)
        {
            ExceptionDetails item;
            bool expected1 = true;
            
            item.SetHasFullStack(expected1);
            bool actual = item.GetHasFullStack();
            Assert::AreEqual(expected1, actual);
            
            bool expected2 = false;
            
            item.SetHasFullStack(expected2);
            actual = item.GetHasFullStack();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(StackWorksAsExpected)
        {
            ExceptionDetails item;
            std::wstring expected1 = L"fLmysXWS";
            
            item.SetStack(expected1);
            std::wstring actual = item.GetStack();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"HxcveEPO";
            
            item.SetStack(expected2);
            actual = item.GetStack();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ParsedStackWorksAsExpected)
        {
            ExceptionDetails item;
            std::vector<StackFrame*> expected1 = { };
            
            item.SetParsedStack(expected1);
            std::vector<StackFrame*> actual = item.GetParsedStack();
            Assert::AreEqual(expected1, actual);
            
            std::vector<StackFrame*> expected2 = { };
            
            item.SetParsedStack(expected2);
            actual = item.GetParsedStack();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            ExceptionDetails item;
            int id = 98;
            int outerId = 27;
            std::wstring typeName = L"tqoEGGgl";
            std::wstring message = L"qThIpXfu";
            bool hasFullStack = true;
            std::wstring stack = L"fLmysXWS";
            std::vector<StackFrame*> parsedStack = { };
            
            item.SetId(id);
            item.SetOuterId(outerId);
            item.SetTypeName(typeName);
            item.SetMessage(message);
            item.SetHasFullStack(hasFullStack);
            item.SetStack(stack);
            item.SetParsedStack(parsedStack);
            
            std::wstring expected = L"{\"id\":98,\"outerId\":27,\"typeName\":\"tqoEGGgl\",\"message\":\"qThIpXfu\",\"hasFullStack\":true,\"stack\":\"fLmysXWS\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
