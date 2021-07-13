/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** double.cpp
*/

#include <string>
#include <limits>
#include <iostream>

#include "IOperand.hpp"
#include "Factory.hpp"
#include "double.hpp"

avm::myDouble::myDouble(const std::string &value)
{
    this->value = &value;
    this->type = avm::eOperandType::DOUBLE;
    this->precision = 15;
}

avm::myDouble::~myDouble()
{
}

avm::IOperand *avm::myDouble::operator+(const IOperand &other) const
{
    std::string result;
    avm::IOperand *newOperand;
    avm::Factory fct;

    int8_t thisValue = static_cast<int8_t>(std::stod(*this->value));
    int8_t otherValue = static_cast<int8_t>(std::stod(other.toString()));
    if ((std::numeric_limits<int8_t>::max() - (std::numeric_limits<int8_t>::min() + std::abs(thisValue))) < std::abs(otherValue)) {
        std::cerr << "myInt8::operator+ error: overflow or underflow\n";
        return (NULL);
    }
    result = std::to_string(thisValue + otherValue);
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

    int8_t thisValue = static_cast<int8_t>(std::stod(*this->value));
    int8_t otherValue = static_cast<int8_t>(std::stod(other.toString()));
    if ((std::numeric_limits<int8_t>::max() - (std::numeric_limits<int8_t>::min() + std::abs(thisValue))) < std::abs(otherValue)) {
        std::cerr << "myInt8::operator+ error: overflow or underflow\n";
        return (NULL);
    }
    result = std::to_string(thisValue - otherValue);
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

    int8_t thisValue = static_cast<int8_t>(std::stod(*this->value));
    int8_t otherValue = static_cast<int8_t>(std::stod(other.toString()));
    if ((std::numeric_limits<int8_t>::max() - (std::numeric_limits<int8_t>::min() + std::abs(thisValue))) < std::abs(otherValue)) {
        std::cerr << "myInt8::operator+ error: overflow or underflow\n";
        return (NULL);
    }
    result = std::to_string(thisValue * otherValue);
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


    int8_t thisValue = static_cast<int8_t>(std::stod(*this->value));
    int8_t otherValue = static_cast<int8_t>(std::stod(other.toString()));
    if ((std::numeric_limits<int8_t>::max() - (std::numeric_limits<int8_t>::min() + std::abs(thisValue))) < std::abs(otherValue)) {
        std::cerr << "myInt8::operator+ error: overflow or underflow\n";
        return (NULL);
    }
    if (otherValue = 0) {
        std::cerr << "myInt8::operator/ error: division by 0\n";
        return (NULL);
    }
    result = std::to_string(thisValue / otherValue);
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

    int8_t thisValue = static_cast<int8_t>(std::stod(*this->value));
    int8_t otherValue = static_cast<int8_t>(std::stod(other.toString()));
    if ((std::numeric_limits<int8_t>::max() - (std::numeric_limits<int8_t>::min() + std::abs(thisValue))) < std::abs(otherValue)) {
        std::cerr << "myInt8::operator+ error: overflow or underflow\n";
        return (NULL);
    }
    if (otherValue = 0) {
        std::cerr << "myInt8::operator\% error: modulo by 0\n";
        return (NULL);
    }
    result = std::to_string(thisValue % otherValue);
    if (this->getType() > other.getType())
        newOperand = fct.createOperand(this->getType(), result);
    else
        newOperand = fct.createOperand(other.getType(), result);
    return (newOperand);
}