/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_checkcode.cpp
*/

#include <criterion/criterion.h>

#include "AbstractVM.hpp"

Test(test_checkcode, test_legal_code_all_opp)
{
    std::string code = ";;;;;;;;;;;;;;\n;header\n;this is a file\n;;;;;;;;;;;;;;\npush int8(78)\npush int16(300)\nadd\ndump\t;should be 378\npush int16(90)\nsub\ndump\t;should be 288\npush int8(-1)\nmul\ndump\t;should be -288\npush int8(2)\ndiv\ndump\t;should be -144\npush int8(5)\nmod\ndump\t;should be -4\nexit";
    cr_assert(avm::CheckCode(avm::GetRidOfComment(code)));
}

Test(test_checkcode, test_legal_code_all_types)
{
    std::string code = "push int8(8)\npush int16(16)\npush int32(32)\npush float(64.64)\npush double(128.128)\npush bigdecimal(256.256)\nexit\n";
    cr_assert(avm::CheckCode(code));
}

Test(test_checkcode, test_legal_code_all_registers)
{
    std::string code = "push int8(8)\npush int16(16)\nstore int8(1)\nload int8(0)\nexit";
    cr_assert(avm::CheckCode(code));
}

Test(test_checkcode, test_legal_code_all_other_cmd)
{
    std::string code = "push int8(8)\npush int16(16)\nswap\npop\ndup\nclear\npush bigdecimal(0.0056)\nassert bigdecimal(0.0056)\ndump\n\n\n\nexit";
    cr_assert(avm::CheckCode(code));
}

Test(test_checkcode, test_illegal_code_no_exit)
{
    std::string code = "push int8(8)\npush bigdecimal(256.256)";
    cr_assert(!avm::CheckCode(code));
}

Test(test_checkcode, test_illegal_code_missing_arg)
{
    std::string code = "push\nexit";
    cr_assert(!avm::CheckCode(code));
}

Test(test_checkcode, test_illegal_code_arg_not_used)
{
    std::string code = "dup int8(9)\nexit";
    cr_assert(!avm::CheckCode(code));
}

Test(test_checkcode, test_illegal_code_arg_syntax_error)
{
    std::string code = "push xxx(6)\nexit";
    cr_assert(!avm::CheckCode(code));
}

Test(test_checkcode, test_illegal_code_syntax_error)
{
    std::string code = "xxxx int8(6)\nexit";
    cr_assert(!avm::CheckCode(code));
}