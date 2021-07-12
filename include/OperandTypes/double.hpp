/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** double.hpp
*/

#ifndef ABSTRACT_DOUBLE_HPP_
    #define ABSTRACT_DOUBLE_HPP_

    #include <string>

    #include "IOperand.hpp"

    namespace avm {
        class myDouble : IOperand
        {
        const std::string *value;
        public:
            myDouble();
            ~myDouble();
            eOperandType getType();
            std::string toString();
        };
    };

#endif