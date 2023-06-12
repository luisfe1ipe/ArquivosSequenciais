#include <conio.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/*

    STRUCTS

*/
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

/*

    PROTÓTIPO DAS FUNÇÕES - LEITURA

*/

void lerCidades(struct cidade cidade[], int &contCidade);
void lerApresentadores(struct apresentador apresentador[], int &contApresentador);
void lerParticipantes(struct participantes participantes[], int &contParticipante);
void lerEventos(struct evento evento[], int &contEvento, int qtdVetorCidade, int qtdVetorApresentador, struct cidade cidade[], struct apresentador apresentador[]);

/*

    PROTÓTIPO DAS FUNÇÕES - EXIBIR

*/

void exibirCidades(struct cidade cidade[], int contCidade);
void exibirApresentadores(struct apresentador apresentadores[], int contApresentadores);
void exibirEventos(struct evento evento[], int contEvento, struct cidade cidade[], int contCidade, struct apresentador apresentador[], int contApresentador);
void exibirUmEvento(struct evento evento[], int contEvento, struct cidade cidade[], int contCidade, struct apresentador apresentador[], int contApresentador);

/*

    PROTÓTIPO DAS FUNÇÕES - BUSCA BINARIA

*/

int verificarCidade(struct cidade cidade[], int idCidade, int qtd);
int verificarParticipante(struct participante participante[], int idParticipante, int qtd);
int verificarApresentador(struct apresentador apresentador[], int idApresentador, int qtd);
int verificarEvento(struct evento evento[], int idEvento, int qtd);

/*

    PROTÓTIPO DAS FUNÇÕES - INCLUSÃO

*/

void incluirApresentadores(struct apresentador apresentadores[], int &contApresentadores, int contador);
void incluirEventos(struct evento evento[], int &contEventos, int contador, int qtdVetorCidade, int qtdVetorApresentador, struct cidade cidade[], struct apresentador apresentador[]);

/*

    PROTÓTIPO DAS FUNÇÕES - OUTROS

*/

void inscricaoEvento(struct evento evento[], int &contEvento, struct participante participante[], int &contParticipante, struct cidade cidade[], int &contCidade, struct apresentador apresentador[], int &contApresentador);

/*

    ----------------------- FUNÇÕES LEITURA -----------------------

*/

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

