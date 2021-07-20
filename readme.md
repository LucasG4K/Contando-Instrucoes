Contando Instruções
=

Neste pequeno jogo, a proposta e objetivo a ser cumprido é o de percorrer uma matriz NxN qualquer buscando sempre o maior elemento e buscando chegar ao última posição dessa matriz. Para isso devem se obedecer as seguintes regras:


1. **Partir da posição 1x1 da matriz;**

2. **A matriz deve ser percorrida um elemento por vez, podendo este estar imediatamente a direita, imediatamente a esquerda ou abaixo da posição analisada;**

3. **O elemento a ser considerado deve ser sempre o de maior valor entre as comparações feitas;**

4. **Não é permitido voltar em posições previamente percorridas;**

5. **Ao chegar na última linha, o único caminho possível é percorrer cada elemento na linha N até a última coluna;**

6. **Por fim, atingir a posição final NxN da matriz e somar os elementos de cada passo realizado;**

### Exemplo a seguir de uma matriz percorrida conforme o jogo: 

    [ 6]  18    7    8    9    3    1
    [27] [45] [50]   6    5    1    2
     21   32  [44] [35]   0    9   22
     15   11    7  [45]   4   18    7
      4    9  [19] [10]   6   89   11
     23   23  [27]   1   91   77    6
     33   28  [34] [18] [19] [96] [ 1]
     
    Total do caminho -> Valor = 476

### Sobre o desenvolvimento

Tendo isso em mente, foi proposto em aula que desenvolvessemos um algoritmo que fizesse o que foi apresentado acima e a partir disso respondessemos as seguintes perguntas:

- Qual o custo computacional do algoritmo desenvolvido?

- Há mais de uma maneira de resolver esse problema?

- Há algum algoritmo famoso em literatura que resolva isso?

Para isso, o algoritmo foi construído em C++, utilizando o sistema operacional Windows 10 versão 20H2. A compilação pode ser feita por meio do seguinte comando: "g++ main.cpp contador_instrucao.cpp -o run" e em seguida executado usando o comando "run".


### Qual o custo computacional do algoritmo desenvolvido?

Para o cálculo do custo computacional do algoritmo, as constantes que não acompanham variáveis serão descartadas por não impactar efeito ao final do algoritmo.

#### Legenda: 
i = linha

j = coluna

LINES = número máximo de linhas (tomaremos 'n' como notação durante a análise)

COLUMNS = número máximo de colunas (tomaremos 'n' como notação durante a análise)

- **Para gerar uma matriz aleatória:**

Com a função 'numGenerator' em nosso código (linha 11 - contador_instrucao.cpp) podemos gerar números aleatórios e fazer o preenchimento da matriz.

    for (int i = 0; i < LINES; i++) { //2n + 2
        for (int j = 0; j < COLUMNS; j++) { //n × (2n + 2)  = 2n² + 2n
            randomMatrix[i][j] = rand() % 100; //n²
        }
    }

Dessa maneira, com os dois laços de repetição, podemos controlar as linhas(i) e colunas(j) de nossa matriz. O custo do primeiro laço de repetição vale '2n + 2' e o segundo laço, contido no anterior, vale '2n² + 2n'. A linha para números randomizados, por se tratar de uma constante, tem peso de 1 unidade e segue os laços de repetição, resultando em n². Sendo assim, os valores dos laços devem ser somados de modo em que chegamos em: ***2n + 2 + 2n² + 2n + n² = 3n² + 4n + 4***

Portanto, o custo dessa função é: **3n² + 4n**

- **Para imprimir as matrizes**

Com a função 'print' em nosso código (linha 91 - contador_instrucao.cpp) podemos exibir preenchimento da matriz.

    for (int i = 0; i < LINES; i++) { //2n + 2
        for (int j = 0; j < COLUMNS; j++) { 2n² + 2n
            if (randomMatrix[i][j] == 0) printf(" 0  ");
            else printf("%2.d  ", randomMatrix[i][j]);
        } cout << endl; 
    } cout << endl;

Semelhante a análise anterior, fazemos novamente 2 laçoes de repetições para tratar linhas e colunas, e com isso já podemos imprimir os valores respeitando as duas validações impostas acima. Essas validações são com referência ao valor 0, que não era exibido nas ocorrências. Sendo assim a soma dos dois laços de repetição, como visto anteriormente, resulta em 2n² + 4n. Referente ao if e ao else, o custo pode ser descrito como n², em caso de não precisar de uma segunda verificação (else). Caso a segunda verificação seja necessária temos, 2n² e portanto adotaremos o valor médio 1.5n².

Portanto, o custo dessa função é: **3.5n² + 4n**


- **Para percorrer e verificar a matriz gerada**

Com a função 'runner' em nosso código (linha 20 - contador_instrucao.cpp) podemos realizar as jogadas que percorrem toda a matriz de forma a obedecer as regras impostas inicialmente.

