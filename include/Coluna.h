#ifndef COLUNA_H
#define COLUNA_H
#include "Cartao.h"
#include <string>
using namespace std;

class Coluna {
private:
  string nome;
  Coluna *proximaColuna;
  Cartao *primeiroCartao;

public:
  Coluna(const string &nome);
  
  ~Coluna(void);
  
  Coluna *obterProximaColuna();
  
  void definirProximaColuna(Coluna *proxima);
  
  string obterNome();

  void mostrarColuna();

  void adicionarCartaoNaColuna(const string& titulo, const string& descricao);
  Cartao *obterPrimeiroCartao();
};

#endif