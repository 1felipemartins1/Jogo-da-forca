#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include "Pessoa.hpp"

//g++ -o arq Pessoa.hpp Pessoa.cpp main.cpp 

int main()
{
    std::string resposta;
    std::cout << "Insira uma palavra" << std::endl;
    std::getline(std::cin, resposta); // coletar a palavra para adivinharmos
    std::string resposta_formatada = conversor_min(resposta);
    int tamanho = resposta_formatada.length();
    int acertos = 0;
    std::vector<char> frase; //vetor que contem a resposta 
    Pessoa felipe;
    std::vector<bool> tentativas(26, false); // guarda quais letras foram tentadas
    felipe.LimpaTela(); 

    // loop que só para quando a vida zerar ou acertar tudo
    while (acertos < tamanho && felipe.getVida() > 0)
    {
        char letra;
        bool acertou_a_letra = false;
        for (char caractere : resposta_formatada) // armazenar a palavra em um vector para poder manipular de forma mais fácil
        {
            frase.push_back(caractere);
        }
        
        std::cout << "Digite uma letra" << std::endl;
        std::cin >> letra;
        try
        {
            if (tentativas[letra - 'a'])
            {
                throw Letratentada();
            }
            else
            {
                tentativas[letra - 'a'] = true; // registra a letra
                for (int i = 0; i < tamanho; i++)
                {
                    if (frase[i] == letra)
                    { 
                        felipe.LimpaTela();
                        acertos = acertos + 1;
                        acertou_a_letra = true;
                        std::cout << "Acertou" << std::endl; 
                    }
                }

                if (!acertou_a_letra)
                {   
                    felipe.LimpaTela();
                    felipe.Erro(); 
                
                }
            }
        }
        catch (const Letratentada &e)
        {
            std::cout << "ERRO: " << e.what() << std::endl;

            while (true)
            {
                std::cin >> letra;
                if (tentativas[letra - 'a'] == false)
                {
                    tentativas[letra - 'a'] = true;
                    bool acertou_nova_letra = false;

                    for (int i = 0; i < tamanho; i++)
                    {
                        if (frase[i] == letra)
                        {   
                            felipe.LimpaTela();
                            acertos = acertos + 1;
                            acertou_nova_letra = true;
                            std::cout << "Acertou" << std::endl;
                        }
                    }

                    if (!acertou_nova_letra)
                    {
                        felipe.LimpaTela();
                        felipe.Erro();
                    }

                    break; // Sai do loop se a letra for válida
                }
                else
                {
                    std::cout << "Você já tentou essa letra, por favor, tente outra" << std::endl;
                }
            }
        }
    }

    if (acertos == tamanho)
    { 
        felipe.LimpaTela();
        std::cout << "Parabéns! Você adivinhou a palavra: " << std::endl;
        std::cout << resposta << std::endl;
    }
    else
    {   

        felipe.LimpaTela();
        std::cout << "Você perdeu. A palavra era: " << std::endl;
        std::cout << resposta << std::endl;
    }

    return 0;
}
