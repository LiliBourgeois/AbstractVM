/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** registers.cpp
*/

#include "Registers.hpp"

unsigned int avm::Registers::getIdx()
{
    return (this->idx);
}

avm::IOperand *avm::Registers::getData()
{
    return (this->data);
}

bool avm::Registers::isEmpty()
{
    return (this->Empty);
}

void avm::Registers::setData(avm::IOperand *data)
{
    this->Empty = false;
    this->data = data;
}

avm::Registers::Registers(unsigned int idx)
{
    this->Empty = true;
    this->idx = idx;
}

avm::Registers::~Registers()
{
}