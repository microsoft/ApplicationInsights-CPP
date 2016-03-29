#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/RequestData.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestRequestData)
    {
    public:
        
        TEST_METHOD(VerWorksAsExpected)
        {
            RequestData item;
            int expected1 = 44;
            
            item.SetVer(expected1);
            int actual = item.GetVer();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 53;
            
            item.SetVer(expected2);
            actual = item.GetVer();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(IdWorksAsExpected)
        {
            RequestData item;
            std::wstring expected1 = L"MgQDgnwj";
            
            item.SetId(expected1);
            std::wstring actual = item.GetId();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"ZQLhHKEQ";
            
            item.SetId(expected2);
            actual = item.GetId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(NameWorksAsExpected)
        {
            RequestData item;
            std::wstring expected1 = L"IpbmDRHR";
            
            item.SetName(expected1);
            std::wstring actual = item.GetName();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"NMfahvIU";
            
            item.SetName(expected2);
            actual = item.GetName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(StartTimeWorksAsExpected)
        {
            RequestData item;
            std::wstring expected1 = L"kCnNhiSC";
            
            item.SetStartTime(expected1);
            std::wstring actual = item.GetStartTime();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"kDGYgkAM";
            
            item.SetStartTime(expected2);
            actual = item.GetStartTime();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(DurationWorksAsExpected)
        {
            RequestData item;
            std::wstring expected1 = L"pWJMqvrn";
            
            item.SetDuration(expected1);
            std::wstring actual = item.GetDuration();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"sxFglGld";
            
            item.SetDuration(expected2);
            actual = item.GetDuration();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ResponseCodeWorksAsExpected)
        {
            RequestData item;
            std::wstring expected1 = L"HbsJtlrO";
            
            item.SetResponseCode(expected1);
            std::wstring actual = item.GetResponseCode();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"owSqbWQM";
            
            item.SetResponseCode(expected2);
            actual = item.GetResponseCode();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SuccessWorksAsExpected)
        {
            RequestData item;
            bool expected1 = false;
            
            item.SetSuccess(expected1);
            bool actual = item.GetSuccess();
            Assert::AreEqual(expected1, actual);
            
            bool expected2 = true;
            
            item.SetSuccess(expected2);
            actual = item.GetSuccess();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(HttpMethodWorksAsExpected)
        {
            RequestData item;
            std::wstring expected1 = L"OGqVMRyp";
            
            item.SetHttpMethod(expected1);
            std::wstring actual = item.GetHttpMethod();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"ehVeeEjS";
            
            item.SetHttpMethod(expected2);
            actual = item.GetHttpMethod();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(UrlWorksAsExpected)
        {
            RequestData item;
            std::wstring expected1 = L"uZuDIKVi";
            
            item.SetUrl(expected1);
            std::wstring actual = item.GetUrl();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"IrDHfhEX";
            
            item.SetUrl(expected2);
            actual = item.GetUrl();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(PropertiesWorksAsExpected)
        {
            RequestData item;
            std::map<std::wstring, std::wstring> expected1 = { { L"KAbR", L"LoRanEpP" } };
            
            item.SetProperties(expected1);
            std::map<std::wstring, std::wstring> actual = item.GetProperties();
            Assert::AreEqual(expected1, actual);
            
            std::map<std::wstring, std::wstring> expected2 = { { L"KVKV", L"LoRanEpP" } };
            
            item.SetProperties(expected2);
            actual = item.GetProperties();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(MeasurementsWorksAsExpected)
        {
            RequestData item;
            std::map<std::wstring, double> expected1 = { { L"GTJR", 3.9199 } };
            
            item.SetMeasurements(expected1);
            std::map<std::wstring, double> actual = item.GetMeasurements();
            Assert::AreEqual(expected1, actual);
            
            std::map<std::wstring, double> expected2 = { { L"PadB", 3.9199 } };
            
            item.SetMeasurements(expected2);
            actual = item.GetMeasurements();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            RequestData item;
            int ver = 44;
            std::wstring id = L"MgQDgnwj";
            std::wstring name = L"IpbmDRHR";
            std::wstring startTime = L"kCnNhiSC";
            std::wstring duration = L"pWJMqvrn";
            std::wstring responseCode = L"HbsJtlrO";
            bool success = false;
            std::wstring httpMethod = L"OGqVMRyp";
            std::wstring url = L"uZuDIKVi";
            std::map<std::wstring, std::wstring> properties = { { L"KAbR", L"LoRanEpP" } };
            std::map<std::wstring, double> measurements = { { L"GTJR", 3.9199 } };
            
            item.SetVer(ver);
            item.SetId(id);
            item.SetName(name);
            item.SetStartTime(startTime);
            item.SetDuration(duration);
            item.SetResponseCode(responseCode);
            item.SetSuccess(success);
            item.SetHttpMethod(httpMethod);
            item.SetUrl(url);
            item.SetProperties(properties);
            item.SetMeasurements(measurements);
            
            std::wstring expected = L"{\"ver\":44,\"id\":\"MgQDgnwj\",\"name\":\"IpbmDRHR\",\"startTime\":\"kCnNhiSC\",\"duration\":\"pWJMqvrn\",\"responseCode\":\"HbsJtlrO\",\"success\":false,\"httpMethod\":\"OGqVMRyp\",\"url\":\"uZuDIKVi\",\"properties\":{\"KAbR\":\"LoRanEpP\"},\"measurements\":{\"GTJR\":3.919900}}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
