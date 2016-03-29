#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/Operation.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestOperation)
    {
    public:
        
        TEST_METHOD(IdWorksAsExpected)
        {
            Operation item;
            Nullable<std::wstring> expected1(L"xgpiibGZ");
            
            item.SetId(expected1);
            Nullable<std::wstring> actual = item.GetId();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"AHBwRDsJ");
            
            item.SetId(expected2);
            actual = item.GetId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(NameWorksAsExpected)
        {
            Operation item;
            Nullable<std::wstring> expected1(L"Azjyxlyr");
            
            item.SetName(expected1);
            Nullable<std::wstring> actual = item.GetName();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"XbRrfAgL");
            
            item.SetName(expected2);
            actual = item.GetName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ParentIdWorksAsExpected)
        {
            Operation item;
            Nullable<std::wstring> expected1(L"suDJVmiw");
            
            item.SetParentId(expected1);
            Nullable<std::wstring> actual = item.GetParentId();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"FPKAsoNX");
            
            item.SetParentId(expected2);
            actual = item.GetParentId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(RootIdWorksAsExpected)
        {
            Operation item;
            Nullable<std::wstring> expected1(L"RYrplEiR");
            
            item.SetRootId(expected1);
            Nullable<std::wstring> actual = item.GetRootId();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"VmwqQBMr");
            
            item.SetRootId(expected2);
            actual = item.GetRootId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SyntheticSourceWorksAsExpected)
        {
            Operation item;
            Nullable<std::wstring> expected1(L"HoeKGdhh");
            
            item.SetSyntheticSource(expected1);
            Nullable<std::wstring> actual = item.GetSyntheticSource();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"nmKPjenu");
            
            item.SetSyntheticSource(expected2);
            actual = item.GetSyntheticSource();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(IsSyntheticWorksAsExpected)
        {
            Operation item;
            Nullable<std::wstring> expected1(L"HGLruVGx");
            
            item.SetIsSynthetic(expected1);
            Nullable<std::wstring> actual = item.GetIsSynthetic();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"cahMPqpw");
            
            item.SetIsSynthetic(expected2);
            actual = item.GetIsSynthetic();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            Operation item;
            Nullable<std::wstring> id(L"xgpiibGZ");
            Nullable<std::wstring> name(L"Azjyxlyr");
            Nullable<std::wstring> parentId(L"suDJVmiw");
            Nullable<std::wstring> rootId(L"RYrplEiR");
            Nullable<std::wstring> syntheticSource(L"HoeKGdhh");
            Nullable<std::wstring> isSynthetic(L"HGLruVGx");
            
            item.SetId(id);
            item.SetName(name);
            item.SetParentId(parentId);
            item.SetRootId(rootId);
            item.SetSyntheticSource(syntheticSource);
            item.SetIsSynthetic(isSynthetic);
            
            std::wstring expected = L"{\"ai.operation.id\":\"xgpiibGZ\",\"ai.operation.name\":\"Azjyxlyr\",\"ai.operation.parentId\":\"suDJVmiw\",\"ai.operation.rootId\":\"RYrplEiR\",\"ai.operation.syntheticSource\":\"HoeKGdhh\",\"ai.operation.isSynthetic\":\"HGLruVGx\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
