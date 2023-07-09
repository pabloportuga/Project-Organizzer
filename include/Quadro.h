#ifndef	QUADRO_H
#define QUADRO_H

#include "Coluna.h"
using namespace std;

class Quadro {
private:
  Coluna *primeiraColuna;

public:
  Quadro();
  ~Quadro(void);

  void adicionarColuna(const string &nome);
  //Falta remover coluna
  void mostrarQuadro();
  //Falta obter primeira coluna e definir primeira coluna

  Coluna *obterColuna(const string &nomeColuna);

  void adicionarCartao(const string &titulo, const string &descricao, const string &nomeColuna);

  void localizarColunasMover(const string &titulo, const string &nomeColuna);

  Coluna *obterColunaComCartao(const string &titulo);

  void obterColunaOrdenar(const string &nomeColuna);

};
#endif