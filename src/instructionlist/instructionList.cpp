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

avm::Instruction_t *setNewNode(avm::Instruction_t *node)
{
    avm::Instruction_t *newNode = new(avm::Instruction_t);

    node->next = newNode;
    newNode->prev = node;
    newNode->next = NULL;
    return newNode;
}

avm::Instruction_t *getTab(std::string codeAsm)
{
    auto f = new avm::Factory;
    avm::Instruction_t *instructionAsm = new(avm::Instruction_t);
    std::smatch tmp;
    avm::eOperandType type;
    std::string value;

    instructionAsm->prev = NULL;
    std::regex word_regex("(\\w+)");
    auto words_begin = std::sregex_iterator(codeAsm.begin(), codeAsm.end(), word_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        instructionAsm->instruction = getInstruction(*i);
        if (instructionAsm->instruction == 16)
            return NULL;
        if (instructionAsm->instruction <= 3) {
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
            std::cout << "value :" << value << "\n";
            instructionAsm->value = f->createOperand(type, value);
        }
        instructionAsm = setNewNode(instructionAsm);
    }
    return instructionAsm;
}
