/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_mmod.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Stack.hpp"

Test(test_mmod, test_int8_mod)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT8, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT8, "10");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mmod(&stack);

    cr_assert_eq(2, std::stod(stack.at(0)->toString()));
}

Test(test_mmod, test_int16_mod)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT16, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT16, "10");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mmod(&stack);

    cr_assert_eq(2, std::stod(stack.at(0)->toString()));
}

Test(test_mmod, test_int32_mod)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT32, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT32, "10");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mmod(&stack);

    cr_assert_eq(2, std::stod(stack.at(0)->toString()));
}

Test(test_mmod, test_bigdecimal_mod)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "10");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mmod(&stack);

    cr_assert_eq(2, std::stod(stack.at(0)->toString()));
}