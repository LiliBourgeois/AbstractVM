/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** abstractVM.cpp
*/

#include "AbstractVM.hpp"
#include "Operand.hpp"
#include <regex>

avm::eInstruction getInstruction(std::sregex_iterator i)
{
    avm::eInstruction enumInstruction = avm::eInstruction::push;
    std::string instruction = (std::string)*i;

    while (avm::strInstruction[enumInstruction] != instruction) {
        enumInstruction = enumInstruction + 1;
    }
    return enumInstruction;
}

avm::eOperandType getType(std::string value)
{
}

avm::Instruction_t *getTab(std::string codeAsm)
{
    avm::Instruction_t *instructionAsm;

    std::regex word_regex("(\\w+)");
    auto words_begin = std::sregex_iterator(codeAsm.begin(), codeAsm.end(), word_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        instructionAsm->instruction = getInstruction(i);
        if (instructionAsm->instruction == (0 || 6 || 12 || 13)) {
            ++i;
            instructionAsm->value = (std::string)*i;
            instructionAsm->type = getTheType(instructionAsm->value);
        }
    }
    return instructionAsm;
}

int avm::AbstractVM(std::string codeAsm)
{
    avm::Instruction_t *instructionsAsm = getTab(codeAsm);

    return 0;
}