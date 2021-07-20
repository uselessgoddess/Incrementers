#include <Platform.Incrementers.h>
#include <gtest/gtest.h>

namespace Platform::Incrementers::Tests
{
    TEST(IncrementersTests, ParameterlessConstructedSetterTest)
    {
        auto incrementer = Incrementer<int>();
        ASSERT_EQ({}, incrementer.Result());
    }

    TEST(IncrementersTests, ConstructedWithDefaultValueSetterTest)
    {
        auto incrementer = Incrementer<int>(9UL);
        ASSERT_EQ(9UL, incrementer.Result());
    }

    TEST(IncrementersTests, MethodsWithBooleanReturnTypeTest)
    {
        auto incrementer = Incrementer<int>();
        incrementer.Increment();
        ASSERT_EQ(1UL, incrementer.Result());
        ASSERT_TRUE(incrementer.IncrementAndReturnTrue());
        ASSERT_EQ(2UL, incrementer.Result());
    }

    TEST(IncrementersTests, MethodsWithIntegerReturnTypeTest)
    {
        auto incrementer = Incrementer<int, int>(1);
        incrementer.Increment();
        ASSERT_EQ(1UL, incrementer.Result());
        ASSERT_EQ(1, incrementer.IncrementAndReturnTrue());
        ASSERT_EQ(2UL, incrementer.Result());
    }
}
