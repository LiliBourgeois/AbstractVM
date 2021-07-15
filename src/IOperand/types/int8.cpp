/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int8.cpp
*/

#include <iostream>
#include <string>
#include <limits>   

#include "Overflow.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"
#include "int8.hpp"

avm::myInt8::myInt8(const std::string &value)
{
    this->value = value;
    this->type = avm::eOperandType::INT8;
    this->precision = 0;
}

avm::myInt8::~myInt8()
{
}

avm::eOperandType avm::myInt8::getType() const
{
    return (avm::eOperandType::INT8);
}

std::string avm::myInt8::toString() const
{
    return (value);
}

unsigned int avm::myInt8::getPrecision() const
{
    return (0);
}

avm::IOperand *avm::myInt8::operator+(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    int8_t thisValue = static_cast<int8_t>(std::stod(this->value));
    int8_t otherValue = static_cast<int8_t>(std::stod(other.toString()));
    if (avm::isAddOverflowing(std::numeric_limits<int8_t>::max(), std::numeric_limits<int8_t>::min(), thisValue, otherValue)) {
        std::cerr << "myInt8::operator+ error: overflow or underflow\n";
        return (NULL);
    }
    result = std::to_string(otherValue + thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt8::operator-(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    int8_t thisValue = static_cast<int8_t>(std::stod(this->value));
    int8_t otherValue = static_cast<int8_t>(std::stod(other.toString()));
    if (avm::isSubOverflowing(std::numeric_limits<int8_t>::max(), std::numeric_limits<int8_t>::min(), thisValue, otherValue)) {
        std::cerr << "myInt8::operator- error: overflow or underflow\n";
        return (NULL);
    }
    result = std::to_string(otherValue - thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt8::operator*(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    int8_t thisValue = static_cast<int8_t>(std::stod(this->value));
    int8_t otherValue = static_cast<int8_t>(std::stod(other.toString()));
    if (avm::isMulOverflowing(std::numeric_limits<int8_t>::max(), std::numeric_limits<int8_t>::min(), thisValue, otherValue)) {
        std::cerr << "myInt8::operator* error: overflow or underflow\n";
        return (NULL);
    }
    result = std::to_string(otherValue * thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt8::operator/(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;


    int8_t thisValue = static_cast<int8_t>(std::stod(this->value));
    int8_t otherValue = static_cast<int8_t>(std::stod(other.toString()));
    if (thisValue == 0) {
        std::cerr << "myInt8::operator/ error: division by 0\n";
        return (NULL);
    }
    result = std::to_string(otherValue / thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt8::operator%(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    int8_t thisValue = static_cast<int8_t>(std::stod(this->value));
    int8_t otherValue = static_cast<int8_t>(std::stod(other.toString()));
    if (thisValue == 0) {
        std::cerr << "myInt8::operator\% error: modulo by 0\n";
        return (NULL);
    }
    result = std::to_string(otherValue % thisValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}