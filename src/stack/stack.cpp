/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** stack.cpp
*/

#include <iostream>
#include <vector>

#include "Stack.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"

int avm::mpop(std::vector<avm::IOperand *> *OList)
{
    if (OList->size() < 1) {
        std::cerr << "'POP' error: list is empty\n";
        return 84;
    }
    OList->erase(OList->begin());
    return 0;
}

int avm::mpush(avm::IOperand *data, std::vector<avm::IOperand *> *OList)
{
    OList->insert(OList->begin(), data);
    return 0;
}

int avm::massert(avm::IOperand *data, std::vector<avm::IOperand *> *OList)
{
    if (OList->size() < 1)
        return 84;
    if (OList->at(0)->toString() == data->toString())
        return 0; 
    std::cerr << "'ASSERT' error: data doesn't match\n";
    return 84;
}

int avm::mload(avm::IOperand *data, std::vector<avm::IOperand *> *OList)
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

int avm::mstore(avm::IOperand *dest, std::vector<avm::IOperand *> *OList)
{
    avm::Factory fct;

    if (dest == NULL)
        return 84;
    dest->setValue(OList->at(0)->toString());
    if (mpop(OList) == 84)
        return 84;
    return 0;
}

int avm::madd(std::vector<avm::IOperand *> *OList)
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

int avm::msub(std::vector<avm::IOperand *> *OList)
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

int avm::mmul(std::vector<avm::IOperand *> *OList)
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

int avm::mdiv(std::vector<avm::IOperand *> *OList)
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

int avm::mmod(std::vector<avm::IOperand *> *OList)
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

int avm::mclear(std::vector<avm::IOperand *> *OList)
{
    OList->clear();
    return 0;
}

int avm::mdup(std::vector<avm::IOperand *> *OList)
{
    OList->insert(OList->begin(), OList->at(0));
    return 0;
}

int avm::mswap(std::vector<avm::IOperand *> *OList)
{
    if (OList->size() < 2) {
        std::cerr << "'SWAP' error: not enough value on the stack\n";
        return 84;
    }
    OList->insert(OList->begin(), OList->at(1));
    OList->erase(OList->begin() + 2);
    return 0;
}

int avm::mdump(std::vector<avm::IOperand *> *OList)
{
    unsigned int idx = 0;

    if (OList->size() <= 0)
        return 0;
    while (OList->at(OList->size() - 1) != OList->at(idx)) {
        std::cout << avm::checkNumber(OList->at(idx)->toString(), OList->at(idx)->getType(), OList->at(idx)->getPrecision()) << "\n"; //<< "mdump in while\n";
        idx = idx + 1;
    }
    std::cout << avm::checkNumber(OList->at(idx)->toString(), OList->at(idx)->getType(), OList->at(idx)->getPrecision()) << "\n"; //<< "mdump\n";
    return 0;
}

int msdump(std::vector<avm::IOperand *> *OList)
{
    unsigned int idx = 0;
    if (OList->size() <= 0)
        return 0;
    while (OList->at(OList->size() - 1) != OList->at(idx)) {
        std::cout << avm::checkNumber(OList->at(idx)->toString(), OList->at(idx)->getType(), OList->at(idx)->getPrecision()) << " | " << OList->at(idx)->getType() << "\n"; //<< "msdump in while\n";
        idx = idx + 1;
    }
    std::cout << avm::checkNumber(OList->at(idx)->toString(), OList->at(idx)->getType(), OList->at(idx)->getPrecision()) << "\n"; // << "msdump\n";
    return 0;
}

int avm::mprint(std::vector<avm::IOperand *> *OList)
{
    char c;

    if (OList->size() < 1)
        return 84;
    if (OList->at(0)->getType() != avm::eOperandType::INT8)
        return 84;
    c = std::stod(avm::checkNumber(OList->at(0)->toString(), OList->at(0)->getType(), OList->at(0)->getPrecision()));
    std::cout << c; // << "mprint\n";
    return 0;
}

