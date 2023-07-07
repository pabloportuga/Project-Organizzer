#include <iostream>
#include "../include/Quadro.h"
using namespace std;


int main(){
	Quadro quadro;

	quadro.adicionarColuna("A fazer");
	quadro.adicionarColuna("Em andamento");
	quadro.adicionarColuna("Concluída");

	string titulo = "Almoço";
	string descricao = "Cozinhar os alimentos e depois lavar a louça";
	string nomeColuna = "A fazer";

	string titulo2 = "Estudar FMC1";
	string descricao2 = "Resolver todos os exercícios dos 3 últimos conteúdos";
	string nomeColuna2 = "Em andamento";

	string titulo3 = "Concluir o projeto";
	string descricao3 = "Codar todos os requisitos do projeto!";
	string nomeColuna3 = "Concluída";

	quadro.adicionarCartao(titulo, descricao, nomeColuna);
	quadro.adicionarCartao(titulo2, descricao2, nomeColuna2);
	quadro.adicionarCartao(titulo3, descricao3, nomeColuna3);
	
	string tituloMover = "Almoço";
	string moverParaColuna = "Concluída";

	quadro.localizarColunasMover(tituloMover, moverParaColuna);

    quadro.mostrarQuadro();
	return 0;
}