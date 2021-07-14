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

avm::IOperand *avm::myInt32::operator+(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    int32_t thisValue = static_cast<int32_t>(std::stod(this->value));
    int32_t otherValue = static_cast<int32_t>(std::stod(other.toString()));
    if (avm::isAddOverflowing(std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::min(), thisValue, otherValue)) {
        std::cerr << "myInt32::operator+ error: overflow or underflow\n";
        return (NULL);
    }
    result = std::to_string(otherValue + thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt32::operator-(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    int32_t thisValue = static_cast<int32_t>(std::stod(this->value));
    int32_t otherValue = static_cast<int32_t>(std::stod(other.toString()));
    if (avm::isSubOverflowing(std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::min(), thisValue, otherValue)) {
        std::cerr << "myint32::operator- error: overflow or underflow\n";
        return (NULL);
    }
    result = std::to_string(otherValue - thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt32::operator*(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    int32_t thisValue = static_cast<int32_t>(std::stod(this->value));
    int32_t otherValue = static_cast<int32_t>(std::stod(other.toString()));
    if (avm::isMulOverflowing(std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::min(), thisValue, otherValue)) {
        std::cerr << "myint32::operator* error: overflow or underflow\n";
        return (NULL);
    }
    result = std::to_string(otherValue * thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt32::operator/(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;


    int32_t thisValue = static_cast<int32_t>(std::stod(this->value));
    int32_t otherValue = static_cast<int32_t>(std::stod(other.toString()));
    if (otherValue == 0) {
        std::cerr << "myint32::operator/ error: division by 0\n";
        return (NULL);
    }
    result = std::to_string(otherValue / thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt32::operator%(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    int32_t thisValue = static_cast<int32_t>(std::stod(this->value));
    int32_t otherValue = static_cast<int32_t>(std::stod(other.toString()));
    if (otherValue == 0) {
        std::cerr << "myint32::operator\% error: modulo by 0\n";
        return (NULL);
    }
    result = std::to_string(otherValue % thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}