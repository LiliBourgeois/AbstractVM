/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** instructionlist.cpp
*/

#include "AbstractVM.hpp"
#include "IOperand.hpp"
#include "Factory.hpp"
#include <regex>

avm::eInstruction getInstruction(std::smatch i)
{
    const char *strInstruction[] = {"push", "assert", "load", "store", "pop", "dump", "clear", "dup", "swap", "add", "sub", "mul", "div", "mod", "print", "exit"};
    avm::eInstruction enumInstruction = avm::eInstruction::PUSH;
    std::string instruction = i.str();

    while (strInstruction[enumInstruction] != instruction && enumInstruction != 16) {
        enumInstruction = avm::eInstruction(enumInstruction + 1);
    }
    return enumInstruction;
}

avm::eOperandType getType(std::string value)
{
    if(value.find("int8") != std::string::npos) {
        return avm::eOperandType::INT8;
    } else if (value.find("int16") != std::string::npos) {
        return avm::eOperandType::INT16;
    } else if (value.find("int32") != std::string::npos) {
        return avm::eOperandType::INT32;
    } else if (value.find("float") != std::string::npos) {
        return avm::eOperandType::FLOAT;
    } else if (value.find("double") != std::string::npos) {
        return avm::eOperandType::DOUBLE;
    } else if (value.find("bigdecimal") != std::string::npos) {
        return avm::eOperandType::BIGDECIMAL;
    }
    return avm::eOperandType::UNKNOWN;
}

avm::Instruction_t *addNewNode(avm::Instruction_t *list, avm::Instruction_t *newNode)
{
    avm::Instruction_t *tmp = list;


    if (tmp == NULL) {
        list = new (avm::Instruction_t);
        list->instruction = newNode->instruction;
        list->value = newNode->value;
        list->next = NULL;
        list->prev = NULL;
        return list;
    }
    while (tmp != NULL && tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    tmp->next->next = NULL;
    tmp->next->prev = tmp;
    return list;
}

avm::Instruction_t *getTab(std::string codeAsm)
{
    auto f = new avm::Factory;
    avm::Instruction_t *instructionAsm = new(avm::Instruction_t);
    avm::Instruction_t *newInstruction;
    std::smatch tmp;
    avm::eOperandType type;
    std::string value;

    instructionAsm = NULL;
    std::regex word_regex("(\\w+)");
    auto words_begin = std::sregex_iterator(codeAsm.begin(), codeAsm.end(), word_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        newInstruction = new(avm::Instruction_t);
        newInstruction->instruction = getInstruction(*i);
        if (newInstruction->instruction == 16)
            return NULL;
        if (newInstruction->instruction <= 3) {
            ++i;
            tmp = *i;
            type = getType(tmp.str());
            ++i;
            tmp = *i;
            value = tmp.str();
            if (type >= 3 && type <= 5){
                ++i;
                tmp = *i;
                value.append(".");
                value.append(tmp.str());
            }
            newInstruction->value = f->createOperand(type, value);
            std::cout << "value :\n" << newInstruction->value->toString() << "\n";
        }
        instructionAsm = addNewNode(instructionAsm, newInstruction);
        std::cout << "value 2:\n" << instructionAsm->instruction << "\n" << instructionAsm->value->toString() << "\n";
    }
    std::cout << "return \n";
    return instructionAsm;
}
