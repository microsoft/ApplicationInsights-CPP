#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/CrashDataHeaders.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestCrashDataHeaders)
    {
    public:
        
        TEST_METHOD(IdWorksAsExpected)
        {
            CrashDataHeaders item;
            std::wstring expected1 = L"nRaImfZV";
            
            item.SetId(expected1);
            std::wstring actual = item.GetId();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"sWqDnjpk";
            
            item.SetId(expected2);
            actual = item.GetId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ProcessWorksAsExpected)
        {
            CrashDataHeaders item;
            std::wstring expected1 = L"GvhGoNhq";
            
            item.SetProcess(expected1);
            std::wstring actual = item.GetProcess();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"taGEeMeF";
            
            item.SetProcess(expected2);
            actual = item.GetProcess();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ProcessIdWorksAsExpected)
        {
            CrashDataHeaders item;
            int expected1 = 93;
            
            item.SetProcessId(expected1);
            int actual = item.GetProcessId();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 69;
            
            item.SetProcessId(expected2);
            actual = item.GetProcessId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ParentProcessWorksAsExpected)
        {
            CrashDataHeaders item;
            std::wstring expected1 = L"OtVSvyVR";
            
            item.SetParentProcess(expected1);
            std::wstring actual = item.GetParentProcess();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"tJSelIla";
            
            item.SetParentProcess(expected2);
            actual = item.GetParentProcess();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ParentProcessIdWorksAsExpected)
        {
            CrashDataHeaders item;
            int expected1 = 43;
            
            item.SetParentProcessId(expected1);
            int actual = item.GetParentProcessId();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 45;
            
            item.SetParentProcessId(expected2);
            actual = item.GetParentProcessId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(CrashThreadWorksAsExpected)
        {
            CrashDataHeaders item;
            int expected1 = 54;
            
            item.SetCrashThread(expected1);
            int actual = item.GetCrashThread();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 7;
            
            item.SetCrashThread(expected2);
            actual = item.GetCrashThread();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ApplicationPathWorksAsExpected)
        {
            CrashDataHeaders item;
            std::wstring expected1 = L"GWouTsZs";
            
            item.SetApplicationPath(expected1);
            std::wstring actual = item.GetApplicationPath();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"unBdZiLU";
            
            item.SetApplicationPath(expected2);
            actual = item.GetApplicationPath();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ApplicationIdentifierWorksAsExpected)
        {
            CrashDataHeaders item;
            std::wstring expected1 = L"QzNlPUbV";
            
            item.SetApplicationIdentifier(expected1);
            std::wstring actual = item.GetApplicationIdentifier();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"LpJpOJmf";
            
            item.SetApplicationIdentifier(expected2);
            actual = item.GetApplicationIdentifier();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ApplicationBuildWorksAsExpected)
        {
            CrashDataHeaders item;
            std::wstring expected1 = L"fwUNQbuA";
            
            item.SetApplicationBuild(expected1);
            std::wstring actual = item.GetApplicationBuild();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"hVcBtSBg";
            
            item.SetApplicationBuild(expected2);
            actual = item.GetApplicationBuild();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ExceptionTypeWorksAsExpected)
        {
            CrashDataHeaders item;
            std::wstring expected1 = L"NfqOpXKe";
            
            item.SetExceptionType(expected1);
            std::wstring actual = item.GetExceptionType();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"wAyLocTC";
            
            item.SetExceptionType(expected2);
            actual = item.GetExceptionType();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ExceptionCodeWorksAsExpected)
        {
            CrashDataHeaders item;
            std::wstring expected1 = L"ibBrzXYt";
            
            item.SetCrashExceptionCode(expected1);
            std::wstring actual = item.GetCrashExceptionCode();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"mTKQKEYE";
            
            item.SetCrashExceptionCode(expected2);
            actual = item.GetCrashExceptionCode();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ExceptionAddressWorksAsExpected)
        {
            CrashDataHeaders item;
            std::wstring expected1 = L"AATkDbQT";
            
            item.SetExceptionAddress(expected1);
            std::wstring actual = item.GetExceptionAddress();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"CDXwNFrA";
            
            item.SetExceptionAddress(expected2);
            actual = item.GetExceptionAddress();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ExceptionReasonWorksAsExpected)
        {
            CrashDataHeaders item;
            std::wstring expected1 = L"VzHVDGhD";
            
            item.SetExceptionReason(expected1);
            std::wstring actual = item.GetExceptionReason();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"WWDoZfWa";
            
            item.SetExceptionReason(expected2);
            actual = item.GetExceptionReason();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            CrashDataHeaders item;
            std::wstring id = L"nRaImfZV";
            std::wstring process = L"GvhGoNhq";
            int processId = 93;
            std::wstring parentProcess = L"OtVSvyVR";
            int parentProcessId = 43;
            int crashThread = 54;
            std::wstring applicationPath = L"GWouTsZs";
            std::wstring applicationIdentifier = L"QzNlPUbV";
            std::wstring applicationBuild = L"fwUNQbuA";
            std::wstring exceptionType = L"NfqOpXKe";
            std::wstring exceptionCode = L"ibBrzXYt";
            std::wstring exceptionAddress = L"AATkDbQT";
            std::wstring exceptionReason = L"VzHVDGhD";
            
            item.SetId(id);
            item.SetProcess(process);
            item.SetProcessId(processId);
            item.SetParentProcess(parentProcess);
            item.SetParentProcessId(parentProcessId);
            item.SetCrashThread(crashThread);
            item.SetApplicationPath(applicationPath);
            item.SetApplicationIdentifier(applicationIdentifier);
            item.SetApplicationBuild(applicationBuild);
            item.SetExceptionType(exceptionType);
            item.SetCrashExceptionCode(exceptionCode);
            item.SetExceptionAddress(exceptionAddress);
            item.SetExceptionReason(exceptionReason);
            
            std::wstring expected = L"{\"id\":\"nRaImfZV\",\"process\":\"GvhGoNhq\",\"processId\":93,\"parentProcess\":\"OtVSvyVR\",\"parentProcessId\":43,\"crashThread\":54,\"applicationPath\":\"GWouTsZs\",\"applicationIdentifier\":\"QzNlPUbV\",\"applicationBuild\":\"fwUNQbuA\",\"exceptionType\":\"NfqOpXKe\",\"exceptionCode\":\"ibBrzXYt\",\"exceptionAddress\":\"AATkDbQT\",\"exceptionReason\":\"VzHVDGhD\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
