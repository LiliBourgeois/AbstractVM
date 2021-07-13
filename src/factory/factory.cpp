/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** factory.cpp
*/

#include <string>

#include "Factory.hpp"
#include "IOperand.hpp"
#include "int8.hpp"
#include "int16.hpp"
#include "int32.hpp"
#include "float.hpp"
#include "double.hpp"
#include "bigdecimal.hpp"

avm::Factory::Factory()
{
}

avm::Factory::~Factory()
{
}

avm::IOperand *avm::Factory::createInt8(const std::string &value)
{
    return (new myInt8(value));
}

avm::IOperand *avm::Factory::createInt16(const std::string &value)
{
    return (new myInt16(value));
}

avm::IOperand *avm::Factory::createInt32(const std::string &value)
{
    return (new myInt32(value));
}

avm::IOperand *avm::Factory::createFloat(const std::string &value)
{
    return (new myFloat(value));
}

avm::IOperand *avm::Factory::createDouble(const std::string &value)
{
    return (new myDouble(value));
}

avm::IOperand *avm::Factory::createBigDecimal(const std::string &value)
{
    return (new myBigdecimal(value));
}

avm::IOperand *avm::Factory::createOperand(avm::eOperandType type, const std::string &value)
{
    if (type == avm::eOperandType::INT8)
        return (this->createInt8(value));
    if (type == avm::eOperandType::INT16)
        return (this->createInt16(value));
    if (type == avm::eOperandType::INT32)
        return (this->createInt32(value));
    if (type == avm::eOperandType::FLOAT)
        return (this->createFloat(value));
    if (type == avm::eOperandType::DOUBLE)
        return (this->createDouble(value));
    if (type == avm::eOperandType::BIGDECIMAL)
        return (this->createBigDecimal(value));
    return (NULL);
}