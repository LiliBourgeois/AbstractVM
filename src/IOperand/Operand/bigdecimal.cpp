/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** bigdecimal.cpp
*/

#include "bigdecimal.hpp"

avm::myBigdecimal::myBigdecimal()
{
}

avm::myBigdecimal::~myBigdecimal()
{
}

avm::eOperandType avm::myBigdecimal::getType()
{
    return (avm::eOperandType::BigDecimal);
}