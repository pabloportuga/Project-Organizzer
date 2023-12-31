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


  void removerColuna(const string &nomeColuna);

  void mostrarQuadro();

  Coluna *obterColuna(const string &nomeColuna);

  void adicionarCartao(const string &titulo, const string &descricao, const string &nomeColuna);

  void localizarColunasMover(const string &titulo, const string &nomeColuna);

  Coluna *obterColunaComCartao(const string &titulo);

  void obterColunaOrdenar(const string &nomeColuna);

  void removerCartaoColuna(const string &titulo, const string nomeColuna);

};
#endif