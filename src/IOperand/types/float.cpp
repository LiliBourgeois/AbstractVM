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

avm::myFloat::myFloat(const std::string &value)
{
    this->value = &value;
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
    return (*value);
}

unsigned int avm::myFloat::getPrecision() const
{
    return (7);
}

avm::IOperand *avm::myFloat::operator+(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    float thisValue = static_cast<float>(std::stod(*this->value));
    float otherValue = static_cast<float>(std::stod(other.toString()));
    if (isAddOverflowing(std::numeric_limits<float>::max(), std::numeric_limits<float>::min(), thisValue, otherValue)) {
        std::cerr << "myFloat::operator+ error: overflow or underflow\n";
        return (NULL);
    }
    result = std::to_string(thisValue + otherValue);
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

    float thisValue = static_cast<float>(std::stod(*this->value));
    float otherValue = static_cast<float>(std::stod(other.toString()));
    if (isSubOverflowing(std::numeric_limits<float>::max(), std::numeric_limits<float>::min(), thisValue, otherValue)) {
        std::cerr << "myFloat::operator- error: overflow or underflow\n";
        return (NULL);
    }
    result = std::to_string(thisValue - otherValue);
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

    float thisValue = static_cast<float>(std::stod(*this->value));
    float otherValue = static_cast<float>(std::stod(other.toString()));
    if (isAddOverflowing(std::numeric_limits<float>::max(), std::numeric_limits<float>::min(), thisValue, otherValue)) {
        std::cerr << "myFloat::operator* error: overflow or underflow\n";
        return (NULL);
    }
    result = std::to_string(thisValue * otherValue);
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


    float thisValue = static_cast<float>(std::stod(*this->value));
    float otherValue = static_cast<float>(std::stod(other.toString()));
    if (otherValue == 0) {
        std::cerr << "myFloat::operator/ error: division by 0\n";
        return (NULL);
    }
    result = std::to_string(thisValue / otherValue);
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

    float thisValue = static_cast<float>(std::stod(*this->value));
    float otherValue = static_cast<float>(std::stod(other.toString()));
    if (otherValue == 0) {
        std::cerr << "myFloat::operator\% error: modulo by 0\n";
        return (NULL);
    }
//    result = std::to_string(thisValue % otherValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}