Primeiramente, como forma de percorrer qualquer matriz bidimensional (2D), o seguinte laço de repetição, ou algo semelhante, pode aparecer.

    for (int i = 0; i < LINES; i++) //2n + 2
        for (int j = 0; j < COLUMNS; j++) //n × (2n + 2)  = 2n² + 2n

Nesse caso, isso já nos garante, inicialmente um custo computacional 2n² + 4n

Além disso, utilizei uma forma de receber os valores do ponteiro por uma forma de praticidade no momento de verificação dos elementos e uma maneira de exibir e contar os passos realizados.

    right = &matrix[i][j + 1]; //n²
    left = &matrix[i][j - 1];  //n²
    down = &matrix[i + 1][j];  //n²
    current = &matrix[i][j];   //n²

    Imprimir a posição atual //n²
    COUNTER++; //n²

Os 6 elementos acima foram responsáveis por impactar em 6n² no custo do algoritmo.

A partir daqui, entramos especificamente nas validações de matrizes que também estão situadas dentro dos dois laços de repetição apresentados anteriormente.

**Obs: baseado sempre no custo médio**

1. Primeiro IF

    Esse é o melhor caso na análise do algoritmo e é responsável por analisar a primeira linha da matriz. Em seu interior, são analisadas cada coluna referente a linha situada e após a 'decisão' do caminho, é feito o incremento do valor total e seu deslocamento para baixo ou para a direita.

        if (i == 0) { // caso médio: n² × 5 linhas (else está oculto)
            if (*right <= *down || j == COLUMNS - 1) {
                i++; 
                j = j - 1;
            }
            AMOUNT += *current;
            *current = -1;
        }
    
    Caso médio do primeiro IF : n² × 5 = 5n²

2. Segundo IF

    Esse é o caso médio na análise do algoritmo e é responsável por analisar as linhas que vão de i > 0 até n. Em seu interior, são analisadas cada coluna referente a linha situada e após a 'decisão' do caminho, é feito o incremento do valor total e seu deslocamento para baixo ou para os lados.

        else if (i > 0 && i < LINES - 1) { // caso médio: n² × 7 linhas (else está oculto)
            if (j == 0) {
                if (*right <= *down) {
                    i++;
                    j = j - 1;
                }
                AMOUNT += *current;
                *current = -1;
            }

            else if (j == COLUMNS - 1) { // caso médio: n² × 7 linhas (else está oculto)
                if (*left > *down) {
                    j = j - 2;
                } else if (*down >= *left) {
                    i++;
                    j = j - 1;
                }
                AMOUNT += *current;
                *current = -1;
            }

            else if (j > 0 && j < COLUMNS - 1) { // caso médio: n² × 9 linhas (else está oculto)
                if (*left <= *down && *down >= *right) {
                    i++;
                    j = j - 1;
                } else if (*right < *left && *left > *down) {
                    j = j - 2;
                }
                AMOUNT += *current;
                *current = -1;
            }
        }

    Caso médio do segundo IF : 7n² + 7n²  = 14n²



3. Terceiro IF

    Esse é o pior caso na análise do algoritmo e é responsável por analisar a última linha da matriz. Em seu interior, são analisadas cada coluna referente a linha situada e após a 'decisão' do caminho, é feito o incremento do valor total e seu deslocamento para a direita.

    Esse é o pior caso na análise do algoritmo

        else if (i == LINES - 1) { //n² * 3 linhas
            AMOUNT += *current;
            *current = -1;
        }

    Caso médio do terceiro IF : 3n²


- **Resultado total final**

Sabendo que todos os 3 IFs anteriores serão percorridos em algum momento, todos eles devem ser considerados.

Sendo assim, somando os custos assintóticos de cada função apresentada acima, chegamos ao seguinte resultado: 

3n² + 4n + 3.5n² + 4n + 5n² + 14n² + 3n² = 28.5n² + 8n

Porém, por n² ser o elemento de maior peso durante os cálculos realizados, podemos definir que o custo computacional para esse algoritmo é de aproximadamente 28.5n².


### Há mais de uma maneira de resolver esse problema?

Existem sim formas de se resolver o problema proposto com alterações ínfimas na estrutura do código apresentado, porém não há maneiras de fugir do problema fundamental que é a operação de matrizes e suas validações em cada caso. Sendo assim, por mais que se tente moldar um tipo de grafo, ou alguma outra forma possível que conhecemos hoje, é fundamental que se utilize uma estrutura de matriz bidimensional e que essa possa ser manipulada.


### Há algum algoritmo famoso em literatura que resolva isso?

Se baseando em estrutura de grafos, existem 3 nomes famosos que desenvolveram algoritmos similares e portanto podem ser uma boa base de pesquisa na hora de resolver este problemas. São eles: 

- Edsger W. Dijkstra
- Bellman-Ford
- Floyd-Warshal

Todos os autores tomam estruturas de grafo semelhante ao comportamento de árvores binárias para tomar a decisão entre os caminhos possíveis.