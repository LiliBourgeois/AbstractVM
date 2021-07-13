/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** bigdecimal.hpp
*/

#ifndef ABSTRACT_BIGDECIMAL_HPP_
    #define ABSTRACT_BIGDECIMAL_HPP_

    #include <string>

    #include "IOperand.hpp"

    namespace avm {
        class myBigdecimal : IOperand
        {
        protected:
            const std::string *value;
            avm::eOperandType type;
            unsigned int precision;
        public:
            myBigdecimal(const std::string &value);
            ~myBigdecimal();

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