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
        class myInt32 : public IOperand
        {
        protected:
            std::string value;
            avm::eOperandType type;
            unsigned int precision;
        public:
            myInt32(const std::string &value);
            ~myInt32();

            std::string toString() const override;
            eOperandType getType() const override;
            unsigned int getPrecision() const override;
            long double getMaxValue() const override;
            long double getMinValue() const override;

            avm::IOperand *operator+(const IOperand &rhs) const override;
            avm::IOperand *operator-(const IOperand &rhs) const override;
            avm::IOperand *operator*(const IOperand &rhs) const override;
            avm::IOperand *operator/(const IOperand &rhs) const override;
            avm::IOperand *operator%(const IOperand &rhs) const override;
        };
    };

#endif