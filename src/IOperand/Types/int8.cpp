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
    this->type = avm::eOperandType::INT8;
    this->precision = 0;
}

avm::myInt8::~myInt8()
{
}