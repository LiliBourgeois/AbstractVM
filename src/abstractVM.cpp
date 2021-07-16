/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** abstractVM.cpp
*/

#include <vector>
#include <map>
#include <regex>

#include "Registers.hpp"
#include "Stack.hpp"
#include "AbstractVM.hpp"

std::string avm::GetRidOfComment(std::string codeAsm)
{
    size_t semicolonPos = 0;
    size_t endCommentPos = 0;

    while (semicolonPos != std::string::npos) {
        semicolonPos = codeAsm.find_first_of(';', 0);
        endCommentPos = codeAsm.find_first_of('\n', semicolonPos);
        if (semicolonPos != std::string::npos) {
            if (endCommentPos == std::string::npos)
                endCommentPos = codeAsm.find_first_of('\0', semicolonPos);
            codeAsm.erase(semicolonPos, endCommentPos - semicolonPos);
        }
    }
    return codeAsm;
}

std::string GetRidOfTabs(std::string codeAsm)
{
    std::replace(codeAsm.begin(), codeAsm.end(), '\t', ' ');
    return codeAsm;
}

void avm::createRegisters(std::vector<avm::Registers *> &registers)
{
    unsigned int idx = 0;
    while (idx < 16) {
        registers.push_back(new avm::Registers(idx));
        idx = idx + 1;
    }
}

int avm::AbstractVMCore(std::vector<avm::Instruction_t *> &iList)
{
    int (*vpf[])(avm::IOperand *, std::vector<avm::IOperand *> *) = {avm::mpush, avm::massert};
    int (*vrpf[])(avm::IOperand *, std::vector<avm::IOperand *> *, std::vector<avm::Registers *> *) = {avm::mload, avm::mstore};
    int (*pf[])(std::vector<avm::IOperand *> *) = {avm::mpop, avm::mdump, avm::mclear, avm::mdup, avm::mswap, avm::madd, avm::msub, avm::mmul, avm::mdiv, avm::mmod, avm::mprint};
    std::vector<avm::IOperand *> stack;
    std::vector<avm::Registers *> registers;
    int retval;
    unsigned int idx = 0;
    bool running = true;

    createRegisters(registers);
    if (iList.empty())
        return 84;
    while (running) {
        if (iList.at(idx)->i != 16) {
            if (iList.at(idx)->i <= 1) {
                retval = vpf[iList.at(idx)->i](iList.at(idx)->value, &stack);
            } else if (iList.at(idx)->i <=3) {
                retval = vrpf[iList.at(idx)->i - 2](iList.at(idx)->value, &stack, &registers);
            } else
                retval = pf[iList.at(idx)->i - 4](&stack);
            if (retval == 84)
                return 84;
            idx = idx + 1;
            if (iList.at(idx) == iList.back())
                running = false;
        }
    }
    return 0;
}

int avm::AbstractVM(std::string codeAsm)
{
    std::vector<avm::Instruction_t *> iList;
    bool isCodeCorrect = true;

    codeAsm = avm::GetRidOfComment(codeAsm);
    codeAsm = GetRidOfTabs(codeAsm);
    isCodeCorrect = avm::CheckCode(codeAsm);
    if (!isCodeCorrect)
        return 84;
    avm::getTab(codeAsm, iList);
    if (iList.at(0) == NULL)
        return 84;
    return (AbstractVMCore(iList));
}