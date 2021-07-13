/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** checkInstructions.cpp
*/

#include "AbstractVM.hpp"

bool sisgz(std::string codeAsm)
{
    if (codeAsm.find("exit\n"))
        return true;
    return true;
}

bool CheckCode(std::string codeAsm)
{
    static const char *strInstruction[] = {"push", "pop", "dump", "clear", "dup", "swap", "assert", "add", "sub", "mul", "div", "mod", "load", "store", "print", "exit"};


    if (!codeAsm.find("exit\n"))
        return false;
    if (strInstruction)
        return true;
    return true;
}