/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int8.cpp
*/

#include <iostream>
#include <string>
#include <limits>   

#include "Factory.hpp"
#include "int8.hpp"

avm::myInt8::myInt8(const std::string &value)
{
    this->value = &value;
    this->type = avm::eOperandType::INT8;
    this->precision = 0;
}

avm::myInt8::~myInt8()
{
}

avm::IOperand *avm::myInt8::operator+(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    int8_t thisValue = static_cast<int8_t>(std::stod(*this->value));
    int8_t otherValue = static_cast<int8_t>(std::stod(other.toString()));
    if ((std::numeric_limits<int8_t>::max() - (std::numeric_limits<int8_t>::min() + thisValue)) < otherValue) {
        std::cerr << "myInt8::operator+ error: overflow or underflow\n";
        return (NULL);
    }

    result = std::to_string(thisValue + otherValue);
    newOperand = fct.createOperand(this->getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt8::operator-(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    double thisValue = static_cast<double>(std::stod(*this->value));
    double otherValue = static_cast<double>(std::stod(other.toString()));
    result = std::to_string(thisValue - otherValue);
    newOperand = fct.createOperand(this->getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt8::operator*(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    double thisValue = static_cast<double>(std::stod(*this->value));
    double otherValue = static_cast<double>(std::stod(other.toString()));
    result = std::to_string(thisValue * otherValue);
    newOperand = fct.createOperand(this->getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt8::operator/(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    double thisValue = static_cast<double>(std::stod(*this->value));
    double otherValue = static_cast<double>(std::stod(other.toString()));
    result = std::to_string(thisValue / otherValue);
    newOperand = fct.createOperand(this->getType(), result);
    return (newOperand);
}

avm::IOperand *avm::myInt8::operator%(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    uint64_t thisValue = static_cast<int>(std::stod(*this->value));
    uint64_t otherValue = static_cast<int>(std::stod(other.toString()));
    result = std::to_string(thisValue % otherValue);
    newOperand = fct.createOperand(this->getType(), result);
    return (newOperand);
}