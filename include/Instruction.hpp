/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** Instruction.hpp
*/

#ifndef INSTRUCTION_HPP_
    #define INSTRUCTION_HPP_

    #include "IOperand.hpp"
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>

    namespace avm {
        bool HasOnlySpaces(std::string& str);
        avm::eInstruction getInstruction(std::string instruction);
        avm::eOperandType getType(std::string value);
    }

#endif