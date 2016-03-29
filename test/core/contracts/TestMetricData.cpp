#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/MetricData.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestMetricData)
    {
    public:
        
        TEST_METHOD(VerWorksAsExpected)
        {
            MetricData item;
            int expected1 = 56;
            
            item.SetVer(expected1);
            int actual = item.GetVer();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 38;
            
            item.SetVer(expected2);
            actual = item.GetVer();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(MetricsWorksAsExpected)
        {
            MetricData item;
            std::vector<DataPoint*> expected1 = { };
            
            item.SetMetrics(expected1);
            std::vector<DataPoint*> actual = item.GetMetrics();
            Assert::AreEqual(expected1, actual);
            
            std::vector<DataPoint*> expected2 = { };
            
            item.SetMetrics(expected2);
            actual = item.GetMetrics();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(PropertiesWorksAsExpected)
        {
            MetricData item;
            std::map<std::wstring, std::wstring> expected1 = { { L"nUVt", L"UsxiClbK" } };
            
            item.SetProperties(expected1);
            std::map<std::wstring, std::wstring> actual = item.GetProperties();
            Assert::AreEqual(expected1, actual);
            
            std::map<std::wstring, std::wstring> expected2 = { { L"GxCS", L"UsxiClbK" } };
            
            item.SetProperties(expected2);
            actual = item.GetProperties();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            MetricData item;
            int ver = 56;
            std::vector<DataPoint*> metrics = { };
            std::map<std::wstring, std::wstring> properties = { { L"nUVt", L"UsxiClbK" } };
            
            item.SetVer(ver);
            item.SetMetrics(metrics);
            item.SetProperties(properties);
            
            std::wstring expected = L"{\"ver\":56,\"metrics\":[],\"properties\":{\"nUVt\":\"UsxiClbK\"}}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
