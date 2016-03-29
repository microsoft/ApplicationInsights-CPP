#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/ExceptionData.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestExceptionData)
    {
    public:
        
        TEST_METHOD(VerWorksAsExpected)
        {
            ExceptionData item;
            int expected1 = 31;
            
            item.SetVer(expected1);
            int actual = item.GetVer();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 79;
            
            item.SetVer(expected2);
            actual = item.GetVer();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(HandledAtWorksAsExpected)
        {
            ExceptionData item;
            std::wstring expected1 = L"sSskQuoP";
            
            item.SetHandledAt(expected1);
            std::wstring actual = item.GetHandledAt();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"uXQCQxHc";
            
            item.SetHandledAt(expected2);
            actual = item.GetHandledAt();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ExceptionsWorksAsExpected)
        {
            ExceptionData item;
            std::vector<ExceptionDetails*> expected1 = { };
            
            item.SetExceptions(expected1);
            std::vector<ExceptionDetails*> actual = item.GetExceptions();
            Assert::AreEqual(expected1, actual);
            
            std::vector<ExceptionDetails*> expected2 = { };
            
            item.SetExceptions(expected2);
            actual = item.GetExceptions();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SeverityLevelWorksAsExpected)
        {
            ExceptionData item;
            Nullable<SeverityLevel> expected1((SeverityLevel)8);
            
            item.SetSeverityLevel(expected1);
            Nullable<SeverityLevel> actual = item.GetSeverityLevel();
            Assert::AreEqual(expected1, actual);
            
            Nullable<SeverityLevel> expected2((SeverityLevel)67);
            
            item.SetSeverityLevel(expected2);
            actual = item.GetSeverityLevel();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(ProblemIdWorksAsExpected)
        {
            ExceptionData item;
            std::wstring expected1 = L"jPyVAuhF";
            
            item.SetProblemId(expected1);
            std::wstring actual = item.GetProblemId();
            Assert::AreEqual(expected1, actual);
            
            std::wstring expected2 = L"gnqJVAgN";
            
            item.SetProblemId(expected2);
            actual = item.GetProblemId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(CrashThreadIdWorksAsExpected)
        {
            ExceptionData item;
            int expected1 = 82;
            
            item.SetCrashThreadId(expected1);
            int actual = item.GetCrashThreadId();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 35;
            
            item.SetCrashThreadId(expected2);
            actual = item.GetCrashThreadId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(PropertiesWorksAsExpected)
        {
            ExceptionData item;
            std::map<std::wstring, std::wstring> expected1 = { { L"Tcep", L"DaxVFHPr" } };
            
            item.SetProperties(expected1);
            std::map<std::wstring, std::wstring> actual = item.GetProperties();
            Assert::AreEqual(expected1, actual);
            
            std::map<std::wstring, std::wstring> expected2 = { { L"YALu", L"DaxVFHPr" } };
            
            item.SetProperties(expected2);
            actual = item.GetProperties();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(MeasurementsWorksAsExpected)
        {
            ExceptionData item;
            std::map<std::wstring, double> expected1 = { { L"kCvi", 3.3344 } };
            
            item.SetMeasurements(expected1);
            std::map<std::wstring, double> actual = item.GetMeasurements();
            Assert::AreEqual(expected1, actual);
            
            std::map<std::wstring, double> expected2 = { { L"WbRj", 3.3344 } };
            
            item.SetMeasurements(expected2);
            actual = item.GetMeasurements();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            ExceptionData item;
            int ver = 31;
            std::wstring handledAt = L"sSskQuoP";
            std::vector<ExceptionDetails*> exceptions = { };
            Nullable<SeverityLevel> severityLevel((SeverityLevel)8);
            std::wstring problemId = L"jPyVAuhF";
            int crashThreadId = 82;
            std::map<std::wstring, std::wstring> properties = { { L"Tcep", L"DaxVFHPr" } };
            std::map<std::wstring, double> measurements = { { L"kCvi", 3.3344 } };
            
            item.SetVer(ver);
            item.SetHandledAt(handledAt);
            item.SetExceptions(exceptions);
            item.SetSeverityLevel(severityLevel);
            item.SetProblemId(problemId);
            item.SetCrashThreadId(crashThreadId);
            item.SetProperties(properties);
            item.SetMeasurements(measurements);
            
            std::wstring expected = L"{\"ver\":31,\"handledAt\":\"sSskQuoP\",\"exceptions\":[],\"severityLevel\":8,\"problemId\":\"jPyVAuhF\",\"crashThreadId\":82,\"properties\":{\"Tcep\":\"DaxVFHPr\"},\"measurements\":{\"kCvi\":3.334400}}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
