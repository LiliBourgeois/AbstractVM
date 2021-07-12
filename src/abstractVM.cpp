/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** abstractVM.cpp
*/

#include "AbstractVM.hpp"
#include "Operand.hpp"
#include "Factory.hpp"
#include <regex>

avm::eInstruction getInstruction(std::smatch i)
{
    avm::eInstruction enumInstruction = avm::eInstruction::push;
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

avm::eOperandType getValue(std::string value)
{

}

avm::Instruction_t *getTab(std::string codeAsm)
{
    auto f = new avm::Factory;
    avm::Instruction_t *instructionAsm;
    std::smatch tmp;
    avm::eOperandType type;
    std::string value;

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
    }
    return instructionAsm;
}

int avm::AbstractVM(std::string codeAsm)
{
    avm::Instruction_t *instructionsAsm = getTab(codeAsm);

    return 0;
}