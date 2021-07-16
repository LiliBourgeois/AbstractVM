/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** checkOverflowUnderflow.cpp
*/

#include <iostream>

#include "Overflow.hpp"

bool avm::isAddOverflowing(long double max, long double min, long double x, long double y)
{
    if ((x > 0) && (y > max - x))
        return true;
    if ((x < 0) && (y < min - x)) {
        return true;
    }
    return false;
}

bool avm::isSubOverflowing(long double max, long double min, long double x, long double y)
{
    if ((x < 0) && (y > max - x))
        return true;
    if ((x > 0) && (y < min - x))
        return true;
    return false;
}

bool avm::isMulOverflowing(long double max, long double min, long double x, long double y)
{
    if (x == -1 && y == min) {
        return true;
    } else if (x == -1) {
        return false;
    }
    if (y == -1 && x == min) {
        return true;
    } else if (y == -1) {
        return false;
    }
    if (y > max / x)
        return true;
    if (y < min / x)
        return true;
    return false;
}