/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** Operand.hpp
*/

#ifndef ABSTRACTVM_OPERAND_HPP_
    #define ABSTRACTVM_OPERAND_HPP_

    #include <string>

    #include "IOperand.hpp"

    namespace avm {
        class Operand : public IOperand
        {
        protected:
            const std::string *value;
            avm::eOperandType type;
            unsigned int precision;
        public:
            unsigned int getPrecision();
            eOperandType getType();
            std::string toString();

            virtual IOperand* operator+(const IOperand &rhs) const = 0;
            virtual IOperand* operator-(const IOperand &rhs) const = 0;
            virtual IOperand* operator*(const IOperand &rhs) const = 0;
            virtual IOperand* operator/(const IOperand &rhs) const = 0;
            virtual IOperand* operator%(const IOperand &rhs) const = 0;

            Operand();
            ~Operand();
        };
    };

#endif