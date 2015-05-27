#include "targetver.h"
#include "specializations.h"
#include "CppUnitTest.h"
#include "TelemetryClientConfig.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef std::wstring wstr;

namespace core {
    namespace tests
{
    TEST_CLASS(TestTelemetryClientConfig)
    {
    public:
        
        TEST_METHOD(CtorWorksAsExpected)
        {
            wstr expected = L"foo";
            TelemetryClientConfig config(expected);
            Assert::AreEqual(expected, config.GetIKey());
        };

        TEST_METHOD(IKeyWorksAsExpected)
        {
            wstr initial = L"bar";
            TelemetryClientConfig config(initial);
            Assert::AreEqual(initial, config.GetIKey());
            
            wstr expected = L"foo";
            config.SetIKey(expected);

            Assert::AreEqual(expected, config.GetIKey());
        };
    };
}}
