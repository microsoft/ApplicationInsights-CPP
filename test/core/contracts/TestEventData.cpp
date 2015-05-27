#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/EventData.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestEventData)
    {
    public:
        
        TEST_METHOD(VerWorksAsExpected)
        {
            EventData item;
            int expected1 = 63;
            
            item.SetVer(expected1);
            int actual = item.GetVer();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 21;
            
            item.SetVer(expected2);
            actual = item.GetVer();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(NameWorksAsExpected)
        {
            EventData item;
            std::wstring expected1 = L"FPkYRwor";
            
            item.SetName(expected1);
            std::wstring actual = item.GetName();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"mwxmSpxU";
            
            item.SetName(expected2);
            actual = item.GetName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(PropertiesWorksAsExpected)
        {
            EventData item;
            std::map<std::wstring, std::wstring> expected1 = { { L"fEUK", L"CmlXfTfm" } };
            
            item.SetProperties(expected1);
            std::map<std::wstring, std::wstring> actual = item.GetProperties();
            Assert::AreEqual(expected1, actual);
            
            std::map<std::wstring, std::wstring> expected2 = { { L"iEHE", L"CmlXfTfm" } };
            
            item.SetProperties(expected2);
            actual = item.GetProperties();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(MeasurementsWorksAsExpected)
        {
            EventData item;
            std::map<std::wstring, double> expected1 = { { L"WxIM", 4.509 } };
            
            item.SetMeasurements(expected1);
            std::map<std::wstring, double> actual = item.GetMeasurements();
            Assert::AreEqual(expected1, actual);
            
            std::map<std::wstring, double> expected2 = { { L"VpiD", 4.509 } };
            
            item.SetMeasurements(expected2);
            actual = item.GetMeasurements();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            EventData item;
            int ver = 63;
            std::wstring name = L"FPkYRwor";
            std::map<std::wstring, std::wstring> properties = { { L"fEUK", L"CmlXfTfm" } };
            std::map<std::wstring, double> measurements = { { L"WxIM", 4.509 } };
            
            item.SetVer(ver);
            item.SetName(name);
            item.SetProperties(properties);
            item.SetMeasurements(measurements);
            
            std::wstring expected = L"{\"ver\":63,\"name\":\"FPkYRwor\",\"properties\":{\"fEUK\":\"CmlXfTfm\"},\"measurements\":{\"WxIM\":4.509000}}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
