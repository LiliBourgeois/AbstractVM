/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_mmul.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Stack.hpp"

Test(test_mmul, test_int8_mul)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT8, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT8, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mmul(&stack);

    cr_assert_eq(12, std::stold(stack.at(0)->toString()));
}

Test(test_mmul, test_int16_mul)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT16, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT16, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mmul(&stack);

    cr_assert_eq(12, std::stold(stack.at(0)->toString()));
}

Test(test_mmul, test_int32_mul)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT32, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT32, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mmul(&stack);

    cr_assert_eq(12, std::stold(stack.at(0)->toString()));
}

Test(test_mmul, test_float_mul)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::FLOAT, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::FLOAT, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mmul(&stack);

    cr_assert_eq(12, std::stold(stack.at(0)->toString()));
}

Test(test_mmul, test_double_mul)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::DOUBLE, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::DOUBLE, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mmul(&stack);

    cr_assert_eq(12, std::stold(stack.at(0)->toString()));
}

Test(test_mmul, test_bigdecimal_mul)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mmul(&stack);

    cr_assert_eq(12, std::stold(stack.at(0)->toString()));
}