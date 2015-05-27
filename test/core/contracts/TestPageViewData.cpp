#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/PageViewData.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestPageViewData)
    {
    public:
        
        TEST_METHOD(UrlWorksAsExpected)
        {
            PageViewData item;
            std::wstring expected1 = L"nxcKNxAq";
            
            item.SetUrl(expected1);
            std::wstring actual = item.GetUrl();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"bjKAYrGi";
            
            item.SetUrl(expected2);
            actual = item.GetUrl();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(DurationWorksAsExpected)
        {
            PageViewData item;
            std::wstring expected1 = L"WaazkJXv";
            
            item.SetDuration(expected1);
            std::wstring actual = item.GetDuration();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"NjcZUfcw";
            
            item.SetDuration(expected2);
            actual = item.GetDuration();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            PageViewData item;
            int ver = 63;
            std::wstring name = L"FPkYRwor";
            std::map<std::wstring, std::wstring> properties = { { L"fEUK", L"CmlXfTfm" } };
            std::map<std::wstring, double> measurements = { { L"WxIM", 4.509 } };
            std::wstring url = L"nxcKNxAq";
            std::wstring duration = L"WaazkJXv";
            
            item.SetVer(ver);
            item.SetName(name);
            item.SetProperties(properties);
            item.SetMeasurements(measurements);
            item.SetUrl(url);
            item.SetDuration(duration);
            
            std::wstring expected = L"{\"ver\":63,\"name\":\"FPkYRwor\",\"properties\":{\"fEUK\":\"CmlXfTfm\"},\"measurements\":{\"WxIM\":4.509000},\"url\":\"nxcKNxAq\",\"duration\":\"WaazkJXv\"}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
