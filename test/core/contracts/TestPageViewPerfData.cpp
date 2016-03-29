#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/PageViewPerfData.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestPageViewPerfData)
    {
    public:
        
        TEST_METHOD(PerfTotalWorksAsExpected)
        {
            PageViewPerfData item;
            std::wstring expected1 = L"jItXKRPj";
            
            item.SetPerfTotal(expected1);
            std::wstring actual = item.GetPerfTotal();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"UTJiZJzM";
            
            item.SetPerfTotal(expected2);
            actual = item.GetPerfTotal();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(NetworkConnectWorksAsExpected)
        {
            PageViewPerfData item;
            std::wstring expected1 = L"zkjWxHlP";
            
            item.SetNetworkConnect(expected1);
            std::wstring actual = item.GetNetworkConnect();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"xTSQXzFa";
            
            item.SetNetworkConnect(expected2);
            actual = item.GetNetworkConnect();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SentRequestWorksAsExpected)
        {
            PageViewPerfData item;
            std::wstring expected1 = L"CeetTzfH";
            
            item.SetSentRequest(expected1);
            std::wstring actual = item.GetSentRequest();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"bpEapcOu";
            
            item.SetSentRequest(expected2);
            actual = item.GetSentRequest();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ReceivedResponseWorksAsExpected)
        {
            PageViewPerfData item;
            std::wstring expected1 = L"ZhZDxeDE";
            
            item.SetReceivedResponse(expected1);
            std::wstring actual = item.GetReceivedResponse();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"rssHVaMn";
            
            item.SetReceivedResponse(expected2);
            actual = item.GetReceivedResponse();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(DomProcessingWorksAsExpected)
        {
            PageViewPerfData item;
            std::wstring expected1 = L"GWUjOWso";
            
            item.SetDomProcessing(expected1);
            std::wstring actual = item.GetDomProcessing();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"HgOuCeTT";
            
            item.SetDomProcessing(expected2);
            actual = item.GetDomProcessing();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            PageViewPerfData item;
            int ver = 63;
            std::wstring name = L"FPkYRwor";
            std::map<std::wstring, std::wstring> properties = { { L"fEUK", L"CmlXfTfm" } };
            std::map<std::wstring, double> measurements = { { L"WxIM", 4.509 } };
            std::wstring url = L"nxcKNxAq";
            std::wstring duration = L"WaazkJXv";
            std::wstring perfTotal = L"jItXKRPj";
            std::wstring networkConnect = L"zkjWxHlP";
            std::wstring sentRequest = L"CeetTzfH";
            std::wstring receivedResponse = L"ZhZDxeDE";
            std::wstring domProcessing = L"GWUjOWso";
            
            item.SetVer(ver);
            item.SetName(name);
            item.SetProperties(properties);
            item.SetMeasurements(measurements);
            item.SetUrl(url);
            item.SetDuration(duration);
            item.SetPerfTotal(perfTotal);
            item.SetNetworkConnect(networkConnect);
            item.SetSentRequest(sentRequest);
            item.SetReceivedResponse(receivedResponse);
            item.SetDomProcessing(domProcessing);
            
            std::wstring expected = L"{\"ver\":63,\"name\":\"FPkYRwor\",\"properties\":{\"fEUK\":\"CmlXfTfm\"},\"measurements\":{\"WxIM\":4.509000},\"url\":\"nxcKNxAq\",\"duration\":\"WaazkJXv\",\"perfTotal\":\"jItXKRPj\",\"networkConnect\":\"zkjWxHlP\",\"sentRequest\":\"CeetTzfH\",\"receivedResponse\":\"ZhZDxeDE\",\"domProcessing\":\"GWUjOWso\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
