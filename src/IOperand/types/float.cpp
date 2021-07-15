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

void avm::myFloat::setValue(const std::string &value)
{
    this->value = value;
}

avm::IOperand *avm::myFloat::operator+(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    float thisValue = std::stof(this->value);
    float otherValue = std::stof(other.toString());
    if (avm::isAddOverflowing(std::numeric_limits<float>::max(), std::numeric_limits<float>::lowest(), thisValue, otherValue)) {
        std::cerr << "myFloat::operator+ error: overflow or underflow\n";
        return (NULL);
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

    float thisValue = std::stof(this->value);
    float otherValue = std::stof(other.toString());
    if (avm::isSubOverflowing(std::numeric_limits<float>::max(), std::numeric_limits<float>::lowest(), thisValue, otherValue)) {
        std::cerr << "myFloat::operator- error: overflow or underflow\n";
        return (NULL);
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

    float thisValue = std::stof(this->value);
    float otherValue = std::stof(other.toString());
    if (avm::isMulOverflowing(std::numeric_limits<float>::max(), std::numeric_limits<float>::lowest(), thisValue, otherValue)) {
        std::cerr << "myFloat::operator* error: overflow or underflow\n";
        return (NULL);
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


    float thisValue = std::stod(this->value);
    float otherValue = std::stod(other.toString());
    if (thisValue == 0) {
        std::cerr << "myFloat::operator/ error: division by 0\n";
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

    float thisValue = std::stof(this->value);
    float otherValue = std::stof(other.toString());
    if (thisValue == 0) {
        std::cerr << "myFloat::operator\% error: modulo by 0\n";
        return (NULL);
    }
    (void)(otherValue);//TODO
//    result = std::to_string(otherValue % thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}