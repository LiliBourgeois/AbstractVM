/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** bigdecimal.cpp
*/

#include "bigdecimal.hpp"

avm::myBigdecimal::myBigdecimal(const std::string &value)
{
    this->value = &value;
    this->type = avm::eOperandType::BigDecimal;
    this->precision = 200;
}

avm::myBigdecimal::~myBigdecimal()
{
}