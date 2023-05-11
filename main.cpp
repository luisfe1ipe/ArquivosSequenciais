#include <conio.h>
#include <iostream>

using namespace std;

struct cidadeEvento
{
    int id;
    char nome[30];
    char uf[2];
};

struct apresentador
{
    int id;
    char nome[30];
};

struct evento
{
    int id;
    char desc[50];
    int id_cidade;
    int id_apresentador;
    int qtdParticipantes;
    int limiteParticipantes;
    float precoUnitario;
};

struct participante
{
    int id;
    char nome[30];
    int id_evento;
};

int main(int argc, char const *argv[])
{
    char op = 'x';
    while (op != '0')
    {
        system("cls");
        cout << "\t\tLista Sequencial de Alunos de tamanho: " << N << "\n\n";

        cout << "\t\t\t|Menu de opcoes|\n\n";
        cout << "\t\t[0] - [Sair]\n";

        fflush(stdin);
        cout << "\n\n\t\tInforme a sua escolha: ";
        op = getchar();

        switch (op)
        {
        case '0':
        {
            cout << "\n\nSaindo...\n\n";
            break;
        }
        default:
        {
            cout << "Opção invalida";
            break;
        }
        }
        system("pause");
    }
}
