#include <iostream>
#include <string>
#include <vector>

class Pessoa
{
private:
    int vida;
    int acertos;

public:
    Pessoa()
    {
        this->vida = 6;
    }

    void Erro()
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

    int getVida() const
    {
        return vida;
    }
};

int main()
{
    std::string resposta;
    std::cout << "Insira uma palavra" << std::endl;
    std::cin >> resposta; // coletar a palavra para adivinharmos
    int tamanho = resposta.length();
    int acertos = 0;
    std::vector<char> frase;
    Pessoa felipe;
    std::vector<bool> tentativas(26, false); // guarda quais letras foram tentadas

    // loop que só para quando a vida zerar ou acertar tudo
    while (acertos < tamanho && felipe.getVida() > 0)
    {
        char letra;
        bool acertou_a_letra = false;
        for (char caractere : resposta) // armazenar a palavra em um vector para poder manipular de forma mais fácil
        {
            frase.push_back(caractere);
        }

        std::cout << "Digite uma letra" << std::endl;
        std::cin >> letra;

        if (tentativas[letra - 'a'])
        {
            std::cout << "Você já tentou essa letra. Tente outra." << std::endl;
            continue;
        }
        else
        {
            tentativas[letra - 'a'] = true; // registra a letra
            for (int i = 0; i < tamanho; i++)
            {
                if (frase[i] == letra)
                {
                    acertos = acertos + 1;
                    acertou_a_letra = true;
                    std::cout << "Acertou" << std::endl;
                }
            }

            if (!acertou_a_letra)
            {
                felipe.Erro();
            }
        }
    }

    if (acertos == tamanho)
    {
        std::cout << "Parabéns! Você adivinhou a palavra: " << resposta << std::endl;
    }
    else
    {
        std::cout << "Você perdeu. A palavra era: /t" << resposta << std::endl;
    }

    return 0;
}
