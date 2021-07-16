/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_overflow.cpp
*/

#include <limits>
#include <criterion/criterion.h>

#include "Overflow.hpp"

/// ADD

Test(test_overflow, test_add_overflow_int8)
{
    int8_t x = 120;
    int8_t y = 120;
    cr_assert(avm::isAddOverflowing(std::numeric_limits<int8_t>::max(), std::numeric_limits<int8_t>::lowest(), x, y));
}

Test(test_overflow, test_add_overflow_int16)
{
    int16_t x = std::numeric_limits<int16_t>::max() - 30;
    int16_t y = 2000;
    cr_assert(avm::isAddOverflowing(std::numeric_limits<int16_t>::max(), std::numeric_limits<int16_t>::lowest(), x, y));
}

Test(test_overflow, test_add_overflow_int32)
{
    int32_t x = std::numeric_limits<int32_t>::max() - 30;
    int32_t y = 2000;
    cr_assert(avm::isAddOverflowing(std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::lowest(), x, y));
}

Test(test_overflow, test_add_overflow_float)
{
    float x = std::numeric_limits<float>::max() - 30;
    float y = 2000;
    cr_assert(avm::isAddOverflowing(std::numeric_limits<float>::max(), std::numeric_limits<float>::lowest(), x, y));
}

Test(test_overflow, test_add_overflow_double)
{
    double x = std::numeric_limits<double>::max() - 30;
    double y = 2000;
    cr_assert(avm::isAddOverflowing(std::numeric_limits<double>::max(), std::numeric_limits<double>::lowest(), x, y));
}

Test(test_overflow, test_add_overflow_bigdecimal)
{
    long double x = std::numeric_limits<long double>::max() - 30;
    long double y = 2000;
    cr_assert(avm::isAddOverflowing(std::numeric_limits<long double>::max(), std::numeric_limits<long double>::lowest(), x, y));
}

/// SUB

Test(test_overflow, test_sub_overflow_int8)
{
    int8_t x = 120;
    int8_t y = -120;
    cr_assert(avm::isSubOverflowing(std::numeric_limits<int8_t>::max(), std::numeric_limits<int8_t>::lowest(), x, y));
}

Test(test_overflow, test_sub_overflow_int16)
{
    int16_t x = std::numeric_limits<int16_t>::max() - 30;
    int16_t y = -2000;
    cr_assert(avm::isSubOverflowing(std::numeric_limits<int16_t>::max(), std::numeric_limits<int16_t>::lowest(), x, y));
}

Test(test_overflow, test_sub_overflow_int32)
{
    int32_t x = std::numeric_limits<int32_t>::max() - 30;
    int32_t y = -2000;
    cr_assert(avm::isSubOverflowing(std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::lowest(), x, y));
}

Test(test_overflow, test_sub_overflow_float)
{
    float x = std::numeric_limits<float>::max() - 30;
    float y = -2000;
    cr_assert(avm::isSubOverflowing(std::numeric_limits<float>::max(), std::numeric_limits<float>::lowest(), x, y));
}

Test(test_overflow, test_sub_overflow_double)
{
    double x = std::numeric_limits<double>::max() - 30;
    double y = -2000;
    cr_assert(avm::isSubOverflowing(std::numeric_limits<double>::max(), std::numeric_limits<double>::lowest(), x, y));
}

Test(test_overflow, test_sub_overflow_bigdecimal)
{
    long double x = std::numeric_limits<long double>::max() - 30;
    long double y = -2000;
    cr_assert(avm::isSubOverflowing(std::numeric_limits<long double>::max(), std::numeric_limits<long double>::lowest(), x, y));
}

/// MUL

Test(test_overflow, test_mul_overflow_int8)
{
    int8_t x = 120;
    int8_t y = 120;
    cr_assert(avm::isMulOverflowing(std::numeric_limits<int8_t>::max(), std::numeric_limits<int8_t>::lowest(), x, y));
}

Test(test_overflow, test_mul_overflow_int16)
{
    int16_t x = std::numeric_limits<int16_t>::max() - 30;
    int16_t y = 2000;
    cr_assert(avm::isMulOverflowing(std::numeric_limits<int16_t>::max(), std::numeric_limits<int16_t>::lowest(), x, y));
}

Test(test_overflow, test_mul_overflow_int32)
{
    int32_t x = std::numeric_limits<int32_t>::max() - 30;
    int32_t y = 2000;
    cr_assert(avm::isMulOverflowing(std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::lowest(), x, y));
}

Test(test_overflow, test_mul_overflow_float)
{
    float x = std::numeric_limits<float>::max() - 30;
    float y = 2000;
    cr_assert(avm::isMulOverflowing(std::numeric_limits<float>::max(), std::numeric_limits<float>::lowest(), x, y));
}

Test(test_overflow, test_mul_overflow_double)
{
    double x = std::numeric_limits<double>::max() - 30;
    double y = 2000;
    cr_assert(avm::isMulOverflowing(std::numeric_limits<double>::max(), std::numeric_limits<double>::lowest(), x, y));
}

Test(test_overflow, test_mul_overflow_bigdecimal)
{
    long double x = std::numeric_limits<long double>::max() - 30;
    long double y = 2000;
    cr_assert(avm::isMulOverflowing(std::numeric_limits<long double>::max(), std::numeric_limits<long double>::lowest(), x, y));
}