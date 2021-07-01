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
    int counter = matrix[0][0];
    
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << j << endl;


            //feito
            if (i == 0) {
                if (matrix[i][j + 1] < matrix[i + 1][j]) {
                    cout << "if1.1 matriz: [" << i + 1 << "]" << "[" << j << "]" << endl;
                    counter += matrix[i + 1][j];
                    i++;
                } else if (matrix[i][j + 1] > matrix[i + 1][j]) {
                    counter += matrix[i][j + 1];
                    cout << "if1.2 matriz: [" << i << "]" << "[" << j + 1 << "]" << endl;
                } else if (j == COLUMNS - 1) {
                    i++;
                    j = COLUMNS - 1;
                    cout << "if1.3 matriz matriz: [" << i << "]" << "[" << j << "]" << endl;
                }
            } 
            
            
            else if (i == 0 && j < COLUMNS) {
                if (matrix[i][j + 1] > matrix[i + 1][j]) {
                    cout << "if2.1 matriz: [" << i << "]" << "[" << j + 1 << "]" << endl;
                    counter += matrix[i][j + 1];
                } else if (matrix[i][j + 1] < matrix[i + 1][j]) {
                    cout << "if2.2 matriz: [" << i + 1 << "]" << "[" << j << "]" << endl;
                    counter += matrix[i + 1][j];
                    i++;
                }
            }

            else if (i == 0 && j == COLUMNS) {
                cout << "if3.1 matriz: [" << i + 1 << "]" << "[" << j << "]" << endl;
                counter += matrix[i + 1][j];
                j = COLUMNS;
            } 


            else if (i > 0 && i < LINES && j < COLUMNS) {
                if (matrix[i][j] < matrix[i + 1][j]) {
                    cout << "if4.1 matriz: [" << i + 1 << "]" << "[" << j << "]" << endl;
                    counter += matrix[i + 1][j];
                    i++;
                } else if (matrix[i][j] < matrix[i][j + 1] ) {
                    cout << "if4.2 matriz: [" << i << "]" << "[" << j + 1 << "]" << endl;
                    counter += matrix[i][j + 1];
                }



            }else if (i > 0 && i < LINES && j == COLUMNS) {
                j = COLUMNS;
                if (matrix[i][j] < matrix[i][j - 1]) {
                    cout << "if5.1 matriz: [" << i + 1 << "]" << "[" << j + 1 << "]" << endl;
                    counter += matrix[i][j];
                    i++;
                    
                } else if(matrix[i][j - 1] < matrix[i][j]) {
                    cout << "if5.1 matriz: [" << i + 1 << "]" << "[" << j + 1 << "]" << endl;
                    counter += matrix[i][j];
                    i++;
                }
            j = COLUMNS;


            } else if (i == LINES && j < COLUMNS) {
                cout << "if6.1 matriz: [" << i << "]" << "[" << j << "]" << endl;
                counter += matrix[i][j];
            }

            else if(i == LINES && j == COLUMNS) {
                cout << "Chegou!!! [" << i << "]" << "[" << j << "]" << endl;
                counter += matrix[i][j];
            }
            //else cout << "Matriz nao e' capaz de ser percorrida conforme a regra" << endl;
        }
    }
    cout << endl << "Total do caminho = " << counter; 
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
    //int matrix[7][7] = {{6,18,7,8,9,3,1}, {27,45,50,6,5,1,2}, {21,32,44,35,0,9,22}, {15,11,7,45,4,18,7}, {4,9,19,10,6,89,11}, {23,23,27,1,91,77,6}, {33,28,34,18,19,96,1}};
    int matrix[3][3] = {{1,2,3}, {1,2,1}, {5,3,2}};
    //numGenerator(matrix);
    print(matrix);
    runner(matrix);
    return 0;
}