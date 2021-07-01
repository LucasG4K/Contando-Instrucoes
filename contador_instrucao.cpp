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
    ContadorInstrucao c;
    
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLUMNS; j++) {



            if (i == 0 && j == 0) {
                if (matrix[i][j + 1] < matrix[i + 1][j]) {
                    cout << "if1.1 matriz: [" << i + 1 << "]" << "[" << j << "]" << endl;
                    c.SOMATORIO += matrix[i][j] + matrix[i + 1][j];
                    i++;
                } else if (matrix[i][j + 1] > matrix[i + 1][j]) {
                    cout << "if1.2 matriz: [" << i << "]" << "[" << j + 1 << "]" << endl;
                    
                }


            } else if (i == 0 && j < COLUMNS) {
                if (matrix[i][j + 1] > matrix[i + 1][j]) {
                    cout << "if2.1 matriz: [" << i << "]" << "[" << j + 1 << "]" << endl;
                    c.SOMATORIO += matrix[i][j + 1];
                } else if (matrix[i][j + 1] < matrix[i + 1][j]) {
                    cout << "if2.2 matriz: [" << i + 1 << "]" << "[" << j << "]" << endl;
                    c.SOMATORIO += matrix[i + 1][j];
                    i++;
                }
            }

            else if (i == 0 && j == COLUMNS) {
                cout << "if3.1 matriz: [" << i + 1 << "]" << "[" << j << "]" << endl;
                c.SOMATORIO += matrix[i + 1][j];
                j = COLUMNS;
            } 


            else if (i > 0 && i < LINES && j < COLUMNS) {
                if (matrix[i][j] < matrix[i + 1][j]) {
                    cout << "if4.1 matriz: [" << i + 1 << "]" << "[" << j << "]" << endl;
                    c.SOMATORIO += matrix[i + 1][j];
                    i++;
                } else if (matrix[i][j] < matrix[i][j + 1] ) {
                    cout << "if4.2 matriz: [" << i << "]" << "[" << j + 1 << "]" << endl;
                    c.SOMATORIO += matrix[i][j + 1];
                }



            }else if (i > 0 && i < LINES && j == COLUMNS) {
                j = COLUMNS;
                if (matrix[i][j] < matrix[i][j - 1]) {
                    cout << "if5.1 matriz: [" << i + 1 << "]" << "[" << j + 1 << "]" << endl;
                    c.SOMATORIO += matrix[i][j];
                    i++;
                    
                } else if(matrix[i][j - 1] < matrix[i][j]) {
                    cout << "if5.1 matriz: [" << i + 1 << "]" << "[" << j + 1 << "]" << endl;
                    c.SOMATORIO += matrix[i][j];
                    i++;
                }
            j = COLUMNS;


            } else if (i == LINES && j < COLUMNS) {
                cout << "if6.1 matriz: [" << i << "]" << "[" << j << "]" << endl;
                c.SOMATORIO += matrix[i][j];
            }

            else if(i == LINES && j == COLUMNS) {
                cout << "Chegou!!! [" << i << "]" << "[" << j << "]" << endl;
                c.SOMATORIO += matrix[i][j];
            }
            //else cout << "Matriz nao e' capaz de ser percorrida conforme a regra" << endl;
        }
    }
    cout << endl << "somato'rio = " << c.SOMATORIO; 
}



void print(int randomMatrix[][COLUMNS]) {
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%2.d  ", randomMatrix[i][j]);
        }
        cout << endl;
    }
}

int main() {
    //int matrix[LINES][COLUMNS];
    int matrix[4][4] = {{1,2,3,4}, {1,1,6,1}, {9,10,11,12}, {13,14,15,16}};
    //numGenerator(matrix);
    print(matrix);
    runner(matrix);
    return 0;
}