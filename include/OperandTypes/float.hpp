/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** float.hpp
*/

#ifndef ABSTRACT_FLOAT_HPP_
    #define ABSTRACT_FLOAT_HPP_

    #include <string>

    #include "IOperand.hpp"

    namespace avm {
        class myFloat : IOperand
        {
        private:
            const std::string *value;
        public:
            myFloat();
            ~myFloat();
            eOperandType getType();
            std::string toString();
        };
    };

#endif