/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int32.cpp
*/

#include "int32.hpp"

avm::myInt32::myInt32()
{
}

avm::myInt32::~myInt32()
{
}

avm::eOperandType avm::myInt32::getType()
{
    return (avm::eOperandType::int32);
}