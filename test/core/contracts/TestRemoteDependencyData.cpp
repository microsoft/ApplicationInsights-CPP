#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/RemoteDependencyData.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestRemoteDependencyData)
    {
    public:
        
        TEST_METHOD(VerWorksAsExpected)
        {
            RemoteDependencyData item;
            int expected1 = 60;
            
            item.SetVer(expected1);
            int actual = item.GetVer();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 92;
            
            item.SetVer(expected2);
            actual = item.GetVer();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(NameWorksAsExpected)
        {
            RemoteDependencyData item;
            std::wstring expected1 = L"ImFOjAtD";
            
            item.SetName(expected1);
            std::wstring actual = item.GetName();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"xXicyvLb";
            
            item.SetName(expected2);
            actual = item.GetName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(KindWorksAsExpected)
        {
            RemoteDependencyData item;
            DataPointType expected1 = (DataPointType)12;
            
            item.SetKind(expected1);
            DataPointType actual = item.GetKind();
            Assert::AreEqual(expected1, actual);
            
            DataPointType expected2 = (DataPointType)34;
            
            item.SetKind(expected2);
            actual = item.GetKind();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ValueWorksAsExpected)
        {
            RemoteDependencyData item;
            double expected1 = 3.3765;
            
            item.SetValue(expected1);
            double actual = item.GetValue();
            Assert::AreEqual(expected1, actual);
            
            double expected2 = 8.712;
            
            item.SetValue(expected2);
            actual = item.GetValue();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(CountWorksAsExpected)
        {
            RemoteDependencyData item;
            Nullable<int> expected1(23);
            
            item.SetCount(expected1);
            Nullable<int> actual = item.GetCount();
            Assert::AreEqual(expected1, actual);
            
            Nullable<int> expected2(56);
            
            item.SetCount(expected2);
            actual = item.GetCount();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(MinWorksAsExpected)
        {
            RemoteDependencyData item;
            Nullable<double> expected1(6.5584);
            
            item.SetMin(expected1);
            Nullable<double> actual = item.GetMin();
            Assert::AreEqual(expected1, actual);
            
            Nullable<double> expected2(0.2099);
            
            item.SetMin(expected2);
            actual = item.GetMin();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(MaxWorksAsExpected)
        {
            RemoteDependencyData item;
            Nullable<double> expected1(7.6871);
            
            item.SetMax(expected1);
            Nullable<double> actual = item.GetMax();
            Assert::AreEqual(expected1, actual);
            
            Nullable<double> expected2(6.3751);
            
            item.SetMax(expected2);
            actual = item.GetMax();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(StdDevWorksAsExpected)
        {
            RemoteDependencyData item;
            Nullable<double> expected1(7.2736);
            
            item.SetStdDev(expected1);
            Nullable<double> actual = item.GetStdDev();
            Assert::AreEqual(expected1, actual);
            
            Nullable<double> expected2(6.6978);
            
            item.SetStdDev(expected2);
            actual = item.GetStdDev();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(DependencyKindWorksAsExpected)
        {
            RemoteDependencyData item;
            DependencyKind expected1 = (DependencyKind)20;
            
            item.SetDependencyKind(expected1);
            DependencyKind actual = item.GetDependencyKind();
            Assert::AreEqual(expected1, actual);
            
            DependencyKind expected2 = (DependencyKind)15;
            
            item.SetDependencyKind(expected2);
            actual = item.GetDependencyKind();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SuccessWorksAsExpected)
        {
            RemoteDependencyData item;
            Nullable<bool> expected1(false);
            
            item.SetSuccess(expected1);
            Nullable<bool> actual = item.GetSuccess();
            Assert::AreEqual(expected1, actual);
            
            Nullable<bool> expected2(true);
            
            item.SetSuccess(expected2);
            actual = item.GetSuccess();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(AsyncWorksAsExpected)
        {
            RemoteDependencyData item;
            Nullable<bool> expected1(true);
            
            item.SetAsync(expected1);
            Nullable<bool> actual = item.GetAsync();
            Assert::AreEqual(expected1, actual);
            
            Nullable<bool> expected2(false);
            
            item.SetAsync(expected2);
            actual = item.GetAsync();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(DependencySourceWorksAsExpected)
        {
            RemoteDependencyData item;
            DependencySourceType expected1 = (DependencySourceType)3;
            
            item.SetDependencySource(expected1);
            DependencySourceType actual = item.GetDependencySource();
            Assert::AreEqual(expected1, actual);
            
            DependencySourceType expected2 = (DependencySourceType)71;
            
            item.SetDependencySource(expected2);
            actual = item.GetDependencySource();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(CommandNameWorksAsExpected)
        {
            RemoteDependencyData item;
            std::wstring expected1 = L"gJGoihBr";
            
            item.SetCommandName(expected1);
            std::wstring actual = item.GetCommandName();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"JWPkbPBO";
            
            item.SetCommandName(expected2);
            actual = item.GetCommandName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(DependencyTypeNameWorksAsExpected)
        {
            RemoteDependencyData item;
            std::wstring expected1 = L"BPQCdibF";
            
            item.SetDependencyTypeName(expected1);
            std::wstring actual = item.GetDependencyTypeName();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"GvzfqxyV";
            
            item.SetDependencyTypeName(expected2);
            actual = item.GetDependencyTypeName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(PropertiesWorksAsExpected)
        {
            RemoteDependencyData item;
            std::map<std::wstring, std::wstring> expected1 = { { L"dpeP", L"BBXyWyVy" } };
            
            item.SetProperties(expected1);
            std::map<std::wstring, std::wstring> actual = item.GetProperties();
            Assert::AreEqual(expected1, actual);
            
            std::map<std::wstring, std::wstring> expected2 = { { L"gTPR", L"BBXyWyVy" } };
            
            item.SetProperties(expected2);
            actual = item.GetProperties();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            RemoteDependencyData item;
            int ver = 60;
            std::wstring name = L"ImFOjAtD";
            DataPointType kind = (DataPointType)12;
            double value = 3.3765;
            Nullable<int> count(23);
            Nullable<double> minValue(6.5584);
            Nullable<double> maxValue(7.6871);
            Nullable<double> stdDev(7.2736);
            DependencyKind dependencyKind = (DependencyKind)20;
            Nullable<bool> success(false);
            Nullable<bool> async(true);
            DependencySourceType dependencySource = (DependencySourceType)3;
            std::wstring commandName = L"gJGoihBr";
            std::wstring dependencyTypeName = L"BPQCdibF";
            std::map<std::wstring, std::wstring> properties = { { L"dpeP", L"BBXyWyVy" } };
            
            item.SetVer(ver);
            item.SetName(name);
            item.SetKind(kind);
            item.SetValue(value);
            item.SetCount(count);
            item.SetMin(minValue);
            item.SetMax(maxValue);
            item.SetStdDev(stdDev);
            item.SetDependencyKind(dependencyKind);
            item.SetSuccess(success);
            item.SetAsync(async);
            item.SetDependencySource(dependencySource);
            item.SetCommandName(commandName);
            item.SetDependencyTypeName(dependencyTypeName);
            item.SetProperties(properties);
            
            std::wstring expected = L"{\"ver\":60,\"name\":\"ImFOjAtD\",\"kind\":12,\"value\":3.376500,\"count\":23,\"min\":6.558400,\"max\":7.687100,\"stdDev\":7.273600,\"dependencyKind\":20,\"success\":false,\"async\":true,\"dependencySource\":3,\"commandName\":\"gJGoihBr\",\"dependencyTypeName\":\"BPQCdibF\",\"properties\":{\"dpeP\":\"BBXyWyVy\"}}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
