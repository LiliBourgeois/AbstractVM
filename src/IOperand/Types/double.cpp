/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** double.cpp
*/

#include "double.hpp"

avm::myDouble::myDouble(const std::string &value)
{
    this->value = &value;
    this->type = avm::eOperandType::Double;
    this->precision = 15;
}

avm::myDouble::~myDouble()
{
}