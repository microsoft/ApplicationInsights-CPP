#include "targetver.h"
#include "specializations.h"
#include "CppUnitTest.h"
#include "TelemetryContext.h"
#include "TelemetryClient.h"
#include "Contracts/Contracts.h"
#include "Channel/Utils/HttpResponse.h"
#include <regex>
#include <stdio.h>


#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // phone or store
#include <ppltasks.h>
using namespace concurrency;
#endif
#endif

#include <thread>
#include <chrono>
using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


typedef std::wstring wstr;
typedef std::string str;
typedef std::map<std::wstring, std::wstring> map_wstr_wstr;
typedef std::regex re;
#define re_match(input, regex) std::regex_match(input, regex)

const int ITERATIONS = 2;

namespace core {
	namespace tests
	{
		namespace basicEndToEnd
		{
			class MockTelemetryChannel : public TelemetryChannel
			{
			public:
				MockTelemetryChannel(TelemetryClientConfig config)
					: TelemetryChannel(config)
				{
				}

#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // phone or store
				DWORD WaitForResponse()
				{
					DWORD dwRet = WaitForSingleObjectEx(hRespRecv, 5000, TRUE);

					if (dwRet == (DWORD)WAIT_FAILED)
					{
						LPVOID lpMsgBuf;
						DWORD error = GetLastError();
						FormatMessage(
							FORMAT_MESSAGE_FROM_SYSTEM |
							FORMAT_MESSAGE_IGNORE_INSERTS,
							nullptr,
							error,
							MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
							(LPTSTR)&lpMsgBuf,
							0, nullptr);
						int i = 0;
					}
					return dwRet;
				}
#endif
#endif
				const HttpResponse& GetResponse() const {
					return resp;
				}
			};

			class MockTelemetryClient : public TelemetryClient
			{
			public:
				MockTelemetryClient(std::wstring& iKey) :
					TelemetryClient(iKey)
				{
				}

				void Flush()
				{
					m_channel->Send();
				}

#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // phone or store
				DWORD WaitForResponse() {
					DWORD ret = ((MockTelemetryChannel *)m_channel)->WaitForResponse();
					return ret;
				}
#endif 
#endif
				HttpResponse GetResponse() {
					return ((MockTelemetryChannel *)m_channel)->GetResponse();
				}

			};

			TEST_CLASS(TestBasicEndToEnd)
			{
			public:
				TEST_CLASS_INITIALIZE(Initialize)
				{
#ifdef WINAPI_FAMILY_PARTITION
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)  // Win32, not phone or store
					WORD wVersionRequested;

					WSADATA wsaData;
					int err;

					/* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
					wVersionRequested = MAKEWORD(2, 2);

					err = WSAStartup(wVersionRequested, &wsaData);
#endif 
#endif
				}

				TEST_CLASS_CLEANUP(Cleanup)
				{
#ifdef WINAPI_FAMILY_PARTITION
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)  // Win32, not phone or store
					WSACleanup();
#endif 
#endif
				}

				TEST_METHOD(BasicEndToEnd)
				{
					std::wstring iKey = L"ba0f19ca-aa77-4838-ac05-dbba85d6b677";
					MockTelemetryClient tc = MockTelemetryClient(iKey);

#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // phone or store					
					auto testTask = create_task([&tc]() -> bool {
#endif	
#endif	
						//int iterations = 2;
						//std::wstring iKey = L"ba0f19ca-aa77-4838-ac05-dbba85d6b677";
						//MockTelemetryClient tc = MockTelemetryClient(iKey);

						wchar_t message[100];
						for (int i = 0; i < ITERATIONS; i++)
						{
							swprintf(message, sizeof(message), L"%s %i", L"HELLO EVENT", i);
							tc.TrackEvent(message);

							swprintf(message, sizeof(message), L"%s %i", L"MY METRIC", i);
							tc.TrackMetric(message, 42.5);

							swprintf(message, sizeof(message), L"%s %i", L"PAGE VIEW", i);
							tc.TrackPageView(message);

							swprintf(message, sizeof(message), L"%s %i", L"MY SPECIAL MESSAGE", i);
							tc.TrackTrace(message);
						}
						tc.Flush();

#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // phone or store
						DWORD ret = tc.WaitForResponse();
						return true;
					});

					Sleep(5000);
#endif
#endif
					HttpResponse resp = tc.GetResponse();

					Assert::AreEqual(200, resp.GetErrorCode());

					char strSent[256];
					sprintf_s(strSent, 256, "%d", ITERATIONS * 4);
					std::string payload = resp.GetPayload();
					int recv = payload.find("itemsRecieved");
					int recvBegin = recv + 15;
					int recvEnd = payload.find(",", recvBegin);
					std::string numReceived = str(&payload[recvBegin], &payload[recvEnd]);
					Assert::AreEqual(numReceived, str(strSent));

					int accepted = payload.find("itemsAccepted");
					int acceptedBegin = accepted + 15;
					int acceptedEnd = payload.find(",", acceptedBegin);
					std::string numAccepted = str(&payload[acceptedBegin], &payload[acceptedEnd]);
					Assert::AreEqual(numAccepted, str(strSent));
				};
			};
		}
	}
}
