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
    
}

avm::IOperand *avm::Factory::createOperand(avm::eOperandType type, const std::string &value)
{
    if (type == avm::eOperandType::int8)
        return (this->createInt8(value));
    if (type == avm::eOperandType::int16)
        return (this->createInt16(value));
    if (type == avm::eOperandType::int32)
        return (this->createInt32(value));
    if (type == avm::eOperandType::Float)
        return (this->createFloat(value));
    if (type == avm::eOperandType::Double)
        return (this->createDouble(value));
    if (type == avm::eOperandType::BigDecimal)
        return (this->createBigDecimal(value));
    return (NULL);
}