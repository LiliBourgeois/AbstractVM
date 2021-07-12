/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int32.cpp
*/

#include "int32.hpp"

avm::myInt32::myInt32(const std::string &value)
{
    this->value = &value;
    this->type = avm::eOperandType::int32;
    this->precision = 0;
}

avm::myInt32::~myInt32()
{
}