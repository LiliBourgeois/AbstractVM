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
        protected:
            const std::string *value;
            avm::eOperandType type;
            unsigned int precision;
        public:
            myFloat(const std::string &value);
            ~myFloat();

            std::string toString() const;
            eOperandType getType() const;
            unsigned int getPrecision() const;

            avm::IOperand *operator+(const IOperand &rhs) const;
            avm::IOperand *operator-(const IOperand &rhs) const;
            avm::IOperand *operator*(const IOperand &rhs) const;
            avm::IOperand *operator/(const IOperand &rhs) const;
            avm::IOperand *operator%(const IOperand &rhs) const;
        };
    };

#endif