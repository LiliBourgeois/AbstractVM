/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** checkZero.cpp
*/

#include "IOperand.hpp"
#include "Stack.hpp"

std::string avm::checkNumber(std::string number, avm::eOperandType numberType, int precision)
{
    int i = 0;
    int countZero = 0;
    int countNb = 0;

    while (number[i] != '\0' && number[i] != '.') {
        if (number[i] == '.' && numberType < 3) {
            return number.erase(i, number.length());
        }
        i += 1;
    }
    if (numberType < 3) {
        return (number);
    }
    while (number[i] != '\0') {
        if (number[i] != '0')
            countZero = 0;
        else if (number[i] == '0')
            countZero += 1;
        countNb += 1;
        i += 1;

    }
    if (countNb > precision) {
        number.erase(i - (countNb - precision), i);
        return number;
    }
    if (countZero != 0) {
        number.erase(i - countZero, i);
        return number;
    }
    return number;
}