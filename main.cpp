#include <conio.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct cidade
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
    char desc[30];
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

void lerCidades(struct cidade cidade[], int &contCidade)
{
    system("cls");
    int qtdCidade = 0;
    cout << "Quantas cidade deseja cadastrar ? ";
    cin >> qtdCidade;
    for (int i = 0; i < qtdCidade; i++)
    {
        cout << "ID da cidade:";
        cin >> cidade[i].id;
        cout << "Nome da cidade:";
        cin >> cidade[i].nome;
        cout << "Nome do UF:";
        cin >> cidade[i].uf;
        cout << "============================================\n\n";
    }
    contCidade = qtdCidade;
}

void exibirCidades(struct cidade cidade[], int contCidade)
{
    system("cls");
    cout << "\t\tIMPRIMINDO CIDADES\n\n";
    for (int i = 0; i < contCidade; i++)
    {
        cout << "ID: " << cidade[i].id << endl;
        cout << "Nome: " << cidade[i].nome << endl;
        cout << "UF: " << cidade[i].uf << endl;
        cout << "============================================\n";
    }
}

void lerApresentadores(struct apresentador apresentador[], int &contApresentador)
{
    system("cls");
    cout << "\t\tLEITURA DE APRESENTADORES\n\n";
    int qtdApresentadores = 0;
    cout << "Quantos apresentadores deseja cadastrar ? ";
    cin >> qtdApresentadores;
    for (int i = 0; i < qtdApresentadores; i++)
    {
        cout << "ID: ";
        cin >> apresentador[i].id;
        cout << "Nome: ";
        cin >> apresentador[i].nome;
        cout << "============================================\n";
    }
    contApresentador = qtdApresentadores;
}

void exibirApresentadores(struct apresentador apresentador[], int contApresentador)
{
    system("cls");
    cout << "\t\tIMPRIMINDO APRESENTADORES\n\n";
    for (int i = 0; i < contApresentador; i++)
    {
        cout << "ID: " << apresentador[i].id << endl;
        cout << "Nome: " << apresentador[i].nome << endl;
        cout << "============================================\n";
    }
}

