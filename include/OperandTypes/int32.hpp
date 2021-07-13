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
        protected:
            const std::string *value;
            avm::eOperandType type;
            unsigned int precision;
        public:
            myInt32(const std::string &value);
            ~myInt32();

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