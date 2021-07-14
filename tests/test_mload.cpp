/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_mload.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Stack.hpp"

Test(test_mload, test_load)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *src = fct.createOperand(avm::eOperandType::FLOAT, "0");

    avm::mload(src, &stack);

    cr_assert_eq(0, std::stod(stack.at(0)->toString()));
    cr_assert_eq(avm::eOperandType::FLOAT, stack.at(0)->getType());
}