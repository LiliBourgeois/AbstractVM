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

void avm::getTab(std::string codeAsm, std::vector<avm::Instruction_t *> &iList)
{
    avm::Factory f;
    std::smatch tmp;
    avm::Instruction_t *newInstruction;
    avm::eOperandType type;
    std::string value;

    std::regex word_regex("(\\w+)");
    auto words_begin = std::sregex_iterator(codeAsm.begin(), codeAsm.end(), word_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator idx = words_begin; idx != words_end; ++idx) {
        newInstruction = new(avm::Instruction_t);
        newInstruction->i = getInstruction(*idx);
        if (newInstruction->i == 16)
            return;
        if (newInstruction->i <= 3) {
            ++idx;
            tmp = *idx;
            type = getType(tmp.str());
            ++idx;
            tmp = *idx;
            value = tmp.str();
            if (type >= 3 && type <= 5){
                ++idx;
                tmp = *idx;
                value.append(".");
                value.append(tmp.str());
            }
            newInstruction->value = f.createOperand(type, value);
        }
        iList.push_back(newInstruction);
    }
}
