/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** abstractVM.cpp
*/

#include "AbstractVM.hpp"

int avm::AbstractVM(std::string codeAsm)
{
    avm::Instruction_t *instructionsAsm;
    std::cout << "avant check code\n";
    bool isCodeCorrect = CheckCode(codeAsm);
    std::cout << "après check code\n";

    if (!isCodeCorrect)
        return 84;
    std::cout << "avant getTab\n";
    instructionsAsm = getTab(codeAsm);
    std::cout << "après getTab\n";
    while (instructionsAsm->next != NULL) {
        std::cout << instructionsAsm->instruction;
        instructionsAsm = instructionsAsm->next;
    }
    return 0;
}