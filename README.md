Informações do projeto para compor a nota da 3° Unidade da matéria IMD0030 - LINGUAGEM DE PROGRAMAÇÃO I - T02 (2023.1).

Autor: Pablo Soares Portugal - 20220041090.

Nome: ORGANIZZER - Quadro Kanban.

Ideia geral: O ORGANIZZER é um programa que permite aos usuários organizar suas tarefas diárias em uma interface com formato de listas, baseada no conceito de Quadro Kanban.


Especificações dos arquivos:

Quadro: Essa classe é a base de todo o projeto, ela tem como único atributo um porteiro para a primeira coluna, que foi implementada como uma lista simplesmente encadeada. Sua principal função é criar, editar ou excluir colunas, além de identificá-las.


Classe Coluna: A classe Coluna possui três atributos: nome (identificação da coluna), proximaColuna (referência para a próxima coluna, utilizando uma lista encadeada) e primeiroCartao (ponteiro para o primeiro cartão, também implementado como uma lista simplesmente encadeada). Sua função principal é criar, editar ou excluir cartões, bem como identificá-los ou ordená-los. Atualmente, o algoritmo de ordenação Bubble Sort está disponível.

Ideias futuras: Planejamos adicionar mais dois algoritmos de ordenação auxiliares: um baseado em prioridade (como Urgente, Normal e Baixa) e outro baseado no tamanho dos cartões.
  
Cartao: A classe Cartao também possui três atributos: título, descrição (que funcionam como identificadores dos cartões)  e um ponteiro proximoCartao, caracterizando o uso da lista encadeada. É nessa classe que as informações do usuário serão mantidas. 


Instalação: 
1. Baixe ou clone o repositório;
2. O makefile permite fácil instalação, use: "make && cd bin && ./Organizzer" para executar o programa.