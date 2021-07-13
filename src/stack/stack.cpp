/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** stack.cpp
*/

#include <iostream>
#include <vector>

#include "Factory.hpp"
#include "IOperand.hpp"

int mpush(avm::IOperand *data, std::vector<avm::IOperand *> *OList)
{
    OList->insert(OList->begin(), data);
    return 0;
}

int massert(avm::IOperand *data, std::vector<avm::IOperand *> *OList)
{
    if (OList->size() < 1)
        return 84;
    if (OList->at(0)->toString() == data->toString())
        return 0; 
    std::cerr << "'ASSERT' error: data doesn't match\n";
    return 84;
}

int mload(avm::IOperand *data, std::vector<avm::IOperand *> *OList)
{
    avm::Factory fct;
    avm::IOperand *newValue;

    if (data == NULL)
        return 84;
    if (data->toString().empty())
        return 84;
    newValue = fct.createOperand(data->getType(), data->toString());
    if (newValue == NULL)
        return 84;
    mpush(newValue, OList);
    return 0;
}

int mstore(avm::IOperand *dest, std::vector<avm::IOperand *> *OList)
{
    avm::Factory fct;

    dest = fct.createOperand(OList->at(0)->getType(), OList->at(0)->toString());
    if (dest == NULL)
        return 84;
    if (mpop(OList) == 84)
        return 84;
    return 0;
}

int madd(std::vector<avm::IOperand *> *OList)
{
    avm::IOperand *newValue;

    if (OList->size() < 2)
        return 84;
    newValue = OList->at(0)->operator+(*OList->at(1));
    mpop(OList);
    mpop(OList);
    if (newValue == NULL)
        return 84;
    mpush(newValue, OList);
    return 0;
}

int msub(std::vector<avm::IOperand *> *OList)
{
    avm::IOperand *newValue;

    if (OList->size() < 2)
        return 84;
    newValue = OList->at(0)->operator-(*OList->at(1));
    mpop(OList);
    mpop(OList);
    if (newValue == NULL)
        return 84;
    mpush(newValue, OList);
    return 0;
}

int mmul(std::vector<avm::IOperand *> *OList)
{
    avm::IOperand *newValue;

    if (OList->size() < 2)
        return 84;
    newValue = OList->at(0)->operator*(*OList->at(1));
    mpop(OList);
    mpop(OList);
    if (newValue == NULL)
        return 84;
    mpush(newValue, OList);
    return 0;
}

int mdiv(std::vector<avm::IOperand *> *OList)
{
    avm::IOperand *newValue;

    if (OList->size() < 2)
        return 84;
    newValue = OList->at(0)->operator/(*OList->at(1));
    mpop(OList);
    mpop(OList);
    if (newValue == NULL)
        return 84;
    mpush(newValue, OList);
    return 0;
}

int mmod(std::vector<avm::IOperand *> *OList)
{
    avm::IOperand *newValue;

    if (OList->size() < 2)
        return 84;
    newValue = OList->at(0)->operator%(*OList->at(1));
    mpop(OList);
    mpop(OList);
    if (newValue == NULL)
        return 84;
    mpush(newValue, OList);
    return 0;
}

int mpop(std::vector<avm::IOperand *> *OList)
{
    if (OList->size() < 1) {
        std::cerr << "'POP' error: list is empty\n";
        return 84;
    }
    OList->erase(OList->begin());
    return 0;
}

int mclear(std::vector<avm::IOperand *> *OList)
{
    OList->clear();
    return 0;
}

int mdup(std::vector<avm::IOperand *> *OList)
{
    if (OList->size() < 1) {
        std::cerr << "'DUP' error: list is empty\n";
        return 84;
    }
    OList->insert(OList->begin(), OList->at(0));
    return 0;
}

int mswap(std::vector<avm::IOperand *> *OList)
{
    if (OList->size() < 2) {
        std::cerr << "'SWAP' error: not enough value on the stack\n";
        return 84;
    }
    OList->insert(OList->begin(), OList->at(1));
    OList->erase(OList->begin() + 2);
    return 0;
}

void mdump(std::vector<avm::IOperand *> *OList)
{
    unsigned int idx = 0;

    if (OList->size() <= 0)
        return;
    while (OList->at(OList->size() - 1) != OList->at(idx)) {
        std::cout << OList->at(idx)->toString() << "\n";
        idx = idx + 1;
    }
    std::cout << OList->at(idx)->toString() << "\n";
}

void msdump(std::vector<avm::IOperand *> *OList)
{
    unsigned int idx = 0;
    if (OList->size() <= 0)
        return;
    while (OList->at(OList->size() - 1) != OList->at(idx)) {
        std::cout << OList->at(idx)->toString() << " | " << OList->at(idx)->getType() << "\n";
        idx = idx + 1;
    }
    std::cout << OList->at(idx) << "\n";
}

int mprint(std::vector<avm::IOperand *> *OList)
{
    char c;

    if (OList->size() < 1)
        return 84;
    if (OList->at(0)->getType() != avm::eOperandType::INT8)
        return 84;
    c = std::stod(OList->at(0)->toString());
    std::cout << c;
    return 0;
}