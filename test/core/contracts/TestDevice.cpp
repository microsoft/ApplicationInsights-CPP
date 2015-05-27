#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/Device.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestDevice)
    {
    public:
        
        TEST_METHOD(IdWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"ELCIfeDG");
            
            item.SetId(expected1);
            Nullable<std::wstring> actual = item.GetId();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"cOztzrST");
            
            item.SetId(expected2);
            actual = item.GetId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(IpWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"gSDudGFE");
            
            item.SetIp(expected1);
            Nullable<std::wstring> actual = item.GetIp();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"DvNNMWSt");
            
            item.SetIp(expected2);
            actual = item.GetIp();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(LanguageWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"DAOcctKt");
            
            item.SetLanguage(expected1);
            Nullable<std::wstring> actual = item.GetLanguage();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"gFfSyuLC");
            
            item.SetLanguage(expected2);
            actual = item.GetLanguage();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(LocaleWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"aXkpqBWw");
            
            item.SetLocale(expected1);
            Nullable<std::wstring> actual = item.GetLocale();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"CiVQEdxZ");
            
            item.SetLocale(expected2);
            actual = item.GetLocale();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ModelWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"mkBCkkHm");
            
            item.SetModel(expected1);
            Nullable<std::wstring> actual = item.GetModel();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"DxVrFmpS");
            
            item.SetModel(expected2);
            actual = item.GetModel();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(NetworkWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"mtbCXfeJ");
            
            item.SetNetwork(expected1);
            Nullable<std::wstring> actual = item.GetNetwork();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"AZeFzgjC");
            
            item.SetNetwork(expected2);
            actual = item.GetNetwork();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(OemNameWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"EazNnals");
            
            item.SetOemName(expected1);
            Nullable<std::wstring> actual = item.GetOemName();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"cvKMXLfr");
            
            item.SetOemName(expected2);
            actual = item.GetOemName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(OsWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"ENNVCWoH");
            
            item.SetOs(expected1);
            Nullable<std::wstring> actual = item.GetOs();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"ZOAIPSYi");
            
            item.SetOs(expected2);
            actual = item.GetOs();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(OsVersionWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"cQgvEEEr");
            
            item.SetOsVersion(expected1);
            Nullable<std::wstring> actual = item.GetOsVersion();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"EETihAgX");
            
            item.SetOsVersion(expected2);
            actual = item.GetOsVersion();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(RoleInstanceWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"IMksmbAe");
            
            item.SetRoleInstance(expected1);
            Nullable<std::wstring> actual = item.GetRoleInstance();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"FhkDapOE");
            
            item.SetRoleInstance(expected2);
            actual = item.GetRoleInstance();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(RoleNameWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"IHnEdFkb");
            
            item.SetRoleName(expected1);
            Nullable<std::wstring> actual = item.GetRoleName();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"yaHwIDNp");
            
            item.SetRoleName(expected2);
            actual = item.GetRoleName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ScreenResolutionWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"DlhObvwj");
            
            item.SetScreenResolution(expected1);
            Nullable<std::wstring> actual = item.GetScreenResolution();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"NfHTbxfL");
            
            item.SetScreenResolution(expected2);
            actual = item.GetScreenResolution();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(TypeWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"ElWvwXNQ");
            
            item.SetType(expected1);
            Nullable<std::wstring> actual = item.GetType();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"ZPYQpwGr");
            
            item.SetType(expected2);
            actual = item.GetType();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(MachineNameWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> expected1(L"ddilWWPp");
            
            item.SetMachineName(expected1);
            Nullable<std::wstring> actual = item.GetMachineName();
            Assert::AreEqual(expected1, actual);
            
            Nullable<std::wstring> expected2(L"AZkvKPbr");
            
            item.SetMachineName(expected2);
            actual = item.GetMachineName();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            Device item;
            Nullable<std::wstring> id(L"ELCIfeDG");
            Nullable<std::wstring> ip(L"gSDudGFE");
            Nullable<std::wstring> language(L"DAOcctKt");
            Nullable<std::wstring> locale(L"aXkpqBWw");
            Nullable<std::wstring> model(L"mkBCkkHm");
            Nullable<std::wstring> network(L"mtbCXfeJ");
            Nullable<std::wstring> oemName(L"EazNnals");
            Nullable<std::wstring> os(L"ENNVCWoH");
            Nullable<std::wstring> osVersion(L"cQgvEEEr");
            Nullable<std::wstring> roleInstance(L"IMksmbAe");
            Nullable<std::wstring> roleName(L"IHnEdFkb");
            Nullable<std::wstring> screenResolution(L"DlhObvwj");
            Nullable<std::wstring> type(L"ElWvwXNQ");
            Nullable<std::wstring> machineName(L"ddilWWPp");
            
            item.SetId(id);
            item.SetIp(ip);
            item.SetLanguage(language);
            item.SetLocale(locale);
            item.SetModel(model);
            item.SetNetwork(network);
            item.SetOemName(oemName);
            item.SetOs(os);
            item.SetOsVersion(osVersion);
            item.SetRoleInstance(roleInstance);
            item.SetRoleName(roleName);
            item.SetScreenResolution(screenResolution);
            item.SetType(type);
            item.SetMachineName(machineName);
            
            std::wstring expected = L"{\"ai.device.id\":\"ELCIfeDG\",\"ai.device.ip\":\"gSDudGFE\",\"ai.device.language\":\"DAOcctKt\",\"ai.device.locale\":\"aXkpqBWw\",\"ai.device.model\":\"mkBCkkHm\",\"ai.device.network\":\"mtbCXfeJ\",\"ai.device.oemName\":\"EazNnals\",\"ai.device.os\":\"ENNVCWoH\",\"ai.device.osVersion\":\"cQgvEEEr\",\"ai.device.roleInstance\":\"IMksmbAe\",\"ai.device.roleName\":\"IHnEdFkb\",\"ai.device.screenResolution\":\"DlhObvwj\",\"ai.device.type\":\"ElWvwXNQ\",\"ai.device.machineName\":\"ddilWWPp\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
