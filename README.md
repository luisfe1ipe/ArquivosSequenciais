Escreva um programa para criar as seguintes estruturas que simularão arquivos sequenciais para uma aplicação para o Gerenciamento de Eventos:

Cidade do Evento: codigo, nome, UF

Apresentadores: codigo, nome

Eventos: codigo, descrição, codigo_cidade, codigo_apresentador, qtde de Participantes, limite de participantes, preço unitário

Participantes: codigo, nome, codigo_evento

1) Escreva funções específicas para a leitura dos dados das estruturas.

2) Escreva uma função para permitir a inclusão de novos registros na tabela de Apresentadores. 

3) Escreva uma função para permitir a inclusão de novos registros na tabela de Eventos.

3.1) Quando o usuário digitar o código da cidade, o programa deverá buscar este código na tabela de Cidades e exibir o nome e a UF da cidade.

3.2) Quando o usuário digitar o código do apresentador, o programa deverá buscar este código na tabela de Apresentadores e exibir o nome do apresentador.

4) Escreva uma função para permitir que uma pessoa realize a inscrição para participação de um evento.

4.1) O usuário deverá informar o código do evento que deseja se inscrever e o programa deverá buscar este código na tabela de Eventos e exibir a descrição do evento, o nome da cidade do evento e o nome do apresentador do evento.

4.2) O programa deverá verificar na tabela de Eventos se ainda há vagas disponíveis para inscrição (a quantidade de participantes deverá ser menor do que a quantidade limite de participantes).

Se houver vagas para novas inscrições:

4.2.1) Solicitar o código do participante que deseja fazer a inscrição e exibir o nome do participante;

4.2.2) O programa deverá gravar o código do evento na tabela de Participantes;

4.2.3) O programa deverá acrescentar uma unidade na qtde de Participantes da tabela de Eventos.

Se não houver vagas para novas inscrições, o programa deverá emitir uma mensagem dizendo que o evento não possui vagas para novas inscrições.

5) Escreva uma função para permitir ao usuário consultar os dados de determinado evento. 

5.1) Para cada evento consultado, exibir: todos os seus dados, o nome da cidade do evento, o nome do apresentador do evento, e o valor total do evento (qtde de Participantes * preço unitário).

6) Escreva uma função para mostrar todos os eventos que estão sendo organizados. O programa deverá exibir: nome do evento, nome da cidade, nome do apresentador, quantidade de participantes e o valor do evento (qtde de Participantes * preço unitário).

Ao final dessa função, mostrar o valor total de todos os eventos.


Todas as funções descritas acima deverão ser chamadas através de um menu de opções que será chamado a partir da função main().

Obs: não utilizar variáveis globais.

