#include "../include/Cartao.h"
using namespace std;

Cartao::Cartao(const string& titulo, const string& descricao) : titulo(titulo), descricao(descricao) {}


string Cartao::obterTitulo() {
    return titulo;
}

string Cartao::obterDescricao() {
    return descricao;
}

Cartao* Cartao::obterProximoCartao(){
    return proximoCartao;
}

void Cartao::definirProximoCartao(Cartao* proximo) {
    proximoCartao = proximo;
}
