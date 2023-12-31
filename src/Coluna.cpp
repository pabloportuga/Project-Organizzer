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
    cout << "   Cartão: " << cartaoAtual->obterTitulo() << endl;
    cout << "   Descrição: " << cartaoAtual->obterDescricao() << endl;
    cout << endl;
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

Cartao *Coluna::obterCartao(const string &titulo){
  Cartao *cartaoAtual = obterPrimeiroCartao(); // errado?
  while(cartaoAtual!=nullptr){
    if(titulo == cartaoAtual->obterTitulo()){
      return cartaoAtual;
    }
    cartaoAtual = cartaoAtual->obterProximoCartao();
  } 
  return nullptr;
}


void Coluna::moverCartao(const string &titulo, Coluna *colunaDestino) {
  Cartao *cartaoAtual = primeiroCartao;
  Cartao *cartaoAnterior = nullptr;

  // Percorre a lista encadeada de cartões
  while (cartaoAtual != nullptr) {
    if (cartaoAtual->obterTitulo() == titulo) {
      // Encontrou o cartão a ser movido

      if (cartaoAnterior == nullptr) {
        // O cartão a ser movido é o primeiro cartão da coluna
        primeiroCartao = cartaoAtual->obterProximoCartao();
      } else {
        // O cartão a ser movido não é o primeiro cartão
        cartaoAnterior->definirProximoCartao(cartaoAtual->obterProximoCartao());
      }

      // Insere o cartão no final da coluna de destino
      if (colunaDestino != nullptr) {
        cartaoAtual->definirProximoCartao(nullptr);

        Cartao *ultimoCartao = colunaDestino->obterPrimeiroCartao();
        if (ultimoCartao == nullptr) {
          colunaDestino->definirPrimeiroCartao(cartaoAtual);
        } else {
          while (ultimoCartao->obterProximoCartao() != nullptr) {
            ultimoCartao = ultimoCartao->obterProximoCartao();
          }
          ultimoCartao->definirProximoCartao(cartaoAtual);
        }
      }
      return;
    }
    cartaoAnterior = cartaoAtual;
    cartaoAtual = cartaoAtual->obterProximoCartao();
  }
}

void Coluna::definirPrimeiroCartao(Cartao *cartao) { primeiroCartao = cartao; }

void Coluna::ordenarCartao() {
  if (primeiroCartao == nullptr || primeiroCartao->obterProximoCartao() == nullptr) {
    // Não há cartões suficientes para ordenar
    return;
  }

  bool trocou = true;
  while (trocou) {
    trocou = false;
    Cartao *atual = primeiroCartao;
    while (atual->obterProximoCartao() != nullptr) {
      Cartao *proximo = atual->obterProximoCartao();
      if (atual->obterTitulo() > proximo->obterTitulo()) {
        // Troca os cartões de posição
        Cartao *aux = proximo->obterProximoCartao();
        atual->definirProximoCartao(aux);
        proximo->definirProximoCartao(atual);
        if (atual == primeiroCartao) {
          primeiroCartao = proximo;
        } else {
          Cartao *anterior = primeiroCartao;
          while (anterior->obterProximoCartao() != atual) {
            anterior = anterior->obterProximoCartao();
          }
          anterior->definirProximoCartao(proximo);
        }
        trocou = true;
      } else {
        atual = proximo;
      }
    }
  }
}

void Coluna::removerCartao(const string &titulo){
  Cartao *cartaoAtual = primeiroCartao;
  Cartao *cartaoAnterior = nullptr;

  while(cartaoAtual!=nullptr){
    if(cartaoAtual->obterTitulo() == titulo){
      if(cartaoAnterior == nullptr){
        primeiroCartao = cartaoAtual->obterProximoCartao();
      }
      else{
        cartaoAnterior->definirProximoCartao(cartaoAtual->obterProximoCartao());
      }
      delete cartaoAtual;
      cout << "Cartão removido com sucesso!" << endl;
      return;
    }

    cartaoAnterior = cartaoAtual;
    cartaoAtual = cartaoAtual->obterProximoCartao();

  }
  cout << "Não existe cartão com esse título nessa coluna." << endl;
}

