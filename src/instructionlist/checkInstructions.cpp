/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** checkInstructions.cpp
*/

#include <string>
#include <iostream>
#include <sstream>
#include <string.h>

#include "AbstractVM.hpp"

size_t GetTypeSize(std::string value)
{
    if(value.find("int8") != std::string::npos) {
        return 4;
    } else if (value.find("int16") != std::string::npos) {
        return 5;
    } else if (value.find("int32") != std::string::npos) {
        return 5;
    } else if (value.find("float") != std::string::npos) {
        return 5;
    } else if (value.find("double") != std::string::npos) {
        return 6;
    } else if (value.find("bigdecimal") != std::string::npos) {
        return 10;
    }
    return 0;
}

bool CheckTheNb(std::string line)
{
    double tryConvert;
    size_t i = 0;
    int dotCount = 0;

    while (i < line.length())
    {
        if (line[i] == '.' && dotCount == 0 && i != 0) {
            dotCount += 1;
        } else if (line[i] == '.' && (dotCount != 0 || i == 0)) {
            std::cout << "hello\n";
            return false;
        } else {
            tryConvert = std::stoi(line.substr(0, 1));
            std::cout << "try convert : " << tryConvert << "\n";
            if (tryConvert == 0)
                return false;
            line.erase(0, 1);
        }
    }
    return true;
}

bool CheckSyntacticalError(std::string line, avm::eInstruction enumInstruction, const char *strInstruction[])
{
    size_t instructionSize = strlen(strInstruction[enumInstruction]); //TODO
    size_t typeSize = 0;

    if (enumInstruction > 3) {
        std::cout << "line" << line.length() << "\n";
        std::cout << "instruction" << instructionSize << "\n";
        if (line.length() != instructionSize) {
            std::cout << "ça marche\n";
            return false;
        }
    } else if (0 <= enumInstruction && enumInstruction <= 3) {
        line.erase(0, instructionSize + 1);
        typeSize = GetTypeSize(line);
        if (typeSize == 0) {
           return false;
        }
        line.erase(0, typeSize + 1);
        /*line.pop_back();
        if (CheckTheNb(line) == 0)
            return false;*/
        std::cout << "line = '" << line << "'\n";
    }
    return true;
}

bool FindInstruction(std::string codeAsm, const char *strInstruction[])
{
    avm::eInstruction enumInstruction = avm::eInstruction(0);
    std::istringstream tmp;
    int foundInstruction = 0;

    tmp.str(codeAsm);
    for (std::string line; std::getline(tmp, line); ) {
        while (enumInstruction < 16) {
            std::cout << "line = " << line << "\n";
            if (!line.empty() && line.find(strInstruction[enumInstruction]) != std::string::npos) {
                foundInstruction = 1;
                std::cout << "enuminstruction :" << enumInstruction << "\n";
                std::cout << "instruction :" << strInstruction[enumInstruction] << "\n\n\n\n";
                if (CheckSyntacticalError(line, enumInstruction, strInstruction) == false) {
                    std::cout << "syntactical error\n";
                    return false;
                }
                enumInstruction = avm::eInstruction(18);
            }
            enumInstruction = avm::eInstruction(enumInstruction + 1);
        }
        if (!line.empty() && foundInstruction == 0) {
                return false;
        }
        foundInstruction = 0;
        enumInstruction = avm::eInstruction(0);
    }
    return true;
}

bool avm::CheckCode(std::string codeAsm)
{
    const char *strInstruction[] = {"push", "assert", "load", "store", "pop", "dump", "clear", "dup", "swap", "add", "sub", "mul", "div", "mod", "print", "exit"};

    if (codeAsm.find("exit") == std::string::npos) {
        std::cout << "no exit\n"; //TODO : check tout
        return false;
    }
    if (!FindInstruction(codeAsm, strInstruction))
        return false;
    return true;
}