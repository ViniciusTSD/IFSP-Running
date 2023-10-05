# IFSP Running
## Questão resolvida durante meu período no IFSP Araraquara - simulação de sistema para gerenciar uma prova de corrida

Suponha que o IFSP Campus Araraquara está organizando uma Prova de Corrida (IFSP Running 2023 – Etapa Araraquara) e você deve implementar um programa em C para receber os dados dos corredores(as). Cada corredor(a) possui os seguintes dados:

• Número de peito (sequencial e gerado pelo programa) • Nome • Idade • Sexo (masculino ou feminino) • Tempo de prova (em minutos)

O programa deve:

a) Definir um tipo registro (struct) para armazenar os dados de cada corredores(as) e um vetor para armazenar os dados de todos, corredores e corredoras.

b) Na função main, apresentar o menu de opções abaixo até o usuário decidir encerrar o programa. O menu deve ser implementado em uma função:

Cadastrar corredor(a)
Consultar os dados de corredor(a) pelo número de peito
Consultar os dados de corredor(a) pelo nome
Gerar relatório de classificação
Calcular a média do tempo de prova entre todos corredores e corredoras
Apresentar a quantidade de corredores(as) acima dos 60 anos e a média do tempo de prova deles(as)
Apresentar a quantidade de mulheres e a média de idade delas
Sair
c) Implementar uma função para cadastrar os dados de um corredor(a) por vez.

d) Implementar uma função para pesquisar um corredor(a) usando seu número de peito. Se localizar, os dados do corredor(a) devem ser apresentados, senão uma mensagem deve informar que o corredor(a) não foi localizado.

e) Implementar uma função para pesquisar um corredor(a) usando seu nome. Se localizar, os dados do corredor(a) devem ser apresentados, senão uma mensagem deve informar que o corredor(a) não foi localizado(a).

f) Implementar uma função para gerar o relatório de classificação. A classificação é crescente, do melhor tempo para o pior tempo.

g) Implementar uma função para calcular a média do tempo de prova entre todos os corredores(as).

h) Implementar uma função para determinar e apresentar a quantidade de corredores(as) acima dos 60 anos e a média do tempo de prova deles(as).

i) Implementar uma função para determinar e apresentar a quantidade de corredoras (mulheres) e a média do tempo de prova delas.
