#include "targetver.h"
#include "specializations.h"
#include "CppUnitTest.h"
#include "TelemetryContext.h"
#include "Contracts/Contracts.h"

#include <regex>

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef std::wstring wstr;
typedef std::string str;
typedef std::map<std::wstring, std::wstring> map_wstr_wstr;
typedef std::regex re;
#define re_match(input, regex) std::regex_match(input, regex)

namespace core { namespace tests
{
    TEST_CLASS(TestTelemetryContext)
    {
    public:
        
        TEST_METHOD(CtorWorksAsExpected)
        {
			std::wstring iKey = L"MY_KEY";
			TelemetryContext context(iKey);
			context.InitContext();
        };

        TEST_METHOD(UserWorksAsExpected)
        {
			std::wstring iKey = L"MY_KEY";
			TelemetryContext context(iKey);
			context.InitContext();

            User user1 = context.GetUser();

            Assert::IsTrue(user1.GetAccountAcquisitionDate().HasValue());
            Assert::IsFalse(user1.GetAccountId().HasValue());
            Assert::IsFalse(user1.GetUserAgent().HasValue());
            Assert::IsTrue(user1.GetId().HasValue());
            
			re dateMatcher("\\d{4}-\\d{2}-\\d{2}T\\d{2}:\\d{2}:\\d{2}.\\d\\d?\\d?Z");
            wstr date = user1.GetAccountAcquisitionDate().GetValue();
            Assert::IsTrue(re_match(str(date.begin(), date.end()), dateMatcher), L"Invalid regex for date");

            re uuidMatcher("(\\{){0,1}[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}(\\}){0,1}");
            wstr uuid = user1.GetId().GetValue();
            Assert::IsTrue(re_match(str(uuid.begin(), uuid.end()), uuidMatcher), L"Invalid regex for uuid");

#ifdef WIN10_UAP
			TelemetryContext context2(iKey);
			Assert::AreEqual(context.GetUser().GetId().GetValue(), context2.GetUser().GetId().GetValue());
			Assert::AreEqual(context.GetUser().GetAccountAcquisitionDate().GetValue(), context2.GetUser().GetAccountAcquisitionDate().GetValue());
#endif 
			User user2;
			user2.SetAccountAcquisitionDate(Nullable<wstr>(L"bar"));
			context.GetUser() = user2;

			Assert::AreEqual(wstr(L"bar"), context.GetUser().GetAccountAcquisitionDate().GetValue());
        };

        TEST_METHOD(DeviceWorksAsExpected)
        {
			std::wstring iKey = L"MY_KEY";
			TelemetryContext context(iKey);
			context.InitContext();

            Device device1 = context.GetDevice();
#ifdef WIN10_UAP
			Assert::IsTrue(device1.GetId().HasValue());
			Assert::IsFalse(device1.GetIp().HasValue());
			Assert::AreEqual(wstr(L"en-US"), device1.GetLanguage().GetValue());
			Assert::AreEqual(wstr(L"United States"), device1.GetLocale().GetValue());
			Assert::IsFalse(device1.GetModel().HasValue());
			Assert::AreEqual(wstr(L"Ethernet"), device1.GetNetwork().GetValue());
			Assert::IsFalse(device1.GetOemName().HasValue());
			Assert::AreEqual(wstr(L"Windows"), device1.GetOs().GetValue());
			Assert::IsFalse(device1.GetOsVersion().HasValue());
			Assert::IsFalse(device1.GetRoleInstance().HasValue());
			Assert::IsFalse(device1.GetRoleName().HasValue());
			Assert::IsFalse(device1.GetScreenResolution().HasValue());
			Assert::AreEqual(wstr(L"Store"), device1.GetType().GetValue());
			Assert::IsFalse(device1.GetMachineName().HasValue());

#else
            Assert::IsFalse(device1.GetId().HasValue());
            Assert::IsFalse(device1.GetIp().HasValue());
            Assert::IsFalse(device1.GetLanguage().HasValue());
            Assert::IsFalse(device1.GetLocale().HasValue());
            Assert::IsFalse(device1.GetModel().HasValue());
            Assert::IsFalse(device1.GetNetwork().HasValue());
            Assert::IsFalse(device1.GetOemName().HasValue());
			Assert::AreEqual(wstr(L"Windows"), device1.GetOs().GetValue());
            Assert::IsFalse(device1.GetOsVersion().HasValue());
            Assert::IsFalse(device1.GetRoleInstance().HasValue());
            Assert::IsFalse(device1.GetRoleName().HasValue());
            Assert::IsFalse(device1.GetScreenResolution().HasValue());
			Assert::AreEqual(wstr(L"Other"), device1.GetType().GetValue());
            Assert::IsFalse(device1.GetMachineName().HasValue());
#endif
            Device device2;
            device2.SetId(Nullable<wstr>(L"bar"));
            context.GetDevice() = device2;

            Assert::AreEqual(wstr(L"bar"), context.GetDevice().GetId().GetValue());
        };

        TEST_METHOD(ApplicationWorksAsExpected)
        {
			std::wstring iKey = L"MY_KEY";
			TelemetryContext context(iKey);
			context.InitContext();

            Application application1 = context.GetApplication();

#ifdef WIN10_UAP
			Assert::IsTrue(application1.GetVer().HasValue());
#else
            Assert::IsFalse(application1.GetVer().HasValue());
#endif
            Application application2;
            application2.SetVer(Nullable<wstr>(L"bar"));
            context.GetApplication() = application2;

            Assert::AreEqual(wstr(L"bar"), context.GetApplication().GetVer().GetValue());
        };

        TEST_METHOD(SessionAndRenewSessionWorkAsExpected)
        {
			std::wstring iKey = L"MY_KEY";
			TelemetryContext context(iKey);
			context.InitContext();

            Session session1 = context.GetSession();

            Assert::IsTrue(session1.GetId().HasValue());
            Assert::IsTrue(session1.GetIsFirst().HasValue());
            Assert::IsTrue(session1.GetIsNew().HasValue());

            re uuidMatcher("(\\{){0,1}[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}(\\}){0,1}");
            wstr uuid1 = session1.GetId().GetValue();
            Assert::IsTrue(re_match(str(uuid1.begin(), uuid1.end()), uuidMatcher), L"Invalid regex for uuid");

            Assert::AreEqual(wstr(L"True"), context.GetSession().GetIsFirst().GetValue());
            Assert::AreEqual(wstr(L"True"), context.GetSession().GetIsNew().GetValue());
			Sleep(2000);
            context.RenewSession();

            Session session2 = context.GetSession();
            wstr uuid2 = session2.GetId().GetValue();
            Assert::IsTrue(re_match(str(uuid2.begin(), uuid2.end()), uuidMatcher), L"Invalid regex for uuid");
			
            Assert::AreNotEqual(uuid1, uuid2);

            Assert::AreEqual(wstr(L"False"), context.GetSession().GetIsFirst().GetValue());
            Assert::AreEqual(wstr(L"True"), context.GetSession().GetIsNew().GetValue());

            Session session3;
            session3.SetId(Nullable<wstr>(L"bar"));
            context.GetSession() = session3;

            Assert::AreEqual(wstr(L"bar"), context.GetSession().GetId().GetValue());
        };

        TEST_METHOD(GetContextTagsWorksAsExpected)
        {
			std::wstring iKey = L"MY_KEY";
			TelemetryContext context(iKey);
			context.InitContext();

            map_wstr_wstr tags;
            RESULT result = context.GetContextTags(tags);

            Assert::AreEqual(RESULT_OK, result);
#ifdef WIN10_UAP
			Assert::AreEqual(12, (int)tags.size());
#else
			Assert::AreEqual(7, (int)tags.size());
#endif

            re uuidMatcher("(\\{){0,1}[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}(\\}){0,1}");
			re dateMatcher("\\d{4}-\\d{2}-\\d{2}T\\d{2}:\\d{2}:\\d{2}.\\d\\d?\\d?Z");

            int found = 0;
            for (map_wstr_wstr::iterator i = tags.begin(); i != tags.end(); i++)
            {
                wstr key = i->first;
                wstr value = i->second;

                if (key == L"ai.user.id")
                {
                    Assert::IsTrue(re_match(str(value.begin(), value.end()), uuidMatcher), L"Invalid regex for uuid");
                    found |= 1;
                }
                else if (key == L"ai.user.accountAcquisitionDate")
                {
                    Assert::IsTrue(re_match(str(value.begin(), value.end()), dateMatcher), L"Invalid regex for date");
                    found |= 2;
                }
                else if (key == L"ai.session.id")
                {
                    Assert::IsTrue(re_match(str(value.begin(), value.end()), uuidMatcher), L"Invalid regex for uuid");
                    found |= 4;
                }
                else if (key == L"ai.session.isFirst")
                {
                    Assert::AreEqual(wstr(L"True"), value);
                    found |= 8;
                }
                else if (key == L"ai.session.isNew")
                {
                    Assert::AreEqual(wstr(L"True"), value);
                    found |= 16;
                }
				else if (key == L"ai.device.os")
				{
					Assert::AreEqual(wstr(L"Windows"), value);
					found |= 32;
				}
				else if (key == L"ai.device.type")
				{
#ifdef WIN10_UAP
					Assert::AreEqual(wstr(L"Store"), value);
#else
					Assert::AreEqual(wstr(L"Other"), value);
#endif
					found |= 64;
				}
            }

            Assert::AreEqual(127, found, L"Invalid set of default tags");

            context.GetUser() = User();
            context.GetSession() = Session();
			context.GetDevice() = Device();

            result = context.GetContextTags(tags);

            Assert::AreEqual(RESULT_OK, result);
#ifdef WIN10_UAP
            Assert::AreEqual(6, (int)tags.size());
#else
			Assert::AreEqual(0, (int)tags.size());
#endif

            User user;
            user.SetAccountAcquisitionDate(Nullable<wstr>(L"ai.user.accountAcquisitionDate"));
            user.SetAccountId(Nullable<wstr>(L"ai.user.accountId"));
            user.SetUserAgent(Nullable<wstr>(L"ai.user.userAgent"));
            user.SetId(Nullable<wstr>(L"ai.user.id"));

            Device device;
            device.SetId(Nullable<wstr>(L"ai.device.id"));
            device.SetIp(Nullable<wstr>(L"ai.device.ip"));
            device.SetLanguage(Nullable<wstr>(L"ai.device.language"));
            device.SetLocale(Nullable<wstr>(L"ai.device.locale"));
            device.SetModel(Nullable<wstr>(L"ai.device.model"));
            device.SetNetwork(Nullable<wstr>(L"ai.device.network"));
            device.SetOemName(Nullable<wstr>(L"ai.device.oemName"));
            device.SetOs(Nullable<wstr>(L"ai.device.os"));
            device.SetOsVersion(Nullable<wstr>(L"ai.device.osVersion"));
            device.SetRoleInstance(Nullable<wstr>(L"ai.device.roleInstance"));
            device.SetRoleName(Nullable<wstr>(L"ai.device.roleName"));
            device.SetScreenResolution(Nullable<wstr>(L"ai.device.screenResolution"));
            device.SetType(Nullable<wstr>(L"ai.device.type"));
            device.SetMachineName(Nullable<wstr>(L"ai.device.machineName"));

            Application application;
            application.SetVer(Nullable<wstr>(L"ai.application.ver"));

            Session session;
            session.SetId(Nullable<wstr>(L"ai.session.id"));
            session.SetIsFirst(Nullable<wstr>(L"ai.session.isFirst"));
            session.SetIsNew(Nullable<wstr>(L"ai.session.isNew"));

            context.GetUser() = user;
            context.GetDevice() = device;
            context.GetApplication() = application;
            context.GetSession() = session;

            result = context.GetContextTags(tags);

            Assert::AreEqual(RESULT_OK, result);
            Assert::AreEqual(22, (int)tags.size());

            for (map_wstr_wstr::iterator i = tags.begin(); i != tags.end(); i++)
            {
                wstr key = i->first;
                wstr value = i->second;

                Assert::AreEqual(key, value);
            }
        };
    };
}}
