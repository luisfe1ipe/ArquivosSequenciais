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