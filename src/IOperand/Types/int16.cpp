/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int16.cpp
*/

#include "int16.hpp"

avm::myInt16::myInt16(const std::string &value)
{
    this->value = &value;
    this->type = avm::eOperandType::INT16;
    this->precision = 0;
}

avm::myInt16::~myInt16()
{
}