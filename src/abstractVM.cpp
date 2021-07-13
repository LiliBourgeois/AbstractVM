/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** abstractVM.cpp
*/

#include "AbstractVM.hpp"

std::string getRidOfComment(std::string codeAsm)
{
    size_t semicolonPos = 0;
    size_t endCommentPos = 0;

    while (semicolonPos != std::string::npos) {
        semicolonPos = codeAsm.find_first_of(';', 0);
        endCommentPos = codeAsm.find_first_of('\n', semicolonPos);
        if (semicolonPos != std::string::npos) {
            if (endCommentPos == std::string::npos)
                endCommentPos = codeAsm.find_first_of('\0', semicolonPos);
            codeAsm.erase(semicolonPos, endCommentPos);
        }
    }
    return codeAsm;
}

int avm::AbstractVM(std::string codeAsm)
{
    avm::Instruction_t *instructionsAsm;
    bool isCodeCorrect = CheckCode(codeAsm);

    if (!isCodeCorrect)
        return 84;
    codeAsm = getRidOfComment(codeAsm);
    std::cout << "CODE WITHOUT COMMENT :\n" << codeAsm << "\n";
    std::cout << "avant getTab\n";
    instructionsAsm = getTab(codeAsm);
    std::cout << "après getTab\n";
    while (instructionsAsm->next != NULL) {
        std::cout << instructionsAsm->instruction;
        instructionsAsm = instructionsAsm->next;
    }
    return 0;
}