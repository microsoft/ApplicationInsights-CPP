//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <TelemetryClient.h>
#include <winsock2.h>
using namespace TestApp;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

TelemetryClient *tc;

MainPage::MainPage()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	/* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
	wVersionRequested = MAKEWORD(2, 2);

	err = WSAStartup(wVersionRequested, &wsaData);

	InitializeComponent();
	tc = TelemetryClient::GetInstance(L"ba0f19ca-aa77-4838-ac05-dbba85d6b677");
}

MainPage::~MainPage()
{
	WSACleanup();
}

void TestApp::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	wchar_t message[100];
	for (int i = 0; i < 1; i++)
	{
		swprintf(message, sizeof(message), L"%s %i", L"HELLO EVENT", i);
		tc->TrackEvent(message);

		swprintf(message, sizeof(message), L"%s %i", L"MY METRIC", i);
		tc->TrackMetric(message, 42.5);

		swprintf(message, sizeof(message), L"%s %i", L"PAGE VIEW", i);
		tc->TrackPageView(message);

		swprintf(message, sizeof(message), L"%s %i", L"MY SPECIAL MESSAGE", i);
		tc->TrackTrace(message);
	}
	tc->Flush();

	

}
