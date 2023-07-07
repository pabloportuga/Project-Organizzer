Informações do projeto para compor a nota da 3° Unidade da matéria IMD0030 - LINGUAGEM DE PROGRAMAÇÃO I - T02 (2023.1).

Autor: Pablo Soares Portugal - 20220041090.

Data: 16/06/2023.


Nome: ORGANIZZER.
Referência: Quadro Kanban.
Ideia geral: Um programa que organiza as tarefas do dia a dia do usuário numa interface em formato de listas.


Especificações dos arquivos:
Quadro.cpp: Essa classe vai contar com 3 colunas: "A fazer", "Em andamento" e "Concluída", cada bloco será a cabeça de uma lista de cartões, ela será implementada usando uma estrutura de listas encadeadas.

Coluna.cpp: Essa classe vai ser criada usando o conceito de Herança através da lista primária, entretanto sua estrutura será em formato de lista duplamente encadeada, isso se deve principalmente pelo nível de complexidade que ela permite quando existe a necessidade de inserções ou remoções constantes dos elementos. Usaremos também 4 algoritmos de ordenação auxiliares: alfabética, prioridade(Urgente, normal, baixa), quantidade de acessos, acessada recentemente.
   
Cartao.cpp: Essa classe vai conter dados juntamente como métodos como criar, excluir e modificar dados em uma estrutura de TADs em forma de pinha, dando prioridade para acessos recentes.
