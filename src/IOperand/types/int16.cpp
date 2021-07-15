/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int16.cpp
*/

#include <iostream>
#include <limits>
#include <string>

#include "Overflow.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"
#include "Exception.hpp"
#include "int16.hpp"

avm::myInt16::myInt16(const std::string &value)
{
    this->value = value;
    this->type = avm::eOperandType::INT16;
    this->precision = 0;
}

avm::myInt16::~myInt16()
{
}

avm::eOperandType avm::myInt16::getType() const
{
    return (avm::eOperandType::INT16);
}

std::string avm::myInt16::toString() const
{
    return (value);
}

unsigned int avm::myInt16::getPrecision() const
{
    return (0);
}

long double avm::myInt16::getMinValue() const
{
    return (std::numeric_limits<int16_t>::min());
}

long double avm::myInt16::getMaxValue() const
{
    return (std::numeric_limits<int16_t>::max());
}


avm::IOperand *avm::myInt16::operator+(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    int16_t thisValue = static_cast<int16_t>(std::stod(this->value));
    long double otherValue = static_cast<long double>(std::stod(other.toString()));
    if (this->type >= other.getType()) {
        if (isAddOverflowing(std::numeric_limits<int16_t>::max(), std::numeric_limits<int16_t>::min(), thisValue, otherValue)) {
            exc.printError("myInt16::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isAddOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("myInt16::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    }
    result = std::to_string(otherValue + thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt16::operator-(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    int16_t thisValue = static_cast<int16_t>(std::stod(this->value));
    long double otherValue = static_cast<long double>(std::stod(other.toString()));
    if (this->type >= other.getType()) {
        if (isSubOverflowing(std::numeric_limits<int16_t>::max(), std::numeric_limits<int16_t>::min(), thisValue, otherValue)) {
            exc.printError("myInt16::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isSubOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("myInt16::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    }
    result = std::to_string(otherValue - thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt16::operator*(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    int16_t thisValue = static_cast<int16_t>(std::stod(this->value));
    long double otherValue = static_cast<long double>(std::stod(other.toString()));
    if (this->type >= other.getType()) {
        if (isMulOverflowing(std::numeric_limits<int16_t>::max(), std::numeric_limits<int16_t>::min(), thisValue, otherValue)) {
            exc.printError("myInt16::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isMulOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("myInt16::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    }
    result = std::to_string(otherValue * thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt16::operator/(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    int16_t thisValue = static_cast<int16_t>(std::stod(this->value));
    int64_t otherValue = static_cast<int64_t>(std::stod(other.toString()));
    if (thisValue == 0) {
        exc.printError("myInt16::operator/ error: division by 0\n");
        return (NULL);
    }
    result = std::to_string(otherValue / thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt16::operator%(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    int16_t thisValue = static_cast<int16_t>(std::stod(this->value));
    int64_t otherValue = static_cast<int64_t>(std::stod(other.toString()));
    if (thisValue == 0) {
        exc.printError("myInt16::operator\% error: modulo by 0\n");
        return (NULL);
    }
    result = std::to_string(otherValue % thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}