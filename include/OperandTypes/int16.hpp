/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int16.hpp
*/

#ifndef ABSTRACT_INT16_HPP_
    #define ABSTRACT_INT16_HPP_

    #include <string>

    #include "IOperand.hpp"

    namespace avm {
        class myInt16 : IOperand
        {
        private:
            const std::string *value;
        public:
            myInt16();
            ~myInt16();
            eOperandType getType();
            std::string toString();
        };
    };

#endif