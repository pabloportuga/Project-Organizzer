#include "../include/Quadro.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

void exibirMenu() {
  cout << "------------------ MENU ------------------" << endl;
  cout << "1. Criar nova coluna" << endl;
  cout << "2. Criar novo cartão" << endl;
  cout << "3. Mover cartão" << endl;
  cout << "4. Mostrar quadro" << endl;
  cout << "5. Ordenar cartões em ordem alfabética" << endl;
  cout << "6. Remover coluna" << endl;
  cout << "7. Remover cartão" << endl;
  cout << "8. EXIT" << endl;
  cout << "------------------------------------------" << endl;
  cout << "Digite o comando: ";
}

int main() {
  Quadro quadro;
  int comando = 0;
  string entrada;

  while (comando != 8) {
    exibirMenu();
    cin >> entrada;
    try {        
      comando = std::stoi(entrada);  // Tenta converter a string em um número inteiro
    } catch (...) {
      cout << "Entrada inválida. Digite um número.\n";
      cin.clear();  // Limpa a flag de erro de entrada
      cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta o restante da linha inválida
      continue;  // Volta ao início do loop
    }
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
      string nomeColuna;
      cout << "Qual coluna você quer ordenar? ";
      cin.ignore();
      getline(cin, nomeColuna);
      quadro.obterColunaOrdenar(nomeColuna);
      break;
    }
  case 6:{
    string nomeColuna;
    cout << "Qual o nome da coluna você quer remover: ";
    cin.ignore();
    getline(cin, nomeColuna);
    quadro.removerColuna(nomeColuna);
    break;
  }
  case 7:{
    string nomeColuna;
    string titulo;
    cout << "Em qual coluna você quer remover o cartão: ";
    cin.ignore();
    getline(cin, nomeColuna);
    cout << "Qual cartão você quer remover? ";
    getline(cin, titulo);
    quadro.removerCartaoColuna(titulo, nomeColuna);
    break;

  }
  case 8: {
    cout << "Encerrando o programa..." << endl;
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