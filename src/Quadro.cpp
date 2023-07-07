#include "../include/Quadro.h"
#include <iostream>
using namespace std;

Quadro::Quadro() : primeiraColuna(nullptr) {}

// Faltou o destrutor
Quadro::~Quadro(void){
    // Lógica para liberar a memória dos nós de coluna e cartão
    // Percorre a lista encadeada de colunas e libera a memória
    Coluna* colunaAtual = primeiraColuna;
    while (colunaAtual != nullptr) {
        Coluna* proximaColuna = colunaAtual->obterProximaColuna();
        delete colunaAtual;
        colunaAtual = proximaColuna;
    }
}

void Quadro::adicionarColuna(const string& nome) {
    Coluna* novaColuna = new Coluna(nome);

    // Lógica para adicionar a nova coluna ao quadro

    // Caso não haja colunas ainda, a nova coluna será a primeira
    if (!primeiraColuna) {
        primeiraColuna = novaColuna;
    }
    // Caso contrário, percorremos a lista para encontrar a última coluna e adicioná-la
    else {
        Coluna* colunaAtual = primeiraColuna;
        while (colunaAtual->obterProximaColuna() != nullptr) {
            colunaAtual = colunaAtual->obterProximaColuna();
        }
        colunaAtual->definirProximaColuna(novaColuna);
    }
}


void Quadro::mostrarQuadro() {
    cout << "--------Quadro--------" << std::endl << std::endl;
    Coluna* colunaAtual = primeiraColuna;

    while (colunaAtual != nullptr) {
        cout << " Coluna: " << colunaAtual->obterNome() << endl;
        colunaAtual->mostrarColuna();  // Chama a função mostrarColuna() da classe Coluna para exibir os cartões
        cout << endl;
        colunaAtual = colunaAtual->obterProximaColuna();
    }
    cout << "----------------------------" << endl;
}

Coluna* Quadro::obterColuna(const string& nomeColuna) {
  Coluna* colunaAtual = primeiraColuna;
  while (colunaAtual != nullptr) {
    if (colunaAtual->obterNome() == nomeColuna) {
      return colunaAtual;
    }
    colunaAtual = colunaAtual->obterProximaColuna();
  }
  return nullptr;  // Retorna nullptr se a coluna não for encontrada
}

void Quadro::adicionarCartao(const string& titulo, const string& descricao, const string& nomeColuna) {
  Coluna* colunaDestino = obterColuna(nomeColuna);

  if (colunaDestino != nullptr) {
    colunaDestino->adicionarCartaoNaColuna(titulo, descricao);
	}
	else{
		cout << "A Coluna não existe!";
	}
}


void Quadro::localizarColunasMover(const string &titulo, const string &nomeColunaDestino){
    Coluna *colunaDestino = obterColuna(nomeColunaDestino);
    Coluna *colunaOrigem = obterColunaComCartao(titulo);
      
      if (colunaOrigem != nullptr && colunaDestino != nullptr) {
        colunaOrigem->moverCartao(titulo, colunaDestino);
        std::cout << "Cartão movido com sucesso!" << std::endl;
      } else {
        std::cout << "Cartão ou coluna não encontrados!" << std::endl;
      }
  }

Coluna* Quadro::obterColunaComCartao(const string &titulo){
    Coluna* colunaAtual = primeiraColuna;
    while(colunaAtual!= nullptr){
        if(colunaAtual->obterCartao(titulo)!=nullptr){
            return colunaAtual;
        }
        colunaAtual = colunaAtual->obterProximaColuna();
    }
    return nullptr;
}