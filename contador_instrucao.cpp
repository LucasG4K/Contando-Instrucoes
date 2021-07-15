#include "contador_instrucao.hpp"

int ContadorInstrucao::SOMATORIO = 0;

int numGenerator(int randomMatrix[][COLUMNS]) {
    srand(time(NULL));
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            randomMatrix[i][j] = rand() % 100;
        }
    }
}


void runner(int matrix[][COLUMNS]) {
    int aux = 0; //auxiliar de coluna => pega valor anterior de j
    int counter = 0;
    int* direita;
    int* esquerda;
    int* baixo;
    int* atual;

    for (int i = 0; i < LINES; i++) {
        cout << endl;
        for (int j = 0; j < COLUMNS; j++) {

            direita = &matrix[i][j + 1];
            esquerda = &matrix[i][j - 1];
            baixo = &matrix[i + 1][j];
            atual = &matrix[i][j];

            //feito
            if (i == 0) {
                if (*direita < *baixo && j < COLUMNS - 1) { //se direita < baixo => baixo
                    cout << "if1.1 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                    counter += *atual;
                    *atual = -1; //-> add por ultimo
                    i++;
                }
                else if (*direita > *baixo && j < COLUMNS - 1) { //se baixo < direita => direita
                    cout << "if1.2 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                    counter += *atual;
                    *atual = -1; //-> add por ultimo

                } else if (j == COLUMNS - 1) { //se j = max => desce e j = maximo
                    counter += *baixo;
                    cout << "if1.3 matriz matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                    *baixo = -1; //-> add por ultimo
                    i++;
                    j = COLUMNS - 1;
                    cout << "i: " << i << " - j: " << j << endl;
                }
            }

            //a fazer
            else if (i > 0 && i < LINES - 1) {
                //validar j = 0;
                if (j == 0) { //se coluna = 0
                    if (*direita < *baixo) { //se direita < baixo => baixo
                        cout << "if2.1 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        counter += *baixo;
                        *baixo = -1; //-> add por ultimo
                        i++;
                    }
                    if (*baixo < *direita) { //se direita < baixo => baixo
                        cout << "if2.2 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        counter += *direita;
                        *direita = -1; //-> add por ultimo
                    }
                }
                else if (j == COLUMNS - 1) { //se coluna = max
                    if(*esquerda > *baixo) { //se esquerda > baixo => esquerda
                        cout << "if2.3 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        counter += *esquerda;
                        *esquerda = -1; //-> add por ultimo
                    } else if (*baixo > *esquerda) { //se baixo > esquerda => baixo
                        cout << "if2.4 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        counter += *baixo;
                        *baixo = -1; //-> add por ultimo
                        j = COLUMNS - 1;
                    }
                }
                else if (j > 0 && j < COLUMNS - 1) {
                    if (*direita < *baixo && *baixo > *esquerda) { //se direita < baixo e baixo > esquerda  => baixo
                        cout << "if2.5 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        counter += *baixo;
                        *baixo = -1; //-> add por ultimo
                        i++;
                    }
                    else if (*baixo < *direita && *direita > *esquerda) { //se baixo < direita e direita > esquerda => direita
                        counter += *atual;
                        cout << "if2.6 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        *atual = -1; //-> add por ultimo
                    }
                    else if (*direita < *esquerda && *esquerda > *baixo) { //se direita < esquerda e esquerda > baixo => esquerda
                        counter += *esquerda;
                        cout << "if2.7 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        *esquerda = -1; //-> add por ultimo
                    }
                }
            }

            else if (i == LINES - 1) {
                if (j < COLUMNS - 1) {
                    counter += *direita;
                    cout << "if3.1 matriz: [" << i << "]" << "[" << j << "] = " << *atual<< endl;
                    *direita = -1; //-> add por ultimo
                }
                else {
                    counter += *atual;
                    cout << "if3.2 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                    *atual = -1; //-> add por ultimo
                }
            }

            //else if (i )
        //     } else if (i == LINES && j < COLUMNS) {
        //         cout << "if6.1 matriz: [" << i << "]" << "[" << j << "] = " << * << endl;
        //         counter += matrix[i][j];
        //     }

        //     else if(i == LINES && j == COLUMNS) {
        //         cout << "Chegou!!! [" << i << "]" << "[" << j << "] = " << * << endl;
        //         counter += matrix[i][j];
        //     }
        //     //else cout << "Matriz nao e' capaz de ser percorrida conforme a regra" << endl;
        }
    }
    cout << endl << "Total do caminho = " << counter;
}




void print(int randomMatrix[][COLUMNS]) {
    cout << endl;
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%2.d  ", randomMatrix[i][j]);
        }
        cout << endl;
    }
}

int main() {
    //int matrix[LINES][COLUMNS];
    int matrix[7][7] = { {6,18,7,8,9,3,1}, {27,45,50,6,5,1,2}, {21,32,44,35,0,9,22}, {15,11,7,45,4,18,7}, {4,9,19,10,6,89,11}, {23,23,27,1,91,77,6}, {33,28,34,18,19,96,1} };
    //int matrix[3][3] = {{1,2,3}, {1,2,1}, {3,5,2}};
    //numGenerator(matrix);
    print(matrix);
    runner(matrix);
    print(matrix);
    return 0;
}