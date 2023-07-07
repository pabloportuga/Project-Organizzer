#include "../include/Coluna.h"
#include <iostream>
using namespace std;

Coluna::Coluna(const string &nome): nome(nome), proximaColuna(nullptr), primeiroCartao(nullptr) {}

Coluna::~Coluna() {
  // Lógica para liberar a memória dos nós de cartão
  // Percorre a lista encadeada de cartões e libera a memória
  Cartao *cartaoAtual = primeiroCartao;
  while (cartaoAtual != nullptr) {
    Cartao *proximoCartao = cartaoAtual->obterProximoCartao();
    delete cartaoAtual;
    cartaoAtual = proximoCartao;
  }
}

Coluna *Coluna::obterProximaColuna() { 
    return proximaColuna; 
}
void Coluna::definirProximaColuna(Coluna *proxima) { 
    proximaColuna = proxima; 
}

string Coluna::obterNome(){
    return nome;
}

void Coluna::mostrarColuna() {
  Cartao *cartaoAtual = primeiroCartao;

  while (cartaoAtual != nullptr) {
    cout << "Cartão: " << cartaoAtual->obterTitulo() << endl;
    cout << "Descrição: " << cartaoAtual->obterDescricao() << endl;
    cartaoAtual = cartaoAtual->obterProximoCartao();
  }
}

void Coluna::adicionarCartaoNaColuna(const string& titulo, const string& descricao) {
  Cartao* novoCartao = new Cartao(titulo, descricao);

  // Caso não haja cartões ainda, o novo cartão será o primeiro
  if (!primeiroCartao) {
    primeiroCartao = novoCartao;
  }
  // Caso contrário, percorremos a lista para encontrar o último cartão e adicioná-lo
  else {
    Cartao* cartaoAtual = primeiroCartao;
    while (cartaoAtual->obterProximoCartao() != nullptr) {
      cartaoAtual = cartaoAtual->obterProximoCartao();
    }
    cartaoAtual->definirProximoCartao(novoCartao);
  }
}
Cartao *Coluna::obterPrimeiroCartao(){ return primeiroCartao; }




        