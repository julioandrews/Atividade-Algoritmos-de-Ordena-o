# Atividade-Algoritmos-de-Ordenação

BubbleSort e QuickSort têm abordagens bem diferentes entre si. O BubbleSort é um algoritmo simples que compara elementos adjacentes e os troca até que a lista esteja ordenada. Em troca de ser fácil de implementar, seu tempo de execução é ineficiente para grandes conjuntos de dados, com complexidade O(n²), o que o torna inadequado para listas maiores.

Já o QuickSort é um algoritmo eficiente, com complexidade média O(n log n), que utiliza o conceito de dividir e conquistar. Sua eficiência depende da escolha do pivô, um elemento em torno do qual a lista será dividida. A escolha do pivô é crucial para o desempenho do QuickSort. Se o pivô for bem escolhido, o algoritmo pode realizar a ordenação de maneira rápida, dividindo a lista em duas partes quase iguais. Caso contrário, como em casos onde o pivô é sempre o menor ou maior elemento, o QuickSort pode degradar para O(n²), similar ao BubbleSort.

Por causa disso, a estratégia de escolha do pivô que implementei foi o método "mediana dos três", onde são considerados os valores do primeiro, meio e último elemento da lista. O pivô será a mediana desses três valores, resultando em uma divisão mais equilibrada da lista e reduzindo a probabilidade de um desempenho ruim.
