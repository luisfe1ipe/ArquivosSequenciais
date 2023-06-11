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

void exibirApresentadores(struct apresentador apresentadores[], int contApresentadores)
{
    system("cls");
    cout << "\t\tIMPRIMINDO APRESENTADORES\n\n";
    for (int i = 0; i < contApresentadores; i++)
    {
        cout << "ID: " << apresentadores[i].id << endl;
        cout << "Nome: " << apresentadores[i].nome << endl;
        cout << "============================================\n";
    }
}

void incluirApresentadores(struct apresentador apresentadores[], int &contApresentadores, int contador)
{
    system("cls");
    struct apresentador inclusaoApresentadores[contador];
    int contInclusaoApresentadores = 0;
    lerApresentadores(inclusaoApresentadores, contInclusaoApresentadores);

    struct apresentador atApresentadores[contador];

    int i = 0, j = 0, k = 0;
    for (; i < contApresentadores && j < contInclusaoApresentadores; k++)
    {
        if (apresentadores[i].id < inclusaoApresentadores[j].id)
        {
            atApresentadores[k].id = apresentadores[i].id;
            strcpy(atApresentadores[k].nome, apresentadores[i].nome);
            i++;
        }
        else
        {
            atApresentadores[k].id = inclusaoApresentadores[j].id;
            strcpy(atApresentadores[k].nome, inclusaoApresentadores[j].nome);
            j++;
        }
    }

    while (i < contApresentadores)
    {
        atApresentadores[k].id = apresentadores[i].id;
        strcpy(atApresentadores[k].nome, apresentadores[i].nome);
        i++;
        k++;
    }

    while (j < contInclusaoApresentadores)
    {
        atApresentadores[k].id = inclusaoApresentadores[j].id;
        strcpy(atApresentadores[k].nome, inclusaoApresentadores[j].nome);
        j++;
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        apresentadores[i].id = atApresentadores[i].id;
        strcpy(apresentadores[i].nome, atApresentadores[i].nome);
    }

    contApresentadores = k;
}

int verificarCidade(struct cidade cidade[], int idCidade, int qtd)
{
    int i = 0, qtdVetor = qtd;
    int m = (i + qtdVetor) / 2;

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
        return m;
    }
    else
    {
        return -1;
    }
}

int verificarApresentador(struct apresentador apresentador[], int idApresentador, int qtd)
{
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
        return m;
    }
    else
    {
        return -1;
    }
}

int verificarEvento(struct evento evento[], int idEvento, int qtd)
{
    int i = 0, qtdVetor = qtd;
    int m = (i + qtdVetor) / 2;
    for (; qtdVetor >= i && idEvento != evento[m].id; m = (i + qtdVetor) / 2)
    {
        if (idEvento > evento[m].id)
        {
            i = m + 1;
        }
        else
        {
            qtdVetor = m - 1;
        }
    }

    if (idEvento == evento[m].id)
    {
        return m;
    }
    else
    {
        return -1;
    }
}

void lerParticipantes(struct participante p[], int &contParticipante, struct evento e[], int qtdVetorEvento, struct cidade c[], int qtdVetorCidade, struct apresentador ap[], int qtdVetorApresentador)
{
    system("cls");
    int qtdParticipantes = 0;
    int x = 1;
    int idEvento = 0;
    int confirmacao = 9;
    cout << "Quantos participantes deseja cadastrar ? ";
    cin >> qtdParticipantes;
    for (int i = 0; i < qtdParticipantes; i++)
    {
        cout << "ID da participante:";
        cin >> p[i].id;
        cout << "Nome do participante:";
        cin >> p[i].nome;
        while (x != 0)
        {
            cout << "ID da do evento: ";
            cin >> idEvento;
            int indiceEvento = verificarEvento(e, idEvento, qtdVetorEvento);
            if (indiceEvento != -1)
            {
                cout << "\t\tEvento encontrado!" << endl;
                cout << "\tDescricao do evento: " << e[indiceEvento].desc << endl;
                int indiceCidade = verificarCidade(c, e[indiceEvento].id_cidade, qtdVetorCidade);
                cout << "\tCidade do evento: " << c[indiceCidade].nome << endl;
                cout << "\tUF do evento: " << c[indiceCidade].uf << endl;
                int indiceApresentador = verificarApresentador(ap, e[indiceEvento].id_apresentador, qtdVetorApresentador);
                cout << "\tApresentador do evento: " << ap[indiceApresentador].nome << endl;
                cout << "\tDeseja confirmar o evento ? (Nao = 0 / Sim = 1)";
                cin >> confirmacao;
                if (confirmacao == 1)
                {
                    p[i].id_evento = idEvento;
                    x = 0;
                }
                else
                {
                    cout << "\tEvento nao confirmado. Digite novamente!\n";
                }
            }
            else
            {
                cout << "\tEvento nao encontrado. Digite novamente!\n";
            }
        }
        confirmacao = 9;
        x = 1;
        cout << "============================================\n\n";
        contParticipante = qtdParticipantes;
    }
    contParticipante = qtdParticipantes;
}

