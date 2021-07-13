/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Stack.hpp
*/

#ifndef ABSTRACTVM_STACK_HPP_
    #define ABSTRACTVM_STACK_HPP_

    #include <vector>

    #include "IOperand.hpp"

    namespace avm {

        int mpush(avm::IOperand *data, std::vector<avm::IOperand *> *OList);
        int massert(avm::IOperand *data, std::vector<avm::IOperand *> *OList);
        int mload(avm::IOperand *data, std::vector<avm::IOperand *> *OList);
        int mstore(avm::IOperand *dest, std::vector<avm::IOperand *> *OList);
        int mpop(std::vector<avm::IOperand *> *OList);
        void mdump(std::vector<avm::IOperand *> *OList);
        int mclear(std::vector<avm::IOperand *> *OList);
        int mdup(std::vector<avm::IOperand *> *OList);
        int mswap(std::vector<avm::IOperand *> *OList);
        int madd(std::vector<avm::IOperand *> *OList);
        int msub(std::vector<avm::IOperand *> *OList);
        int mmul(std::vector<avm::IOperand *> *OList);
        int mdiv(std::vector<avm::IOperand *> *OList);
        int mmod(std::vector<avm::IOperand *> *OList);
        int mprint(std::vector<avm::IOperand *> *OList);

    };

#endif