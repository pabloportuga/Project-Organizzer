#include "../include/Quadro.h"
#include <iostream>
using namespace std;

void exibirMenu() {
  cout << "------ MENU ------" << endl;
  cout << "1. Criar nova coluna" << endl;
  cout << "2. Criar novo cartão" << endl;
  cout << "3. Mover cartão" << endl;
  cout << "4. Mostrar quadro" << endl;
  cout << "5. EXIT" << endl;
  cout << "------------------" << endl;
  cout << "Digite o comando: ";
}

int main() {
  Quadro quadro;
  int comando = 0;

  cout << "Inicializando colunas padrão" << endl;
  quadro.adicionarColuna("A fazer");
  quadro.adicionarColuna("Em andamento");
  quadro.adicionarColuna("Concluída");

  while (comando != 5) {
    exibirMenu();
    cin >> comando;
    switch (comando) {
    case 1: {
      string nomeColuna;
      cout << "Digite o nome da nova coluna: ";
      cin.ignore();
      getline(cin, nomeColuna);
      quadro.adicionarColuna(nomeColuna);
      break;
    }
    case 2: {
      string titulo, descricao, nomeColuna;
      cout << "Digite o título do novo cartao: ";
      cin.ignore();
      getline(cin, titulo);

      cout << "Digite a descrição do novo cartao: ";
      getline(cin, descricao);

      cout << "Digite o nome da coluna onde deseja adicionar o cartao: ";
      getline(cin, nomeColuna);
      quadro.adicionarCartao(titulo, descricao, nomeColuna);
      break;
    }
    case 3: {
      string tituloMover;
      string moverParaColuna;
      cout << "Digite o título do cartão a ser movido: ";
      cin.ignore();
      getline(cin, tituloMover);
      cout << "Digite o nome da coluna de destino: ";
      getline(cin, moverParaColuna);

      quadro.localizarColunasMover(tituloMover, moverParaColuna);
      break;
    }

    case 4: {
      quadro.mostrarQuadro();
      break;
    }
    case 5: {
      cout << "Encerrando o programa..." << endl;
      break;
    }
    case 6: {
      string nomeColuna;
      cout << "Qual coluna você quer ordenar?" << endl;
      getline(cin, nomeColuna);
      //ordenarCartao(nomeColuna); // implementar
      break;
    }
    default: {
      cout << "Comando inválido. Digite um número válido do menu." << endl;
      break;
    }
    }
    cout << endl;
  }
  return 0;
}