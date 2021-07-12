/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** Operand.cpp
*/

#include <string>

#include "Operand.hpp"

avm::Operand::Operand()
{
}

avm::Operand::~Operand()
{
}

avm::eOperandType avm::Operand::getType()
{
    return (this->type);
}

unsigned int avm::Operand::getPrecision()
{
    return (this->precision);
}

std::string avm::Operand::toString()
{
    return (*this->value);
}

avm::IOperand *avm::IOperand::operator+(const avm::IOperand &rhs)
{
}