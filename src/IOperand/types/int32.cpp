/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int32.cpp
*/

#include <string>
#include <iostream>
#include <limits>

#include "Overflow.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"
#include "Stack.hpp"
#include "Exception.hpp"
#include "int32.hpp"

avm::myInt32::myInt32(const std::string &value)
{
    this->value = value;
    this->type = avm::eOperandType::INT32;
    this->precision = 0;
}

avm::myInt32::~myInt32()
{
}

avm::eOperandType avm::myInt32::getType() const
{
    return (avm::eOperandType::INT32);
}

std::string avm::myInt32::toString() const
{
    return (value);
}

unsigned int avm::myInt32::getPrecision() const
{
    return (0);
}

long double avm::myInt32::getMinValue() const
{
    return (std::numeric_limits<int32_t>::lowest());
}

long double avm::myInt32::getMaxValue() const
{
    return (std::numeric_limits<int32_t>::max());
}

avm::IOperand *avm::myInt32::operator+(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::IOperand *tmpOperand;
    avm::Factory fct;
    avm::myException exc;

    int32_t thisValue = static_cast<int32_t>(std::stold(this->value));
    long double otherValue = static_cast<long double>(std::stold(other.toString()));
    if (this->type >= other.getType()) {
        if (isAddOverflowing(std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::lowest(), thisValue, otherValue)) {
            exc.printError("myInt32::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isAddOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("myInt32::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    }
    result = std::to_string(otherValue + thisValue);
    if (this->getType() > other.getType())
        tmpOperand = fct.createOperand(this->getType(), result);
    else
        tmpOperand = fct.createOperand(other.getType(), result);
    newOperand = fct.createOperand(tmpOperand->getType(), avm::checkNumber(tmpOperand->toString(), tmpOperand->getType(), tmpOperand->getPrecision()));
    return (newOperand);
}

avm::IOperand *avm::myInt32::operator-(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::IOperand *tmpOperand;
    avm::Factory fct;
    avm::myException exc;

    int32_t thisValue = static_cast<int32_t>(std::stold(this->value));
    long double otherValue = static_cast<long double>(std::stold(other.toString()));
    if (this->type >= other.getType()) {
        if (isSubOverflowing(std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::lowest(), thisValue, otherValue)) {
            exc.printError("myInt32::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isSubOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("myInt32::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    }
    result = std::to_string(otherValue - thisValue);
    if (this->getType() > other.getType())
        tmpOperand = fct.createOperand(this->getType(), result);
    else
        tmpOperand = fct.createOperand(other.getType(), result);
    newOperand = fct.createOperand(tmpOperand->getType(), avm::checkNumber(tmpOperand->toString(), tmpOperand->getType(), tmpOperand->getPrecision()));
    return (newOperand);
}

avm::IOperand *avm::myInt32::operator*(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::IOperand *tmpOperand;
    avm::Factory fct;
    avm::myException exc;

    int32_t thisValue = static_cast<int32_t>(std::stold(this->value));
    long double otherValue = static_cast<long double>(std::stold(other.toString()));
    if (this->type >= other.getType()) {
        if (isMulOverflowing(std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::lowest(), thisValue, otherValue)) {
            exc.printError("myInt32::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isMulOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("myInt32::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    }
    result = std::to_string(otherValue * thisValue);
    if (this->getType() > other.getType())
        tmpOperand = fct.createOperand(this->getType(), result);
    else
        tmpOperand = fct.createOperand(other.getType(), result);
    newOperand = fct.createOperand(tmpOperand->getType(), avm::checkNumber(tmpOperand->toString(), tmpOperand->getType(), tmpOperand->getPrecision()));
    return (newOperand);
}

avm::IOperand *avm::myInt32::operator/(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::IOperand *tmpOperand;
    avm::Factory fct;
    avm::myException exc;


    int32_t thisValue = static_cast<int32_t>(std::stold(this->value));
    int64_t otherValue = static_cast<int64_t>(std::stold(other.toString()));
    if (thisValue == 0) {
        exc.printError("myint32::operator/ error: division by 0\n");
        return (NULL);
    }
    result = std::to_string(otherValue / thisValue);
    if (this->getType() > other.getType())
        tmpOperand = fct.createOperand(this->getType(), result);
    else
        tmpOperand = fct.createOperand(other.getType(), result);
    newOperand = fct.createOperand(tmpOperand->getType(), avm::checkNumber(tmpOperand->toString(), tmpOperand->getType(), tmpOperand->getPrecision()));
    return (newOperand);
}

avm::IOperand *avm::myInt32::operator%(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::IOperand *tmpOperand;
    avm::Factory fct;
    avm::myException exc;

    int32_t thisValue = static_cast<int32_t>(std::stold(this->value));
    int64_t otherValue = static_cast<int64_t>(std::stold(other.toString()));
    if (thisValue == 0) {
        exc.printError("myint32::operator\% error: modulo by 0\n");
        return (NULL);
    }
    result = std::to_string(otherValue % thisValue);
    if (this->getType() > other.getType())
        tmpOperand = fct.createOperand(this->getType(), result);
    else
        tmpOperand = fct.createOperand(other.getType(), result);
    newOperand = fct.createOperand(tmpOperand->getType(), avm::checkNumber(tmpOperand->toString(), tmpOperand->getType(), tmpOperand->getPrecision()));
    return (newOperand);
}