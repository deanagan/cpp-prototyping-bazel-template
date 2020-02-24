#include "Calculator.h"


#include "gtest/gtest.h"
#include "gmock/gmock.h"

class TemplateTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {

    }

};


TEST_F(TemplateTest, ShouldExpect_Total_WhenExecutingCalculatorAdd)
{
    // Arrange
    Template::Calculator calculator;

    // Act
    const auto result = calculator.Add(1,2);

    // Assert
    EXPECT_EQ(3, result);
}

TEST_F(TemplateTest, ShouldExpect_Product_WhenExecutingCalculatorMultiply)
{
    // Arrange
    Template::Calculator calculator;

    // Act
    const auto result = calculator.Multiply(10,2);

    // Assert
    EXPECT_EQ(20, result);
}