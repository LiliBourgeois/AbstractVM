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
        protected:
            const std::string *value;
            avm::eOperandType type;
            unsigned int precision;
        public:
            myDouble(const std::string &value);
            ~myDouble();

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