void lerEventos(struct evento evento[], int &contEvento, int qtdVetorCidade, int qtdVetorApresentador, struct cidade cidade[], struct apresentador apresentador[])
{
    system("cls");
    cout << "\t\tLEITURA DE EVENTOS\n\n";
    int qtdEventos = 0;
    int idCidade = 0;
    int idApresentador = 0;
    int x = 1;
    int confirmacao = 9;
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
            int indiceCidade = verificarCidade(cidade, idCidade, qtdVetorCidade);
            if (indiceCidade != -1)
            {
                cout << "\t\tCidade encontrada!" << endl;
                cout << "\tNome da cidade: " << cidade[indiceCidade].nome << endl;
                cout << "\tDeseja confirmar a cidade ? (Nao = 0 / Sim = 1)";
                cin >> confirmacao;
                if (confirmacao == 1)
                {
                    evento[i].id_cidade = idCidade;
                    x = 0;
                }
                else
                {
                    cout << "\tCidade nao confirmada. Digite novamente!\n";
                }
            }
            else
            {
                cout << "\tCidade nao encontrada. Digite novamente!\n";
            }
        }
        confirmacao = 9;
        x = 1;
        while (x != 0)
        {
            cout << "ID do apresentador: ";
            cin >> idApresentador;
            int indiceApresentador = verificarApresentador(apresentador, idApresentador, qtdVetorApresentador);
            if (indiceApresentador != -1)
            {
                cout << "\t\tApresentador encontrado!" << endl;
                cout << "\tNome do apresentador: " << apresentador[indiceApresentador].nome << endl;
                cout << "\tDeseja confirmar o apresentador ? (Nao = 0 / Sim = 1)";
                cin >> confirmacao;
                if (confirmacao == 1)
                {
                    evento[i].id_apresentador = idApresentador;
                    x = 0;
                }
                else
                {
                    cout << "\tApresentador nao confirmado. Digite novamente!\n";
                }
            }
            else
            {
                cout << "\tApresentador nao encontrado. Digite novamente!\n";
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
            cout << "\nDigite uma quantidade de participantes inferior ou igual ao limite(" << evento[i].limiteParticipantes << "): ";
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
        cout << "==========================================================\n";
    }
}

int main()
{
    const int CONTADOR = 1000;
    struct cidade cidades[CONTADOR];
    struct apresentador apresentadores[CONTADOR];
    struct evento eventos[CONTADOR];
    struct participante participantes[CONTADOR];

    int contCidade = 0;
    int contApresentador = 0;
    int contEvento = 0;
    int contParticipante = 0;

    int op = 99;
    while (op != 0)
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
        cout << "\t\t[6] - Inserir Apresentadores\n\n";
        cout << "\t\t------------------------------\n\n";
        cout << "\t\t[7] FALTA - Ler Participantes\n\n";
        cout << "\t\t[8] FALTA - Exibir Participantes\n\n";
        cout << "\t\t[9] FALTA - Inserir Participantes\n\n";
        cout << "\t\t------------------------------\n\n";
        cout << "\t\t[10] - Ler Eventos\n\n";
        cout << "\t\t[11] - Exibir Eventos\n\n";
        cout << "\t\t[12] FALTA - Inserir Eventos\n\n";
        cout << "\t\t[0] - [Sair]\n";

        fflush(stdin);
        cout << "\n\n\t\tInforme a sua escolha: ";
        cin >> op;

        switch (op)
        {
        case 0:
        {
            cout << "\n\nSaindo...\n\n";
            break;
        }
        case 1:
        {
            lerCidades(cidades, contCidade);
            break;
        }
        case 2:
        {
            exibirCidades(cidades, contCidade);
            break;
        }
        case 4:
        {
            lerApresentadores(apresentadores, contApresentador);
            break;
        }
        case 5:
        {
            exibirApresentadores(apresentadores, contApresentador);
            break;
        }
        case 6:
        {
            incluirApresentadores(apresentadores, contApresentador, CONTADOR);
            break;
        }
        case 7:
        {
            lerParticipantes(participantes, contParticipante, eventos, contEvento, cidades, contCidade, apresentadores, contApresentador);
            break;
        }
        case 10:
        {
            lerEventos(eventos, contEvento, contCidade, contApresentador, cidades, apresentadores);
            break;
        }
        case 11:
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
