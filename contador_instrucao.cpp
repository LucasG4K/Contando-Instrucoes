#include "contador_instrucao.hpp"

int ContadorInstrucao::AMOUNT = 0;

int ContadorInstrucao::COUNTER = 0;

int ContadorInstrucao::getSum() { return AMOUNT; }

int ContadorInstrucao::getCount() { return COUNTER; }

int ContadorInstrucao::numGenerator(int randomMatrix[][COLUMNS]) {
    srand(time(NULL));
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            randomMatrix[i][j] = rand() % 100;
        }
    }
}

void ContadorInstrucao::runner(int matrix[][COLUMNS]) {
    //simplifying the matrix
    int* right;
    int* left;
    int* down;
    int* current;

    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLUMNS; j++) {

            right = &matrix[i][j + 1];
            left = &matrix[i][j - 1];
            down = &matrix[i + 1][j];
            current = &matrix[i][j];

            cout << "matrix: [" << i << "]" << "[" << j << "] = " << *current << endl;
            COUNTER++;

            //start line
            if (i == 0) {
                if (*right <= *down || j == COLUMNS - 1) { //right < down and j  or colunas = max => down
                    i++;
                    j = j - 1;
                }
                AMOUNT += *current;
                *current = -1;
            }

            //lines between start and MAX
            else if (i > 0 && i < LINES - 1) {
                if (j == 0) { //column = 0
                    if (*right <= *down) { //right < down => down
                        i++;
                        j = j - 1;
                    }
                    AMOUNT += *current;
                    *current = -1;
                }

                else if (j == COLUMNS - 1) { //column = max
                    if (*left > *down) { //left > down => left
                        j = j - 2;
                    } else if (*down >= *left) { //down > left => down
                        i++;
                        j = j - 1;
                    }
                    AMOUNT += *current;
                    *current = -1;
                }

                else if (j > 0 && j < COLUMNS - 1) {
                    if (*left <= *down && *down >= *right) { //right < down and down > left => down
                        i++;
                        j = j - 1;
                    } else if (*right < *left && *left > *down) { //right < left e left > down => left  
                        j = j - 2;
                    }
                    AMOUNT += *current;
                    *current = -1;
                }
            }

            //max line
            else if (i == LINES - 1) {
                AMOUNT += *current;
                *current = -1;
            }
        }
    }
}

void ContadorInstrucao::print(int randomMatrix[][COLUMNS]) {
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (randomMatrix[i][j] == 0) printf(" 0  ");
            else printf("%2.d  ", randomMatrix[i][j]);
        } cout << endl; 
    } cout << endl;
}
