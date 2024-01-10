#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>
#include <vector>  
#include <cstdlib> //biblioteca para limpar a tela   
#include <cctype>

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

std::string conversor_min(const std::string & entrada);

std:: vector<char> conversor_vec_char(const std::string & entrad); 

#endif  
