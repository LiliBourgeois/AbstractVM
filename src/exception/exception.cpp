/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** exception.cpp
*/

#include "Exception.hpp"

void avm::myException::printError(const char *error)
{
    std::cerr << error;
}