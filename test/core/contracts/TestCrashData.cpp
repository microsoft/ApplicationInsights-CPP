#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/CrashData.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestCrashData)
    {
    public:
        
        TEST_METHOD(VerWorksAsExpected)
        {
            CrashData item;
            int expected1 = 5;
            
            item.SetVer(expected1);
            int actual = item.GetVer();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 63;
            
            item.SetVer(expected2);
            actual = item.GetVer();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(HeadersWorksAsExpected)
        {
            CrashData item;
            CrashDataHeaders* expected1 = new CrashDataHeaders();
            
            item.SetHeaders(expected1);
            CrashDataHeaders* actual = item.GetHeaders();
            Assert::AreEqual(expected1, actual);
            
            CrashDataHeaders* expected2 = new CrashDataHeaders();
            
            item.SetHeaders(expected2);
            actual = item.GetHeaders();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ThreadsWorksAsExpected)
        {
            CrashData item;
            std::vector<CrashDataThread*> expected1 = { };
            
            item.SetThreads(expected1);
            std::vector<CrashDataThread*> actual = item.GetThreads();
            Assert::AreEqual(expected1, actual);
            
            std::vector<CrashDataThread*> expected2 = { };
            
            item.SetThreads(expected2);
            actual = item.GetThreads();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(BinariesWorksAsExpected)
        {
            CrashData item;
            std::vector<CrashDataBinary*> expected1 = { };
            
            item.SetBinaries(expected1);
            std::vector<CrashDataBinary*> actual = item.GetBinaries();
            Assert::AreEqual(expected1, actual);
            
            std::vector<CrashDataBinary*> expected2 = { };
            
            item.SetBinaries(expected2);
            actual = item.GetBinaries();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            CrashData item;
            int ver = 5;
            CrashDataHeaders* headers = new CrashDataHeaders();
            std::vector<CrashDataThread*> threads = { };
            std::vector<CrashDataBinary*> binaries = { };
            
            item.SetVer(ver);
            item.SetHeaders(headers);
            item.SetThreads(threads);
            item.SetBinaries(binaries);
            
            std::wstring expected = L"{\"ver\":5,\"headers\":{\"id\":\"\",\"processId\":0,\"parentProcessId\":0,\"crashThread\":0}}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
