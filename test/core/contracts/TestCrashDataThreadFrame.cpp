#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/CrashDataThreadFrame.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestCrashDataThreadFrame)
    {
    public:
        
        TEST_METHOD(AddressWorksAsExpected)
        {
            CrashDataThreadFrame item;
            std::wstring expected1 = L"FZTIRgix";
            
            item.SetAddress(expected1);
            std::wstring actual = item.GetAddress();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"MYWQuomQ";
            
            item.SetAddress(expected2);
            actual = item.GetAddress();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SymbolWorksAsExpected)
        {
            CrashDataThreadFrame item;
            std::wstring expected1 = L"ZVoZDKeb";
            
            item.SetSymbol(expected1);
            std::wstring actual = item.GetSymbol();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"bjirGekl";
            
            item.SetSymbol(expected2);
            actual = item.GetSymbol();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(RegistersWorksAsExpected)
        {
            CrashDataThreadFrame item;
            std::map<std::wstring, std::wstring> expected1 = { { L"izdG", L"SSuLuTVh" } };
            
            item.SetRegisters(expected1);
            std::map<std::wstring, std::wstring> actual = item.GetRegisters();
            Assert::AreEqual(expected1, actual);
            
            std::map<std::wstring, std::wstring> expected2 = { { L"PFNL", L"SSuLuTVh" } };
            
            item.SetRegisters(expected2);
            actual = item.GetRegisters();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            CrashDataThreadFrame item;
            std::wstring address = L"FZTIRgix";
            std::wstring symbol = L"ZVoZDKeb";
            std::map<std::wstring, std::wstring> registers = { { L"izdG", L"SSuLuTVh" } };
            
            item.SetAddress(address);
            item.SetSymbol(symbol);
            item.SetRegisters(registers);
            
            std::wstring expected = L"{\"address\":\"FZTIRgix\",\"symbol\":\"ZVoZDKeb\",\"registers\":{\"izdG\":\"SSuLuTVh\"}}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
