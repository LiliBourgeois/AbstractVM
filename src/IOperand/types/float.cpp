/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** float.cpp
*/

#include <string>
#include <iostream>
#include <limits>

#include "Overflow.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"
#include "float.hpp"
#include "Exception.hpp"

avm::myFloat::myFloat(const std::string &value)
{
    this->value = value;
    this->type = avm::eOperandType::FLOAT;
    this->precision = 7;
}

avm::myFloat::~myFloat()
{
}

avm::eOperandType avm::myFloat::getType() const
{
    return (avm::eOperandType::FLOAT);
}

std::string avm::myFloat::toString() const
{
    return (value);
}

unsigned int avm::myFloat::getPrecision() const
{
    return (7);
}

long double avm::myFloat::getMinValue() const
{
    return (std::numeric_limits<float>::lowest());
}

long double avm::myFloat::getMaxValue() const
{
    return (std::numeric_limits<float>::max());
}

avm::IOperand *avm::myFloat::operator+(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    float thisValue = std::stof(this->value);
    long double otherValue = static_cast<long double>(std::stof(other.toString()));
    if (this->type >= other.getType()) {
        if (isAddOverflowing(std::numeric_limits<float>::max(), std::numeric_limits<float>::lowest(), thisValue, otherValue)) {
            exc.printError("float::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isAddOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("float::operator+ error: overflow or underflow\n");
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

avm::IOperand *avm::myFloat::operator-(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    float thisValue = std::stof(this->value);
    long double otherValue = static_cast<long double>(std::stof(other.toString()));
    if (this->type >= other.getType()) {
        if (isSubOverflowing(std::numeric_limits<float>::max(), std::numeric_limits<float>::min(), thisValue, otherValue)) {
            exc.printError("float::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isSubOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("float::operator+ error: overflow or underflow\n");
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

avm::IOperand *avm::myFloat::operator*(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    float thisValue = std::stof(this->value);
    long double otherValue = static_cast<long double>(std::stof(other.toString()));
    if (this->type >= other.getType()) {
        if (isMulOverflowing(std::numeric_limits<float>::max(), std::numeric_limits<float>::min(), thisValue, otherValue)) {
            exc.printError("float::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isMulOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("float::operator+ error: overflow or underflow\n");
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

avm::IOperand *avm::myFloat::operator/(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;


    float thisValue = std::stold(this->value);
    long double otherValue = std::stold(other.toString());
    if (thisValue == 0) {
        exc.printError("myFloat::operator/ error: division by 0\n");
        return (NULL);
    }
    result = std::to_string(otherValue / thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myFloat::operator%(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    float thisValue = std::stof(this->value);
    long double otherValue = std::stof(other.toString());
    if (thisValue == 0) {
        exc.printError("myFloat::operator\% error: modulo by 0\n");
        return (NULL);
    }
    (void)(otherValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    (void)(newOperand);
    return (NULL);
}