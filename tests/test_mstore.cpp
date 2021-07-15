/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_mstore.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Stack.hpp"

Test(test_mstore, test_store)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::FLOAT, "0");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "99");
    avm::IOperand *dest = fct.createOperand(avm::eOperandType::BIGDECIMAL, "42");

    avm::mpush(v1, &stack);
    avm::mpush(v2, &stack);

    avm::mstore(dest, &stack);

    cr_assert_eq(0, std::stod(stack.at(0)->toString()));
    cr_assert_eq(avm::eOperandType::FLOAT, stack.at(0)->getType());
    cr_assert_eq(99, std::stod(dest->toString()));
    cr_assert_eq(avm::eOperandType::BIGDECIMAL, dest->getType());
}