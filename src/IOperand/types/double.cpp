/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** double.cpp
*/

#include <string>
#include <limits>
#include <iostream>

#include "Overflow.hpp"
#include "IOperand.hpp"
#include "Factory.hpp"
#include "double.hpp"
#include "Exception.hpp"

avm::myDouble::myDouble(const std::string &value)
{
    this->value = value;
    this->type = avm::eOperandType::DOUBLE;
    this->precision = 15;
}

avm::myDouble::~myDouble()
{
}

avm::eOperandType avm::myDouble::getType() const
{
    return (avm::eOperandType::DOUBLE);
}

std::string avm::myDouble::toString() const
{
    return (value);
}

unsigned int avm::myDouble::getPrecision() const
{
    return (15);
}

long double avm::myDouble::getMinValue() const
{
    return (std::numeric_limits<double>::lowest());
}

long double avm::myDouble::getMaxValue() const
{
    return (std::numeric_limits<double>::max());
}

avm::IOperand *avm::myDouble::operator+(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    double thisValue = std::stod(this->value);
    long double otherValue = static_cast<long double>(std::stod(other.toString()));
    if (this->type >= other.getType()) {
        if (isAddOverflowing(std::numeric_limits<double>::max(), std::numeric_limits<double>::lowest(), thisValue, otherValue)) {
            exc.printError("double::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isAddOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("double::operator+ error: overflow or underflow\n");
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

avm::IOperand *avm::myDouble::operator-(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    double thisValue = std::stod(this->value);
    long double otherValue = static_cast<long double>(std::stod(other.toString()));
    if (this->type >= other.getType()) {
        if (isSubOverflowing(std::numeric_limits<double>::max(), std::numeric_limits<double>::min(), thisValue, otherValue)) {
            exc.printError("double::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isSubOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("double::operator+ error: overflow or underflow\n");
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

avm::IOperand *avm::myDouble::operator*(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    double thisValue = std::stod(this->value);
    long double otherValue = std::stod(other.toString());
    if (this->type >= other.getType()) {
        if (isMulOverflowing(std::numeric_limits<double>::max(), std::numeric_limits<double>::min(), thisValue, otherValue)) {
            exc.printError("double::operator+ error: overflow or underflow\n");
            return (NULL);
        }
    } else {
        if (isMulOverflowing(other.getMaxValue(), other.getMinValue(), thisValue, otherValue)) {
            exc.printError("double::operator+ error: overflow or underflow\n");
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

avm::IOperand *avm::myDouble::operator/(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;


    double thisValue = std::stod(this->value);
    long double otherValue = std::stod(other.toString());
    if (thisValue == 0) {
        exc.printError("myDouble::operator/ error: division by 0\n");
        return (NULL);
    }
    result = std::to_string(otherValue / thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myDouble::operator%(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;
    avm::myException exc;

    double thisValue = std::stod(this->value);
    long double otherValue = std::stod(other.toString());
    if (thisValue == 0) {
        exc.printError("myDouble::operator\% error: modulo by 0\n");
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