#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/DataPoint.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestDataPoint)
    {
    public:
        
        TEST_METHOD(NameWorksAsExpected)
        {
            DataPoint item;
            std::wstring expected1 = L"ILuHEzWe";
            
            item.SetName(expected1);
            std::wstring actual = item.GetName();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"DamjApTx";
            
            item.SetName(expected2);
            actual = item.GetName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(KindWorksAsExpected)
        {
            DataPoint item;
            DataPointType expected1 = (DataPointType)89;
            
            item.SetKind(expected1);
            DataPointType actual = item.GetKind();
            Assert::AreEqual(expected1, actual);
            
            DataPointType expected2 = (DataPointType)69;
            
            item.SetKind(expected2);
            actual = item.GetKind();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ValueWorksAsExpected)
        {
            DataPoint item;
            double expected1 = 0.6264;
            
            item.SetValue(expected1);
            double actual = item.GetValue();
            Assert::AreEqual(expected1, actual);
            
            double expected2 = 1.322;
            
            item.SetValue(expected2);
            actual = item.GetValue();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(CountWorksAsExpected)
        {
            DataPoint item;
            Nullable<int> expected1(92);
            
            item.SetCount(expected1);
            Nullable<int> actual = item.GetCount();
            Assert::AreEqual(expected1, actual);
            
            Nullable<int> expected2(10);
            
            item.SetCount(expected2);
            actual = item.GetCount();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(MinWorksAsExpected)
        {
            DataPoint item;
            Nullable<double> expected1(0.597);
            
            item.SetMin(expected1);
            Nullable<double> actual = item.GetMin();
            Assert::AreEqual(expected1, actual);
            
            Nullable<double> expected2(3.8705);
            
            item.SetMin(expected2);
            actual = item.GetMin();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(MaxWorksAsExpected)
        {
            DataPoint item;
            Nullable<double> expected1(3.0309);
            
            item.SetMax(expected1);
            Nullable<double> actual = item.GetMax();
            Assert::AreEqual(expected1, actual);
            
            Nullable<double> expected2(4.215);
            
            item.SetMax(expected2);
            actual = item.GetMax();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(StdDevWorksAsExpected)
        {
            DataPoint item;
            Nullable<double> expected1(8.2776);
            
            item.SetStdDev(expected1);
            Nullable<double> actual = item.GetStdDev();
            Assert::AreEqual(expected1, actual);
            
            Nullable<double> expected2(4.9077);
            
            item.SetStdDev(expected2);
            actual = item.GetStdDev();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            DataPoint item;
            std::wstring name = L"ILuHEzWe";
            DataPointType kind = (DataPointType)89;
            double value = 0.6264;
            Nullable<int> count(92);
            Nullable<double> minValue(0.597);
            Nullable<double> maxValue(3.0309);
            Nullable<double> stdDev(8.2776);
            
            item.SetName(name);
            item.SetKind(kind);
            item.SetValue(value);
            item.SetCount(count);
            item.SetMin(minValue);
            item.SetMax(maxValue);
            item.SetStdDev(stdDev);
            
            std::wstring expected = L"{\"name\":\"ILuHEzWe\",\"kind\":89,\"value\":0.626400,\"count\":92,\"min\":0.597000,\"max\":3.030900,\"stdDev\":8.277600}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
