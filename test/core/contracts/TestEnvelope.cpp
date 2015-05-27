#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/Envelope.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestEnvelope)
    {
    public:
        
        TEST_METHOD(VerWorksAsExpected)
        {
            Envelope item;
            int expected1 = 80;
            
            item.SetVer(expected1);
            int actual = item.GetVer();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 38;
            
            item.SetVer(expected2);
            actual = item.GetVer();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(NameWorksAsExpected)
        {
            Envelope item;
            std::wstring expected1 = L"adlchSLC";
            
            item.SetName(expected1);
            std::wstring actual = item.GetName();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"BoywoCzj";
            
            item.SetName(expected2);
            actual = item.GetName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(TimeWorksAsExpected)
        {
            Envelope item;
            std::wstring expected1 = L"rdfJJhQs";
            
            item.SetTime(expected1);
            std::wstring actual = item.GetTime();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"zotVaJNt";
            
            item.SetTime(expected2);
            actual = item.GetTime();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SampleRateWorksAsExpected)
        {
            Envelope item;
            double expected1 = 4.3706;
            
            item.SetSampleRate(expected1);
            double actual = item.GetSampleRate();
            Assert::AreEqual(expected1, actual);
            
            double expected2 = 9.2301;
            
            item.SetSampleRate(expected2);
            actual = item.GetSampleRate();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SeqWorksAsExpected)
        {
            Envelope item;
            std::wstring expected1 = L"rCitVJLQ";
            
            item.SetSeq(expected1);
            std::wstring actual = item.GetSeq();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"eTUUGRJV";
            
            item.SetSeq(expected2);
            actual = item.GetSeq();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(IKeyWorksAsExpected)
        {
            Envelope item;
            std::wstring expected1 = L"siOxfiva";
            
            item.SetIKey(expected1);
            std::wstring actual = item.GetIKey();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"mhrUZzEP";
            
            item.SetIKey(expected2);
            actual = item.GetIKey();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(FlagsWorksAsExpected)
        {
            Envelope item;
            long expected1 = 21;
            
            item.SetFlags(expected1);
            long actual = item.GetFlags();
            Assert::AreEqual(expected1, actual);
            
            long expected2 = 13;
            
            item.SetFlags(expected2);
            actual = item.GetFlags();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(DeviceIdWorksAsExpected)
        {
            Envelope item;
            std::wstring expected1 = L"EqYYkvOl";
            
            item.SetDeviceId(expected1);
            std::wstring actual = item.GetDeviceId();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"KgfeStoH";
            
            item.SetDeviceId(expected2);
            actual = item.GetDeviceId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(OsWorksAsExpected)
        {
            Envelope item;
            std::wstring expected1 = L"MaKfLYEt";
            
            item.SetOs(expected1);
            std::wstring actual = item.GetOs();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"MsJHWViR";
            
            item.SetOs(expected2);
            actual = item.GetOs();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(OsVerWorksAsExpected)
        {
            Envelope item;
            std::wstring expected1 = L"rxjitPVg";
            
            item.SetOsVer(expected1);
            std::wstring actual = item.GetOsVer();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"oqhUmUlX";
            
            item.SetOsVer(expected2);
            actual = item.GetOsVer();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(AppIdWorksAsExpected)
        {
            Envelope item;
            std::wstring expected1 = L"rbMgDmCq";
            
            item.SetAppId(expected1);
            std::wstring actual = item.GetAppId();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"YvWhqPpC";
            
            item.SetAppId(expected2);
            actual = item.GetAppId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(AppVerWorksAsExpected)
        {
            Envelope item;
            std::wstring expected1 = L"vsnESigH";
            
            item.SetAppVer(expected1);
            std::wstring actual = item.GetAppVer();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"MOEvauCs";
            
            item.SetAppVer(expected2);
            actual = item.GetAppVer();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(UserIdWorksAsExpected)
        {
            Envelope item;
            std::wstring expected1 = L"tZRephyj";
            
            item.SetUserId(expected1);
            std::wstring actual = item.GetUserId();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"iuJlQhNl";
            
            item.SetUserId(expected2);
            actual = item.GetUserId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(TagsWorksAsExpected)
        {
            Envelope item;
            std::map<std::wstring, std::wstring> expected1 = { { L"rMCx", L"bZQsOeRE" } };
            
            item.SetTags(expected1);
            std::map<std::wstring, std::wstring> actual = item.GetTags();
            Assert::AreEqual(expected1, actual);
            
            std::map<std::wstring, std::wstring> expected2 = { { L"maVc", L"bZQsOeRE" } };
            
            item.SetTags(expected2);
            actual = item.GetTags();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(DataWorksAsExpected)
        {
            Envelope item;
            Base expected1;
            
            item.SetData(expected1);
            Base* actual = item.GetData();
            Assert::AreEqual(&expected1, actual);
            
            Base expected2;
            
            item.SetData(expected2);
            actual = item.GetData();
            Assert::AreEqual(&expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            Envelope item;
            int ver = 80;
            std::wstring name = L"adlchSLC";
            std::wstring time = L"rdfJJhQs";
            double sampleRate = 4.3706;
            std::wstring seq = L"rCitVJLQ";
            std::wstring iKey = L"siOxfiva";
            long flags = 21;
            std::wstring deviceId = L"EqYYkvOl";
            std::wstring os = L"MaKfLYEt";
            std::wstring osVer = L"rxjitPVg";
            std::wstring appId = L"rbMgDmCq";
            std::wstring appVer = L"vsnESigH";
            std::wstring userId = L"tZRephyj";
            std::map<std::wstring, std::wstring> tags = { { L"rMCx", L"bZQsOeRE" } };
            Base data;
            
            item.SetVer(ver);
            item.SetName(name);
            item.SetTime(time);
            item.SetSampleRate(sampleRate);
            item.SetSeq(seq);
            item.SetIKey(iKey);
            item.SetFlags(flags);
            item.SetDeviceId(deviceId);
            item.SetOs(os);
            item.SetOsVer(osVer);
            item.SetAppId(appId);
            item.SetAppVer(appVer);
            item.SetUserId(userId);
            item.SetTags(tags);
            item.SetData(data);
            
            std::wstring expected = L"{\"ver\":80,\"name\":\"adlchSLC\",\"time\":\"rdfJJhQs\",\"sampleRate\":4.370600,\"seq\":\"rCitVJLQ\",\"iKey\":\"siOxfiva\",\"flags\":21.000000,\"deviceId\":\"EqYYkvOl\",\"os\":\"MaKfLYEt\",\"osVer\":\"rxjitPVg\",\"appId\":\"rbMgDmCq\",\"appVer\":\"vsnESigH\",\"userId\":\"tZRephyj\",\"tags\":{\"rMCx\":\"bZQsOeRE\"},\"data\":{}}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
