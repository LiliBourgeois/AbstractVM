/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** bigdecimal.cpp
*/

#include <string>
#include <limits>
#include <iostream>
#include "Exception.hpp"
#include "Overflow.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"
#include "bigdecimal.hpp"

avm::myBigdecimal::myBigdecimal(const std::string &value)
{
    this->value = value;
    this->type = avm::eOperandType::BIGDECIMAL;
    this->precision = 200;
}

avm::myBigdecimal::~myBigdecimal()
{
}

avm::eOperandType avm::myBigdecimal::getType() const
{
    return (avm::eOperandType::BIGDECIMAL);
}

std::string avm::myBigdecimal::toString() const
{
    return (value);
}

unsigned int avm::myBigdecimal::getPrecision() const
{
    return (200);
}

long double avm::myBigdecimal::getMinValue() const
{
    return (std::numeric_limits<long double>::lowest());
}

long double avm::myBigdecimal::getMaxValue() const
{
    return (std::numeric_limits<long double>::max());
}

avm::IOperand *avm::myBigdecimal::operator+(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    long double thisValue = static_cast<long double>(std::stod(this->value));
    long double otherValue = static_cast<long double>(std::stod(other.toString()));
    if (this->type >= other.getType()) {
        if (isAddOverflowing(std::numeric_limits<long double>::max(), std::numeric_limits<long double>::lowest(), thisValue, otherValue)) {
            exc.printError("myBigDecimal::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isAddOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("myBigDecimal::operator+ error: overflow or underflow\n");
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

avm::IOperand *avm::myBigdecimal::operator-(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    long double thisValue = static_cast<long double>(std::stod(this->value));
    long double otherValue = static_cast<long double>(std::stod(other.toString()));
    if (this->type >= other.getType()) {
        if (isSubOverflowing(std::numeric_limits<long double>::max(), std::numeric_limits<long double>::min(), thisValue, otherValue)) {
            exc.printError("myBigDecimal::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isSubOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("myBigDecimal::operator+ error: overflow or underflow\n");
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

avm::IOperand *avm::myBigdecimal::operator*(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    long double thisValue = static_cast<long double>(std::stod(this->value));
    long double otherValue = static_cast<long double>(std::stod(other.toString()));
    if (this->type >= other.getType()) {
        if (isMulOverflowing(std::numeric_limits<long double>::max(), std::numeric_limits<long double>::min(), thisValue, otherValue)) {
            exc.printError("myBigDecimal::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isMulOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("myBigDecimal::operator+ error: overflow or underflow\n");
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

avm::IOperand *avm::myBigdecimal::operator/(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;


    long double thisValue = static_cast<long double>(std::stod(this->value));
    long double otherValue = static_cast<long double>(std::stod(other.toString()));
    if (thisValue == 0) {
        exc.printError("myBigDecimal::operator/ error: division by 0\n");
        return (NULL);
    }
    result = std::to_string(otherValue / thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myBigdecimal::operator%(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    int64_t thisValue = static_cast<int64_t>(std::stod(this->value));
    int64_t otherValue = static_cast<int64_t>(std::stod(other.toString()));
    if (thisValue == 0) {
        exc.printError("myBigDecimal::operator\% error: modulo by 0\n");
        return (NULL);
    }
    result = std::to_string(otherValue % thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}