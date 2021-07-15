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

avm::eInstruction getInstruction(std::string instruction)
{
    const char *strInstruction[] = {"push", "assert", "load", "store", "pop", "dump", "clear", "dup", "swap", "add", "sub", "mul", "div", "mod", "print", "exit"};
    avm::eInstruction enumInstruction = avm::eInstruction::PUSH;

    while (strInstruction[enumInstruction] != instruction && enumInstruction != 16) {
        enumInstruction = avm::eInstruction(enumInstruction + 1);
    }
    return enumInstruction;
}

avm::eOperandType avm::getType(std::string value)
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

std::string getFirstWord(std::string line)
{
    size_t firstSpace = line.find_first_of(' ');

    if (firstSpace != std::string::npos)
        line.erase(firstSpace);
    std::cout << "line = " << line << "\n";
    return line;
}

std::string getValue(std::string line)
{
    size_t i = 0;

    while (line[i] != '(' &&  i != line.length()) {
        std::cout << "the line = " << line << " i = " << i << "\n";
        i += 1;
    }
    line.erase(0, i + 1);
    line.pop_back();
    std::cout << "nb = " << line << "\n";
    return line;
}

void avm::getTab(std::string codeAsm, std::vector<avm::Instruction_t *> &iList)
{
    std::istringstream tmp;
    avm::eOperandType type;
    std::string value;
    avm::Instruction_t *newInstruction;
    avm::Factory f;

    tmp.str(codeAsm);
    for (std::string line; std::getline(tmp, line); ) {
        if (line.compare("") != 0) {
            value = getFirstWord(line);
            newInstruction = new(avm::Instruction_t);
            newInstruction->i = getInstruction(value);
            type = getType(line);
            if (newInstruction->i <= 3){
                value = getValue(line);
            }
            newInstruction->value = f.createOperand(type, value);
            iList.push_back(newInstruction);
        }
    }
}