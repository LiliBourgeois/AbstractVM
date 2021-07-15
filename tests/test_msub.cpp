/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_msub.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Stack.hpp"

Test(test_msub, test_int8_sub)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT8, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT8, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::msub(&stack);

    cr_assert_eq(-1, std::stod(stack.at(0)->toString()));
}

Test(test_msub, test_int16_sub)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT16, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT16, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::msub(&stack);

    cr_assert_eq(-1, std::stod(stack.at(0)->toString()));
}

Test(test_msub, test_int32_sub)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT32, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT32, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::msub(&stack);

    cr_assert_eq(-1, std::stod(stack.at(0)->toString()));
}

Test(test_msub, test_float_sub)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::FLOAT, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::FLOAT, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::msub(&stack);

    cr_assert_eq(-1, std::stod(stack.at(0)->toString()));
}

Test(test_msub, test_double_sub)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::DOUBLE, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::DOUBLE, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::msub(&stack);

    cr_assert_eq(-1, std::stod(stack.at(0)->toString()));
}

Test(test_msub, test_bigdecimal_sub)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::msub(&stack);

    cr_assert_eq(-1, std::stod(stack.at(0)->toString()));
}

Test(test_msub, test_int8_n_sub)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT8, "-4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT8, "-3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::msub(&stack);

    cr_assert_eq(1, std::stod(stack.at(0)->toString()));
}

Test(test_msub, test_int16_n_sub)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT16, "-4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT16, "-3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::msub(&stack);

    cr_assert_eq(1, std::stod(stack.at(0)->toString()));
}

Test(test_msub, test_int32_n_sub)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT32, "-4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT32, "-3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::msub(&stack);

    cr_assert_eq(1, std::stod(stack.at(0)->toString()));
}

Test(test_msub, test_float_n_sub)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::FLOAT, "-4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::FLOAT, "-3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::msub(&stack);

    cr_assert_eq(1, std::stod(stack.at(0)->toString()));
}

Test(test_msub, test_double_n_sub)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::DOUBLE, "-4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::DOUBLE, "-3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::msub(&stack);

    cr_assert_eq(1, std::stod(stack.at(0)->toString()));
}

Test(test_msub, test_bigdecimal_n_sub)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "-4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "-3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::msub(&stack);

    cr_assert_eq(1, std::stod(stack.at(0)->toString()));
}