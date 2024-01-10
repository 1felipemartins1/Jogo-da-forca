#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>
#include <vector>  
#include <cstdlib> //biblioteca para limpar a tela  
class Letratentada : public std::exception
{
public:
    const char *what() const throw();
};

class Pessoa
{
private:
    int vida;
    int acertos;

public:
    Pessoa();

    void Erro();

    int getVida() const;

    void LimpaTela();
};

#endif  
