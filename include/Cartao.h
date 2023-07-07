#ifndef CARTAO_H
#define CARTAO_H
#include <string>
using namespace std;

class Cartao {
private:
  string titulo;
  string descricao;
  Cartao *proximoCartao; // Ponteiro para o próximo cartão

public:
  Cartao(const string &titulo, const string &descricao);
  
  string obterTitulo();
  string obterDescricao();
  Cartao *obterProximoCartao(); // Novo método para obter o ponteiro do próximo cartão
  void definirProximoCartao(Cartao *proximo); // Novo método para definir o próximo cartão
};
#endif // CARTAO_H