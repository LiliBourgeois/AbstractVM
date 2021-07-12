/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int32.hpp
*/

#ifndef ABSTRACT_INT32_HPP_
    #define ABSTRACT_INT32_HPP_

    #include <string>

    #include "IOperand.hpp"

    namespace avm {
        class myInt32 : IOperand
        {
        private:
            const std::string *value;
        public:
            myInt32();
            ~myInt32();
            eOperandType getType();
            std::string toString();
        };
    };

#endif