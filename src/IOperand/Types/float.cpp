/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** float.cpp
*/

#include "float.hpp"

avm::myFloat::myFloat(const std::string &value)
{
    this->value = &value;
    this->type = avm::eOperandType::FLOAT;
    this->precision = 7;
}

avm::myFloat::~myFloat()
{
}