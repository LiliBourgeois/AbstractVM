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
#include "Exception.hpp"

int avm::mpop(std::vector<avm::IOperand *> *OList)
{
    avm::myException exc;

    if (OList->size() < 1) {
        exc.printError("'POP' error: list is empty\n");
        return 84;
    }
    OList->erase(OList->begin());
    return 0;
}

int avm::mpush(avm::IOperand *data, std::vector<avm::IOperand *> *OList)
{
    avm::myException exc;

    if (OList->size() >= 16) {
        exc.printError("'PUSH' error: max register is 16");
        return 84;
    }
    OList->insert(OList->begin(), data);
    return 0;
}

int avm::massert(avm::IOperand *data, std::vector<avm::IOperand *> *OList)
{
    avm::myException exc;

    if (OList->size() < 1) {
        exc.printError("'ASSERT' error: no data in stack\n");
        return 84;
    }
    if (OList->at(0)->toString() == data->toString())
        return 0; 
    exc.printError("'ASSERT' error: data doesn't match\n");
    return 84;
}

int avm::mload(avm::IOperand *data, std::vector<avm::IOperand *> *OList)
{
    avm::Factory fct;
    avm::myException exc;
    if (data == NULL || OList->size() >= 16) {
        exc.printError("'LOAD' error: data is null or stack is full\n");
        return 84;
    }
    if (std::stold(data->toString()) >= OList->size()){
        exc.printError("'LOAD' error: unreachable register\n");
        return 84;
    }
    
    avm::mpush(fct.createOperand(OList->at(std::stold(data->toString()))->getType(), OList->at(std::stold(data->toString()))->toString()), OList);
    return 0;
}

int avm::mstore(avm::IOperand *data, std::vector<avm::IOperand *> *OList)
{
    avm::Factory fct;
    avm::myException exc;

    if (data == NULL) {
        exc.printError("'STORE' error: data is null\n");
        return 84;
    }
    if (std::stold(data->toString()) < 0) {
        exc.printError("'STORE' error: negative register index\n");
        return 84;
    }
    if (std::stold(data->toString()) >= OList->size()) {
        exc.printError("'STORE' error: unreachable register\n");
        return 84;
    }
    
    mpop(OList);
    return 0;
}

int avm::madd(std::vector<avm::IOperand *> *OList)
{
    avm::IOperand *newValue;
    avm::myException exc;

    if (OList->size() < 2) {
        exc.printError("'ADD' error: not enough data in the stack\n");
        return 84;
    }
    newValue = OList->at(0)->operator+(*OList->at(1));
    mpop(OList);
    mpop(OList);
    if (newValue == NULL) {
        exc.printError("'ADD' error: operator+ error\n");
        return 84;
    }
    mpush(newValue, OList);
    return 0;
}

int avm::msub(std::vector<avm::IOperand *> *OList)
{
    avm::IOperand *newValue;
    avm::myException exc;

    if (OList->size() < 2) {
        exc.printError("'SUB' error: not enough data in the stack\n");
        return 84;
    }
    newValue = OList->at(0)->operator-(*OList->at(1));
    mpop(OList);
    mpop(OList);
    if (newValue == NULL) {
        exc.printError("'SUB' error: operator+ error\n");
        return 84;
    }
    mpush(newValue, OList);
    return 0;
}

int avm::mmul(std::vector<avm::IOperand *> *OList)
{
    avm::IOperand *newValue;
    avm::myException exc;

    if (OList->size() < 2) {
        exc.printError("'MUL' error: not enough data in the stack\n");
        return 84;
    }
    newValue = OList->at(0)->operator*(*OList->at(1));
    mpop(OList);
    mpop(OList);
    if (newValue == NULL) {
        exc.printError("'MUL' error: operator+ error\n");
        return 84;
    }
    mpush(newValue, OList);
    return 0;
}

int avm::mdiv(std::vector<avm::IOperand *> *OList)
{
    avm::IOperand *newValue;
    avm::myException exc;

    if (OList->size() < 2) {
        exc.printError("'DIV' error: not enough data in the stack\n");
        return 84;
    }
    newValue = OList->at(0)->operator/(*OList->at(1));
    mpop(OList);
    mpop(OList);
    if (newValue == NULL) {
        exc.printError("'DIV' error: operator+ error\n");
        return 84;
    }
    mpush(newValue, OList);
    return 0;
}

int avm::mmod(std::vector<avm::IOperand *> *OList)
{
    avm::IOperand *newValue;
    avm::myException exc;

    if (OList->size() < 2) {
        exc.printError("'MOD' error: not enough data in the stack\n");
        return 84;
    }
    newValue = OList->at(0)->operator%(*OList->at(1));
    mpop(OList);
    mpop(OList);
    if (newValue == NULL) {
        exc.printError("'MOD' error: operator+ error\n");
        return 84;
    }
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
    avm::Factory fct;
    avm::myException exc;

    if (OList->size() >= 16) {
        exc.printError("'DUP' error: stack is full\n");
        return 84;
    }
    OList->insert(OList->begin(), fct.createOperand(OList->at(0)->getType(), OList->at(0)->toString()));
    return 0;
}

int avm::mswap(std::vector<avm::IOperand *> *OList)
{
    avm::myException exc;

    if (OList->size() < 2) {
        exc.printError("'SWAP' error: not enough value on the stack\n");
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
        std::cout << avm::checkNumber(OList->at(idx)->toString(), OList->at(idx)->getType(), OList->at(idx)->getPrecision()) << "\n";
        idx = idx + 1;
    }
    std::cout << avm::checkNumber(OList->at(idx)->toString(), OList->at(idx)->getType(), OList->at(idx)->getPrecision()) << "\n";
    return 0;
}

int avm::mprint(std::vector<avm::IOperand *> *OList)
{
    char c;
    avm::myException exc;

    if (OList->size() < 1) {
        exc.printError("'PRINT' error: not enough data\n");
        return 84;
    }
    if (OList->at(0)->getType() != avm::eOperandType::INT8) {
        exc.printError("'PRINT' error: top data is not a int8\n");
        return 84;
    }
    c = std::stold(OList->at(0)->toString());
    std::cout << c;
    return 0;
}

