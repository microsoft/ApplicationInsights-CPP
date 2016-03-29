#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/StackFrame.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestStackFrame)
    {
    public:
        
        TEST_METHOD(LevelWorksAsExpected)
        {
            StackFrame item;
            int expected1 = 37;
            
            item.SetLevel(expected1);
            int actual = item.GetLevel();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 27;
            
            item.SetLevel(expected2);
            actual = item.GetLevel();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(MethodWorksAsExpected)
        {
            StackFrame item;
            std::wstring expected1 = L"EkQgDpPN";
            
            item.SetMethod(expected1);
            std::wstring actual = item.GetMethod();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"PfRZhlsX";
            
            item.SetMethod(expected2);
            actual = item.GetMethod();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(AssemblyWorksAsExpected)
        {
            StackFrame item;
            std::wstring expected1 = L"GxIJFkxm";
            
            item.SetAssembly(expected1);
            std::wstring actual = item.GetAssembly();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"QYXvOpuB";
            
            item.SetAssembly(expected2);
            actual = item.GetAssembly();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(FileNameWorksAsExpected)
        {
            StackFrame item;
            std::wstring expected1 = L"RmInsZZW";
            
            item.SetFileName(expected1);
            std::wstring actual = item.GetFileName();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"nFMPfcAe";
            
            item.SetFileName(expected2);
            actual = item.GetFileName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(LineWorksAsExpected)
        {
            StackFrame item;
            int expected1 = 78;
            
            item.SetLine(expected1);
            int actual = item.GetLine();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 83;
            
            item.SetLine(expected2);
            actual = item.GetLine();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            StackFrame item;
            int level = 37;
            std::wstring method = L"EkQgDpPN";
            std::wstring assembly = L"GxIJFkxm";
            std::wstring fileName = L"RmInsZZW";
            int line = 78;
            
            item.SetLevel(level);
            item.SetMethod(method);
            item.SetAssembly(assembly);
            item.SetFileName(fileName);
            item.SetLine(line);
            
            std::wstring expected = L"{\"level\":37,\"method\":\"EkQgDpPN\",\"assembly\":\"GxIJFkxm\",\"fileName\":\"RmInsZZW\",\"line\":78}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
