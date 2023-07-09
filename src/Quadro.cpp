#include "../include/Quadro.h"
#include <iostream>
using namespace std;

Quadro::Quadro() : primeiraColuna(nullptr) {}

// Faltou o destrutor
Quadro::~Quadro(void) {
  // Lógica para liberar a memória dos nós de coluna e cartão
  // Percorre a lista encadeada de colunas e libera a memória
  Coluna *colunaAtual = primeiraColuna;
  while (colunaAtual != nullptr) {
    Coluna *proximaColuna = colunaAtual->obterProximaColuna();
    delete colunaAtual;
    colunaAtual = proximaColuna;
  }
}

void Quadro::adicionarColuna(const string &nome) {
  Coluna *novaColuna = new Coluna(nome);
  

  // Lógica para adicionar a nova coluna ao quadro

  // Caso não haja colunas ainda, a nova coluna será a primeira
  if (!primeiraColuna) {
    primeiraColuna = novaColuna;
  }
  // Caso contrário, percorremos a lista para encontrar a última coluna e
  // adicioná-la
  else {
    Coluna *colunaAtual = primeiraColuna;
    while (colunaAtual->obterProximaColuna() != nullptr) {
      if(colunaAtual->obterNome() == novaColuna->obterNome()){
        cout << "Já existe uma coluna com esse nome." << endl;
        return;
      }
      colunaAtual = colunaAtual->obterProximaColuna();
    }
    colunaAtual->definirProximaColuna(novaColuna);
  }
  cout << "Coluna criada com sucesso!" << endl;
}

void Quadro::mostrarQuadro() {
  cout << "-----------Quadro-----------" << endl << endl;
  Coluna *colunaAtual = primeiraColuna;

  while (colunaAtual != nullptr) {
    cout << " Coluna: " << colunaAtual->obterNome() << endl;
    colunaAtual->mostrarColuna(); // Chama a função mostrarColuna() da classe
                                  // Coluna para exibir os cartões
    cout << endl;
    colunaAtual = colunaAtual->obterProximaColuna();
  }
  cout << "----------------------------" << endl;
}

Coluna *Quadro::obterColuna(const string &nomeColuna) {
  Coluna *colunaAtual = primeiraColuna;
  while (colunaAtual != nullptr) {
    if (colunaAtual->obterNome() == nomeColuna) {
      return colunaAtual;
    }
    colunaAtual = colunaAtual->obterProximaColuna();
  }
  return nullptr; // Retorna nullptr se a coluna não for encontrada
}

void Quadro::adicionarCartao(const string &titulo, const string &descricao,
                             const string &nomeColuna) {
  Coluna *colunaDestino = obterColuna(nomeColuna);

  if (colunaDestino != nullptr) {
    colunaDestino->adicionarCartaoNaColuna(titulo, descricao);
    cout << "Cartão adicionado com sucesso!" << endl;
  } else {
    cout << "A Coluna não existe!" << endl;
  }
}

void Quadro::localizarColunasMover(const string &titulo,
                                   const string &nomeColunaDestino) {
  Coluna *colunaDestino = obterColuna(nomeColunaDestino);
  Coluna *colunaOrigem = obterColunaComCartao(titulo);

  if (colunaOrigem != nullptr && colunaDestino != nullptr) {
    colunaOrigem->moverCartao(titulo, colunaDestino);
    cout << "Cartão movido com sucesso!" << endl;
  } else {
    cout << "Cartão ou coluna não encontrados!" << endl;
  }
}

Coluna *Quadro::obterColunaComCartao(const string &titulo) {
  Coluna *colunaAtual = primeiraColuna;
  while (colunaAtual != nullptr) {
    if (colunaAtual->obterCartao(titulo) != nullptr) {
      return colunaAtual;
    }
    colunaAtual = colunaAtual->obterProximaColuna();
  }
  return nullptr;
}

void Quadro::obterColunaOrdenar(const string &nomeColuna){
  Coluna *colunaAtual = obterColuna(nomeColuna);
  colunaAtual->ordenarCartao();
  cout << "Coluna ordenada com sucesso!";
}

void Quadro::removerColuna(const string &nomeColuna) {
  Coluna *colunaAtual = primeiraColuna;
  Coluna *colunaAnterior = nullptr;
  
  while (colunaAtual != nullptr) {
    if (colunaAtual->obterNome() == nomeColuna) {
      if (colunaAnterior == nullptr) {
        primeiraColuna = colunaAtual->obterProximaColuna();
      } else {
        colunaAnterior->definirProximaColuna(colunaAtual->obterProximaColuna());
      }
      
      delete colunaAtual;
      cout << "Coluna removida com sucesso!" << endl;
      return;
    }
    
    colunaAnterior = colunaAtual;
    colunaAtual = colunaAtual->obterProximaColuna();
  }
  
  cout << "Não existe coluna com esse nome." << endl;
}

void Quadro::removerCartaoColuna(const string &titulo, const string nomeColuna){
  Coluna *colunaDestino = obterColuna(nomeColuna);
  colunaDestino->removerCartao(titulo);
}



