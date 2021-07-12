/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** stack.cpp
*/

#include <iostream>
#include <vector>

#include "IOperand.hpp"

int mpush(avm::IOperand *data, std::vector<avm::IOperand *, avm::IOperand> *OList)
{
    OList->insert(OList->begin(), data);
    return 0;
}

int mpop(std::vector<avm::IOperand *, avm::IOperand> *OList)
{
    if (OList->size() < 1) {
        std::cerr << "'POP' error: list is empty\n";
        return 84;
    }
    OList->erase(OList->begin());
    return 0;
}

int mclear(std::vector<avm::IOperand *, avm::IOperand> *OList)
{
    OList->clear();
    return 0;
}

int mdup(std::vector<avm::IOperand *, avm::IOperand> *OList)
{
    OList->insert(OList->begin(), OList->at(0));
    return 0;
}

int mswap(std::vector<avm::IOperand *, avm::IOperand> *OList)
{
    OList->insert(OList->begin(), OList->at(1));
    OList->swap()
}