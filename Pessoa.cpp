#include "Pessoa.hpp"

// Implementação da classe Letratentada
const char* Letratentada::what() const throw()
{
    return "Você já tentou essa letra, tente outra!\t";
}

// Implementação da classe Pessoa
Pessoa::Pessoa()
{
    this->vida = 6;
}

void Pessoa::Erro()
{
    this->vida = this->vida - 1;
    int x = this->vida;
    if (x == 0)
    {
        std::cout << "Você morreu" << std::endl;
    }
    else
    {
        std::cout << "Você ainda tem " << x << " vidas" << std::endl;
    }
}

int Pessoa::getVida() const
{
    return vida;
}

void Pessoa::LimpaTela(){
    #ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
