/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int8.hpp
*/

#ifndef ABSTRACT_INT8_HPP_
    #define ABSTRACT_INT8_HPP_

    #include <string>

    #include "IOperand.hpp"

    namespace avm {
        class myInt8 : public IOperand
        {
        protected:
            std::string value;
            avm::eOperandType type;
            unsigned int precision;
        public:
            myInt8(const std::string &value);
            ~myInt8();

            std::string toString() const override;
            eOperandType getType() const override;
            unsigned int getPrecision() const override;

            avm::IOperand *operator+(const IOperand &rhs) const override;
            avm::IOperand *operator-(const IOperand &rhs) const override;
            avm::IOperand *operator*(const IOperand &rhs) const override;
            avm::IOperand *operator/(const IOperand &rhs) const override;
            avm::IOperand *operator%(const IOperand &rhs) const override;
        };
    };

#endif