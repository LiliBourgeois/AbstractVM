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

avm::IOperand *avm::myDouble::operator+(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    double thisValue = std::stod(this->value);
    double otherValue = std::stod(other.toString());
    if (isAddOverflowing(std::numeric_limits<double>::max(), std::numeric_limits<double>::lowest(), thisValue, otherValue)) {
        std::cerr << "myDouble::operator+ error: overflow or underflow\n";
        return (NULL);
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

    double thisValue = std::stod(this->value);
    double otherValue = std::stod(other.toString());
    if (avm::isSubOverflowing(std::numeric_limits<double>::max(), std::numeric_limits<double>::lowest(), thisValue, otherValue)) {
        std::cerr << "myDouble::operator- error: overflow or underflow\n";
        return (NULL);
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

    double thisValue = std::stod(this->value);
    double otherValue = std::stod(other.toString());
    if (avm::isMulOverflowing(std::numeric_limits<double>::max(), std::numeric_limits<double>::lowest(), thisValue, otherValue)) {
        std::cerr << "myDouble::operator* error: overflow or underflow\n";
        return (NULL);
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


    double thisValue = std::stod(this->value);
    double otherValue = std::stod(other.toString());
    if (thisValue == 0) {
        std::cerr << "myDouble::operator/ error: division by 0\n";
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

    double thisValue = std::stod(this->value);
    double otherValue = std::stod(other.toString());
    if (thisValue == 0) {
        std::cerr << "myDouble::operator\% error: modulo by 0\n";
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