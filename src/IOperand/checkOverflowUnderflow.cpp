/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** checkOverflowUnderflow.cpp
*/

bool isAddOverflowing(long double max, long double min, long double x, long double y)
{
    if ((x > 0) && (y > max - x))
        return true;
    if ((x < 0) && (y < min - x))
        return true;
    return false;
}

bool isSubOverflowing(long double max, long double min, long double x, long double y)
{
    if ((x < 0) && (y > max - x))
        return true;
    if ((x > 0) && (y < min - x))
        return true;
    return false;
}

bool isMulOverflowing(long double max, long double min, long double x, long double y)
{
    if (x == -1 && y == min)
        return true;
    if (y == -1 && x == min)
        return true;
    if (y > max / x)
        return true;
    if (y < min / x)
        return true;
    return false;
}