#include "contador_instrucao.hpp"

int ContadorInstrucao::SOMATORIO = 0;

int ContadorInstrucao::getSomatorio() {return SOMATORIO;}

int ContadorInstrucao::numGenerator(int randomMatrix[][COLUMNS]) {
    srand(time(NULL));
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            randomMatrix[i][j] = rand() % 100;
        }
    }
}

void ContadorInstrucao::runner(int matrix[][COLUMNS]) {
    int temp = 0; //auxiliar de coluna => pega valor anterior de j
    int counter = 0;
    int* direita;
    int* esquerda;
    int* baixo;
    int* atual;

    for (int i = 0; i < LINES; i++) {
        //cout << endl;
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
                    temp = j;
                    j = temp - 1;
                }
                else if (*direita > *baixo && j < COLUMNS - 1) { //se baixo < direita => direita
                    cout << "if1.2 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                    counter += *atual;
                    *atual = -1; //-> add por 

                } else if (j == COLUMNS - 1) { //se j = max => desce e j = maximo
                    counter += *atual;
                    cout << "if1.3 matriz matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                    *atual = -1; //-> add por ultimo
                    i++;
                    temp = j;
                    j = temp - 1;
                }
            }

            //a fazer
            else if (i > 0 && i < LINES - 1) {
                //validar j = 0;
                if (j == 0) { //se coluna = 0
                    if (*direita < *baixo) { //se direita < baixo => baixo
                        cout << "if2.1 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        counter += *atual;
                        *atual = -1; //-> add por ultimo
                        i++;
                        temp = j;
                        j = temp - 1;
                    }
                    if (*baixo < *direita) { //se direita > baixo => direita
                        cout << "if2.2 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        counter += *atual;
                        *atual = -1; //-> add por ultimo
                    }
                }
                else if (j == COLUMNS - 1) { //se coluna = max
                    if(*esquerda > *baixo) { //se esquerda > baixo => esquerda
                        cout << "if2.3 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        counter += *atual;
                        *atual = -1; //-> add por ultimo
                        temp = j;
                        j = temp - 2;
                    } else if (*baixo > *esquerda) { //se baixo > esquerda => baixo
                        cout << "if2.4 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        counter += *atual;
                        *atual = -1; //-> add por ultimo
                        i++;
                        temp = j;
                        j = temp - 1;
                    }
                }
                else if (j > 0 && j < COLUMNS - 1) {
                    if (*direita < *baixo && *baixo > *esquerda) { //se direita < baixo e baixo > esquerda  => baixo
                        cout << "if2.5 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        counter += *atual;
                        *atual = -1; //-> add por ultimo
                        i++;
                        temp = j;
                        j = temp - 1;
                    }
                    else if (*baixo < *direita && *direita > *esquerda) { //se baixo < direita e direita > esquerda => direita
                        cout << "if2.6 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        counter += *atual;
                        *atual = -1; //-> add por ultimo
                    }
                    else if (*direita < *esquerda && *esquerda > *baixo) { //se direita < esquerda e esquerda > baixo => esquerda
                        cout << "if2.7 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                        counter += *atual;
                        *atual = -1; //-> add por ultimo
                        temp = j;
                        j = temp - 2;
                    }
                }
            }

            else if (i == LINES - 1) {
                if (j < COLUMNS - 1) {
                    cout << "if3.1 matriz: [" << i << "]" << "[" << j << "] = " << *atual<< endl;
                    counter += *atual;
                    *atual = -1; //-> add por ultimo
                }
                else {
                    cout << "if3.2 matriz: [" << i << "]" << "[" << j << "] = " << *atual << endl;
                    counter += *atual;
                    *atual = -1; //-> add por ultimo
                }
            }
        }
    }
    SOMATORIO = counter;
    cout << endl;
}

void ContadorInstrucao::print(int randomMatrix[][COLUMNS]) {
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (randomMatrix[i][j] == 0) {
                printf(" 0 ");
            } else
            printf("%2.d  ", randomMatrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}
