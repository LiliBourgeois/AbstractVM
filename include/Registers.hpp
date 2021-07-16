/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** Registers.hpp
*/

#ifndef ABSTRACTVM_REGISTERS_HPP_
    #define ABSTRACTVM_REGISTERS_HPP_

    #include <vector>

    #include "IOperand.hpp"

    namespace avm {

        class Registers
        {
        private:
            unsigned int idx;
            bool Empty;
            avm::IOperand *data;
        public:
            void setData(avm::IOperand *data);
            unsigned int getIdx();
            bool isEmpty();
            avm::IOperand *getData();
            Registers(unsigned int idx);
            ~Registers();
        };

        void createRegisters(std::vector<avm::Registers *> &);

    }

#endif