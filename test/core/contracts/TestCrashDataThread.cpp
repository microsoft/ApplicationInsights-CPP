#include "../targetver.h"
#include "../specializations.h"
#include "CppUnitTest.h"
#include "Contracts/CrashDataThread.h"

using namespace ApplicationInsights::core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace core { namespace tests { namespace contracts
{
    TEST_CLASS(TestCrashDataThread)
    {
    public:
        
        TEST_METHOD(IdWorksAsExpected)
        {
            CrashDataThread item;
            int expected1 = 55;
            
            item.SetId(expected1);
            int actual = item.GetId();
            Assert::AreEqual(expected1, actual);
            
            int expected2 = 82;
            
            item.SetId(expected2);
            actual = item.GetId();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(FramesWorksAsExpected)
        {
            CrashDataThread item;
            std::vector<CrashDataThreadFrame*> expected1 = { };
            
            item.SetFrames(expected1);
            std::vector<CrashDataThreadFrame*> actual = item.GetFrames();
            Assert::AreEqual(expected1, actual);
            
            std::vector<CrashDataThreadFrame*> expected2 = { };
            
            item.SetFrames(expected2);
            actual = item.GetFrames();
            Assert::AreEqual(expected2, actual);
        };
        
        TEST_METHOD(SerializationWorksAsExpected)
        {
            CrashDataThread item;
            int id = 55;
            std::vector<CrashDataThreadFrame*> frames = { };
            
            item.SetId(id);
            item.SetFrames(frames);
            
            std::wstring expected = L"{\"id\":55}";
            
            std::wstring actual;
            StringWriter writer(&actual);
            JsonWriter serializer(writer);
            serializer.WriteObjectValue(&item);
            
            Assert::AreEqual(expected, actual);
        }
    };
}}}
