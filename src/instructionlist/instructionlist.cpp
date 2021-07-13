/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** instructionlist.cpp
*/

#include "AbstractVM.hpp"
#include "Operand.hpp"
#include "Factory.hpp"
#include <regex>

avm::eInstruction getInstruction(std::smatch i)
{
    avm::eInstruction enumInstruction = avm::eInstruction::PUSH;
    std::string instruction = i.str();

    while (avm::strInstruction[enumInstruction] != instruction) {
        enumInstruction = avm::eInstruction(enumInstruction + 1);
    }
    return enumInstruction;
}

avm::eOperandType getType(std::string value)
{
    if(value.find("int8")) {
        return avm::eOperandType::INT8;
    } else if (value.find("int16")) {
        return avm::eOperandType::INT16;
    } else if (value.find("int32")) {
        return avm::eOperandType::INT32;
    } else if (value.find("Float")) {
        return avm::eOperandType::FLOAT;
    } else if (value.find("Double")) {
        return avm::eOperandType::DOUBLE;
    } else if (value.find("BigDecimal")) {
        return avm::eOperandType::BIGDECIMAL;
    }
    return avm::eOperandType::UNKNOWN;
}

std::string getValue(std::string value)
{
    std::string tmp;
    int i = 0;
    int j = 0;

    while(value[i] != '(' && value[i] != '\0' && value[i] != '\n') {
        i += 1;
    }
    while(value[i] != ')' && value[i] != '\0' && value[i] != '\n') {
        tmp[j] = value[i];
        j += 1;
        i += 1;
    }
    return tmp;
}

avm::Instruction_t *setNewNode(avm::Instruction_t *node)
{
    avm::Instruction_t *newNode;

    node->next = newNode;
    newNode->prev = node;
    newNode->next = NULL;
    return newNode;
}

avm::Instruction_t *getTab(std::string codeAsm)
{
    auto f = new avm::Factory;
    avm::Instruction_t *instructionAsm;
    std::smatch tmp;
    avm::eOperandType type;
    std::string value;

    instructionAsm->prev = NULL;
    std::regex word_regex("(\\w+)");
    auto words_begin = std::sregex_iterator(codeAsm.begin(), codeAsm.end(), word_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        instructionAsm->instruction = getInstruction(*i);
        if (instructionAsm->instruction == (0 || 6 || 12 || 13)) {
            ++i;
            tmp = *i;
            type = getType(tmp.str());
            value = getValue(tmp.str());
            instructionAsm->value = f->createOperand(type, value);
        }
        instructionAsm = setNewNode(instructionAsm);
    }
    return instructionAsm;
}
