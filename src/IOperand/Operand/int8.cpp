/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int8.cpp
*/

#include "int8.hpp"

avm::myInt8::myInt8(const std::string &value)
{
    this->value = &value;
}

avm::myInt8::~myInt8()
{
}

avm::eOperandType avm::myInt8::getType()
{
    return(avm::eOperandType::int8);
}