#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/CrashDataBinary.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestCrashDataBinary)
    {
    public:
        
        TEST_METHOD(StartAddressWorksAsExpected)
        {
            CrashDataBinary item;
            std::wstring expected1 = L"LSMWXIIi";
            
            item.SetStartAddress(expected1);
            std::wstring actual = item.GetStartAddress();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"KCIhrOaA";
            
            item.SetStartAddress(expected2);
            actual = item.GetStartAddress();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(EndAddressWorksAsExpected)
        {
            CrashDataBinary item;
            std::wstring expected1 = L"UQolRytI";
            
            item.SetEndAddress(expected1);
            std::wstring actual = item.GetEndAddress();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"xxACdxjI";
            
            item.SetEndAddress(expected2);
            actual = item.GetEndAddress();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(NameWorksAsExpected)
        {
            CrashDataBinary item;
            std::wstring expected1 = L"UywVeait";
            
            item.SetName(expected1);
            std::wstring actual = item.GetName();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"YioFDrYF";
            
            item.SetName(expected2);
            actual = item.GetName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(CpuTypeWorksAsExpected)
        {
            CrashDataBinary item;
            long expected1 = 80;
            
            item.SetCpuType(expected1);
            long actual = item.GetCpuType();
            Assert::AreEqual(expected1, actual);
            
            long expected2 = 87;
            
            item.SetCpuType(expected2);
            actual = item.GetCpuType();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(CpuSubTypeWorksAsExpected)
        {
            CrashDataBinary item;
            long expected1 = 72;
            
            item.SetCpuSubType(expected1);
            long actual = item.GetCpuSubType();
            Assert::AreEqual(expected1, actual);
            
            long expected2 = 76;
            
            item.SetCpuSubType(expected2);
            actual = item.GetCpuSubType();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(UuidWorksAsExpected)
        {
            CrashDataBinary item;
            std::wstring expected1 = L"GfyqHdCd";
            
            item.SetUuid(expected1);
            std::wstring actual = item.GetUuid();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"kjCPtHER";
            
            item.SetUuid(expected2);
            actual = item.GetUuid();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(PathWorksAsExpected)
        {
            CrashDataBinary item;
            std::wstring expected1 = L"XZafbwhW";
            
            item.SetPath(expected1);
            std::wstring actual = item.GetPath();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"XrqgUFKf";
            
            item.SetPath(expected2);
            actual = item.GetPath();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            CrashDataBinary item;
            std::wstring startAddress = L"LSMWXIIi";
            std::wstring endAddress = L"UQolRytI";
            std::wstring name = L"UywVeait";
            long cpuType = 80;
            long cpuSubType = 72;
            std::wstring uuid = L"GfyqHdCd";
            std::wstring path = L"XZafbwhW";
            
            item.SetStartAddress(startAddress);
            item.SetEndAddress(endAddress);
            item.SetName(name);
            item.SetCpuType(cpuType);
            item.SetCpuSubType(cpuSubType);
            item.SetUuid(uuid);
            item.SetPath(path);
            
            std::wstring expected = L"{\"startAddress\":\"LSMWXIIi\",\"endAddress\":\"UQolRytI\",\"name\":\"UywVeait\",\"cpuType\":80.000000,\"cpuSubType\":72.000000,\"uuid\":\"GfyqHdCd\",\"path\":\"XZafbwhW\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