void lerParticipantes(struct participante p[], int &contParticipante)
{
    system("cls");
    int qtdParticipantes = 0;
    cout << "Quantos participantes deseja cadastrar ? ";
    cin >> qtdParticipantes;
    for (int i = 0; i < qtdParticipantes; i++)
    {
        cout << "ID da participante:";
        cin >> p[i].id;
        cout << "Nome do participante:";
        cin >> p[i].nome;
        p[i].id_evento = 0;
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

/*

    ----------------------- FUNÇÕES EXIBIR -----------------------

*/

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

void exibirUmEvento(struct evento evento[], int contEvento, struct cidade cidade[], int contCidade, struct apresentador apresentador[], int contApresentador)
{
    system("cls");
    int x = 1, idEvento = 0;
    while (x != 0)
    {
        cout << "\nDigite o ID do evento para exibi-lo: ";
        cin >> idEvento;

        int indiceEvento = verificarEvento(evento, idEvento, contEvento);
        if (indiceEvento != -1)
        {
            cout << "ID: " << evento[indiceEvento].id << endl;
            cout << "Descricao: " << evento[indiceEvento].desc << endl;
            int indiceCidade = verificarCidade(cidade, evento[indiceEvento].id_cidade, contCidade);
            cout << "Cidade: " << cidade[indiceCidade].nome << endl;
            int indiceApresentador = verificarApresentador(apresentador, evento[indiceEvento].id_apresentador, contApresentador);
            cout << "Apresentador: " << apresentador[indiceApresentador].nome << endl;
            cout << "Limite de participantes: " << evento[indiceEvento].limiteParticipantes << endl;
            cout << "Quantidade de participantes: " << evento[indiceEvento].qtdParticipantes << endl;
            cout << "Preco unitario: " << evento[indiceEvento].precoUnitario << " reais" << endl;
            cout << "Valor total: " << evento[indiceEvento].precoUnitario * evento[indiceEvento].qtdParticipantes << " reais" << endl;
            x = 0;
        }
        else
        {
            cout << "Evento nao encontrado. Digite novamente!";
        }
    }
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

void exibirEventos(struct evento evento[], int contEvento, struct cidade cidade[], int contCidade, struct apresentador apresentador[], int contApresentador)
{
    system("cls");
    float valorTotal = 0, valorTotalEvento = 0;
    cout << "\t\tIMPRIMINDO EVENTOS\n\n";
    for (int i = 0; i < contEvento; i++)
    {
        cout << "ID: " << evento[i].id << endl;
        cout << "Descricao: " << evento[i].desc << endl;
        int indiceCidade = verificarCidade(cidade, evento[i].id_cidade, contCidade);
        cout << "Cidade: " << cidade[indiceCidade].nome << endl;
        int indiceApresentador = verificarApresentador(apresentador, evento[i].id_apresentador, contApresentador);
        cout << "Apresentador: " << apresentador[indiceApresentador].nome << endl;
        cout << "Limite de participantes: " << evento[i].limiteParticipantes << endl;
        cout << "Quantidade de participantes: " << evento[i].qtdParticipantes << endl;
        cout << "Preco unitario: " << evento[i].precoUnitario << endl;
        valorTotalEvento = evento[i].precoUnitario * evento[i].qtdParticipantes;
        cout << "Valor total do evento: " << valorTotalEvento << " reais" << endl;
        valorTotal = valorTotal + valorTotalEvento;
        cout << "==========================================================\n";
    }
    cout << "O valor total de todos eventos: " << valorTotal << " reais" << endl;
}

/*

    ----------------------- FUNÇÕES BUSCA BINARIA -----------------------

*/

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

int verificarParticipante(struct participante participante[], int idParticipante, int qtd)
{
    int i = 0, qtdVetor = qtd;
    int m = (i + qtdVetor) / 2;

    for (; qtdVetor >= i && idParticipante != participante[m].id; m = (i + qtdVetor) / 2)
    {
        if (idParticipante > participante[m].id)
        {
            i = m + 1;
        }
        else
        {
            qtdVetor = m - 1;
        }
    }

    if (idParticipante == participante[m].id)
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

/*

    ----------------------- FUNÇÕES INCLUSÃO -----------------------

*/

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

void incluirEventos(struct evento evento[], int &contEventos, int contador, int qtdVetorCidade, int qtdVetorApresentador, struct cidade cidade[], struct apresentador apresentador[])
{
    system("cls");
    struct evento inclusaoEvento[contador];
    int contInclusaoEvento = 0;
    lerEventos(inclusaoEvento, contInclusaoEvento, qtdVetorCidade, qtdVetorApresentador, cidade, apresentador);

    struct evento atEvento[contador];

    int i = 0, k = 0, j = 0;
    for (; i < contEventos && j < contInclusaoEvento; k++)
    {
        if (evento[i].id < inclusaoEvento[j].id)
        {
            atEvento[k].id = evento[i].id;
            strcpy(atEvento[k].desc, evento[i].desc);
            atEvento[k].id_cidade = evento[i].id_cidade;
            atEvento[k].id_apresentador = evento[i].id_apresentador;
            atEvento[k].qtdParticipantes = evento[i].qtdParticipantes;
            atEvento[k].limiteParticipantes = evento[i].limiteParticipantes;
            atEvento[k].precoUnitario = evento[i].precoUnitario;
            i++;
        }
        else
        {
            atEvento[k].id = inclusaoEvento[j].id;
            strcpy(atEvento[k].desc, inclusaoEvento[j].desc);
            atEvento[k].id_cidade = inclusaoEvento[j].id_cidade;
            atEvento[k].id_apresentador = inclusaoEvento[j].id_apresentador;
            atEvento[k].qtdParticipantes = inclusaoEvento[j].qtdParticipantes;
            atEvento[k].limiteParticipantes = inclusaoEvento[j].limiteParticipantes;
            atEvento[k].precoUnitario = inclusaoEvento[j].precoUnitario;
            j++;
        }
    }

    while (i < contEventos)
    {
        atEvento[k].id = evento[i].id;
        strcpy(atEvento[k].desc, evento[i].desc);
        atEvento[k].id_cidade = evento[i].id_cidade;
        atEvento[k].id_apresentador = evento[i].id_apresentador;
        atEvento[k].qtdParticipantes = evento[i].qtdParticipantes;
        atEvento[k].limiteParticipantes = evento[i].limiteParticipantes;
        atEvento[k].precoUnitario = evento[i].precoUnitario;
        i++;
        k++;
    }

    while (j < contInclusaoEvento)
    {
        atEvento[k].id = inclusaoEvento[j].id;
        strcpy(atEvento[k].desc, inclusaoEvento[j].desc);
        atEvento[k].id_cidade = inclusaoEvento[j].id_cidade;
        atEvento[k].id_apresentador = inclusaoEvento[j].id_apresentador;
        atEvento[k].qtdParticipantes = inclusaoEvento[j].qtdParticipantes;
        atEvento[k].limiteParticipantes = inclusaoEvento[j].limiteParticipantes;
        atEvento[k].precoUnitario = inclusaoEvento[j].precoUnitario;
        j++;
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        evento[i].id = atEvento[i].id;
        strcpy(evento[i].desc, atEvento[i].desc);
        evento[i].id_cidade = atEvento[i].id_cidade;
        evento[i].id_apresentador = atEvento[i].id_apresentador;
        evento[i].qtdParticipantes = atEvento[i].qtdParticipantes;
        evento[i].limiteParticipantes = atEvento[i].limiteParticipantes;
        evento[i].precoUnitario = atEvento[i].precoUnitario;
    }

    contEventos = k;
}

/*

    ----------------------- FUNÇÕES OUTROS -----------------------

*/

void inscricaoEvento(struct evento evento[], int &contEvento, struct participante participante[], int &contParticipante, struct cidade cidade[], int &contCidade, struct apresentador apresentador[], int &contApresentador)
{
    system("cls");
    int x = 1, y = 1, idEvento = 0, idParticipante = 0, confirmacaoEvento = 9, confirmacaoParticipante = 9;
    cout << "\tREALIZAR INSCRICAO NO EVENTO\n\n";

    while (x != 0)
    {
        cout << "\nDigite o ID do evento para realizar a inscricao: ";
        cin >> idEvento;

        int indiceEvento = verificarEvento(evento, idEvento, contEvento);
        if (indiceEvento != -1)
        {
            x = 0;
            cout << "\t\tEvento encontrado!" << endl;
            cout << "\t\nDescricao do evento: " << evento[indiceEvento].desc << endl;
            int indiceCidade = verificarCidade(cidade, evento[indiceEvento].id_cidade, contCidade);
            cout << "\tCidade do evento: " << cidade[indiceCidade].nome << endl;
            int indiceApresentador = verificarApresentador(apresentador, evento[indiceEvento].id_apresentador, contApresentador);
            cout << "\tApresentador do evento: " << apresentador[indiceApresentador].nome << endl;
            cout << "\t\nDeseja confirmar o evento ? (Nao = 0 / Sim = 1)";
            cin >> confirmacaoEvento;
            if (confirmacaoEvento == 1)
            {
                x = 0;
                if (evento[indiceEvento].limiteParticipantes > evento[indiceCidade].qtdParticipantes)
                {
                    cout << "\nDigite o ID do participante: ";
                    cin >> idParticipante;
                    int indiceParticipante = verificarParticipante(participante, idParticipante, contParticipante);
                    while (y != 0)
                    {
                        if (indiceParticipante != -1)
                        {
                            cout << "\t\tParticipante encontrado!" << endl;
                            cout << "\tNome do participante: " << participante[indiceParticipante].nome << endl;
                            cout << "\t\nDeseja confirmar o participante ? (Nao = 0 / Sim = 1)";
                            cin >> confirmacaoParticipante;
                            if (confirmacaoParticipante == 1)
                            {
                                participante[indiceParticipante].id_evento = evento[indiceEvento].id;
                                evento[indiceEvento].qtdParticipantes++;
                                y = 0;
                            }
                            else
                            {
                                cout << "\tParticipante nao confirmado. Digite novamente!";
                            }
                        }
                        else
                        {
                            cout << "\tParticipante nao encontrado. Digite novamente!" << endl;
                        }
                    }
                }
                else
                {
                    cout << "\tO evento atingiu o limite maximo de participantes." << endl;
                }
            }
            else
            {
                cout << "\tEvento nao confirmado. Digite novamente!";
            }
        }
        else
        {
            cout << "\tEvento nao encontrado. Digite novamente!" << endl;
        }
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

        cout << "\t\t\t|Menu de opcoes|\n\n\n";
        cout << "\t\t| LEITURA |\n\n";
        cout << "\t\t[1] - Ler Cidades\n\n";
        cout << "\t\t[2] - Ler Apresentadores\n\n";
        cout << "\t\t[3] - Ler Participantes\n\n";
        cout << "\t\t[4] - Ler Eventos\n\n";
        cout << "\t\t------------------------------\n\n\n";
        cout << "\t\t| EXIBIR |\n\n";
        cout << "\t\t[5] - Exibir um Evento\n\n";
        cout << "\t\t[6] - Exibir todos Eventos\n\n\n";
        cout << "\t\t------------------------------\n\n";
        cout << "\t\t| INCLUSAO |\n\n";
        cout << "\t\t[7] Incluir Apresentadores\n\n";
        cout << "\t\t[8] Incluir Eventos\n\n";
        cout << "\t\t------------------------------\n\n\n";
        cout << "\t\t| OUTROS |\n\n";
        cout << "\t\t[9] - Realizar inscricao evento\n\n";
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
            lerApresentadores(apresentadores, contApresentador);
            break;
        }
        case 3:
        {
            lerParticipantes(participantes, contParticipante);
            break;
        }
        case 4:
        {
            lerEventos(eventos, contEvento, contCidade, contApresentador, cidades, apresentadores);
            break;
        }
        case 5:
        {
            exibirUmEvento(eventos, contEvento, cidades, contCidade, apresentadores, contApresentador);
            break;
        }
        case 6:
        {
            exibirEventos(eventos, contEvento, cidades, contCidade, apresentadores, contApresentador);
            break;
        }
        case 7:
        {
            incluirApresentadores(apresentadores, contApresentador, CONTADOR);
            break;
        }
        case 8:
        {
            incluirEventos(eventos, contEvento, CONTADOR, contCidade, contApresentador, cidades, apresentadores);
            break;
        }
        case 9:
        {
            inscricaoEvento(eventos, contEvento, participantes, contParticipante, cidades, contCidade, apresentadores, contApresentador);
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