bool verificarCidade(struct cidade cidade[], int idCidade, int qtd)
{
    int i = 0, qtdVetor = qtd;
    int m = (i + qtdVetor) / 2;
    int confirmar = 9;

    for (; qtdVetor >= i && idCidade != cidade[m].id; m = (i + qtdVetor) / 2)
    {
        if (idCidade > cidade[m].id)
        {
            i = m + 1;
        }
        else
        {
            qtdVetor = m - 1;
        }
    }

    if (idCidade == cidade[m].id)
    {
        cout << "\tNome cidade: " << cidade[m].nome << endl;
        cout << "\tUF cidade: " << cidade[m].uf << endl;
        cout << "\tDeseja confirmar a cidade ? [0 == nao/1 == sim]\n";
        cin >> confirmar;
        if (confirmar == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool verificarApresentador(struct apresentador apresentador[], int idApresentador, int qtd)
{
    int confirmar = 9;
    int i = 0, qtdVetor = qtd;
    int m = (i + qtdVetor) / 2;
    for (; qtdVetor >= i && idApresentador != apresentador[m].id; m = (i + qtdVetor) / 2)
    {
        if (idApresentador > apresentador[m].id)
        {
            i = m + 1;
        }
        else
        {
            qtdVetor = m - 1;
        }
    }

    if (idApresentador == apresentador[m].id)
    {
        cout << "\tNome apresentador: " << apresentador[m].nome << endl;
        cout << "\tDeseja confirmar a cidade ? [0 == nao/1 == sim]\n";
        cin >> confirmar;
        if (confirmar == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void lerEventos(struct evento evento[], int &contEvento, int qtdVetorCidade, int qtdVetorApresentador, struct cidade cidade[], struct apresentador apresentador[])
{
    system("cls");
    cout << "\t\tLEITURA DE EVENTOS\n\n";
    int qtdEventos = 0;
    int idCidade = 0;
    int idApresentador = 0;
    int x = 1;
    cout << "Quantos eventos deseja cadastrar ? ";
    cin >> qtdEventos;
    for (int i = 0; i < qtdEventos; i++)
    {
        cout << "ID: ";
        cin >> evento[i].id;
        cout << "Nome: ";
        cin >> evento[i].desc;
        while (x != 0)
        {
            cout << "ID da cidade: ";
            cin >> idCidade;
            if (verificarCidade(cidade, idCidade, qtdVetorCidade) == true)
            {
                evento[i].id_cidade = idCidade;
                x = 0;
            }
            else
            {
                cout << "Cidade nao encontrada ou nao confirmada. Digite novamente!\n";
            }
        }
        x = 1;
        while (x != 0)
        {
            cout << "ID do apresentador: ";
            cin >> idApresentador;
            if (verificarApresentador(apresentador, idApresentador, qtdVetorApresentador) == true)
            {
                evento[i].id_apresentador = idApresentador;
                x = 0;
            }
            else
            {
                cout << "Apresentador nao encontrado.";
            }
        }
        x = 1;
        cout << "Limite de participantes: ";
        cin >> evento[i].limiteParticipantes;
        cout << "Quantidade de participantes: ";
        cin >> evento[i].qtdParticipantes;

        while (evento[i].qtdParticipantes > evento[i].limiteParticipantes)
        {
            cout << "Quantidade de participantes maior que o limite(" << evento[i].limiteParticipantes << ")" << endl;
            cout << "\nDigite uma quantidade de participantes inferior ao limite(" << evento[i].limiteParticipantes << "): ";
            cin >> evento[i].qtdParticipantes;
        }

        cout << "Preco unitario: ";
        cin >> evento[i].precoUnitario;
        cout << "============================================\n\n";
    }
    contEvento = qtdEventos;
}

void exibirEventos(struct evento evento[], int contEvento)
{
    system("cls");
    cout << "\t\tIMPRIMINDO EVENTOS\n\n";
    for (int i = 0; i < contEvento; i++)
    {
        cout << "ID: " << evento[i].id << endl;
        cout << "Nome: " << evento[i].desc << endl;
        cout << "ID cidade: " << evento[i].id_cidade << endl;
        cout << "ID apresentador: " << evento[i].id_apresentador << endl;
        cout << "Limite de participantes: " << evento[i].limiteParticipantes << endl;
        cout << "Quantidade de participantes: " << evento[i].qtdParticipantes << endl;
    }
}

int main()
{
    const int CONTADOR = 1000;
    struct cidade cidades[CONTADOR];
    struct apresentador apresentadores[CONTADOR];
    struct evento eventos[CONTADOR];

    int contCidade = 0;
    int contApresentador = 0;
    int contEvento = 0;

    char op = 'x';
    while (op != '0')
    {
        system("cls");
        cout << "\t\tArquivos Sequenciais\n\n";

        cout << "\t\t\t|Menu de opcoes|\n\n";
        cout << "\t\t[1] - Ler Cidades\n\n";
        cout << "\t\t[2] - Exibir Cidades\n\n";
        cout << "\t\t[3] FALTA - Inserir Cidades\n\n";
        cout << "\t\t------------------------------\n\n";
        cout << "\t\t[4] - Ler Apresentadores\n\n";
        cout << "\t\t[5] - Exibir Apresentadores\n\n";
        cout << "\t\t[6] FALTA - Inserir Apresentadores\n\n";
        cout << "\t\t------------------------------\n\n";
        cout << "\t\t[7] - Ler Eventos\n\n";
        cout << "\t\t[8] - Exibir Eventos\n\n";
        cout << "\t\t[9] FALTA - Inserir Eventos\n\n";
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
        case '1':
        {
            lerCidades(cidades, contCidade);
            break;
        }
        case '2':
        {
            exibirCidades(cidades, contCidade);
            break;
        }
        case '4':
        {
            lerApresentadores(apresentadores, contApresentador);
            break;
        }
        case '5':
        {
            exibirApresentadores(apresentadores, contApresentador);
            break;
        }
        case '7':
        {
            lerEventos(eventos, contEvento, contCidade, contApresentador, cidades, apresentadores);
            break;
        }
        case '8':
        {
            exibirEventos(eventos, contEvento);
            break;
        }
        default:
        {
            cout << "Opcao invalida\n";
            break;
        }
        }
        system("pause");
    }
}
