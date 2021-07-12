/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** main.cpp
*/

#include "AbstractVM.hpp"

std::string ReadFromFile(char *filename)
{
    std::string line("");
    std::string codeAsm("");
    std::ifstream myfile(filename);

    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            codeAsm = codeAsm + line;
        }
        myfile.close();
        std::cout << codeAsm;
    }
    return codeAsm;
}

std::string ReadFromTerminal()
{
    std::string codeAsm("");
    std::string line("");

    while(line.compare(";;")) {
        codeAsm = codeAsm + line;
        std::cin >> line;
    }
    return codeAsm;
}

int main(int ac, char **av)
{
    std::string codeAsm;
    if (ac == 2)
        codeAsm = ReadFromFile(av[1]);
    else if (ac == 1)
        codeAsm = ReadFromTerminal();
    else
        std::cerr << "error: Please enter only one file name or less\n";
        return 84;
    if (codeAsm.compare(""))
        return 84;
    if (AbstractVM(codeAsm) == 84)
        return 84;
    return 0;
}