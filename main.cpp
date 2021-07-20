#include "contador_instrucao.hpp"

int main() {
    /*matriz de teste principal:
    int matrix[LINES][COLUMNS] = { { 6, 18,  7,  8,  9,  3,  1}, 
                                   {27, 45, 50,  6,  5,  1,  2}, 
                                   {21, 32, 44, 35,  0,  9, 22}, 
                                   {15, 11,  7, 45,  4, 18,  7}, 
                                   { 4,  9, 19, 10,  6, 89, 11}, 
                                   {23, 23, 27,  1, 91, 77,  6}, 
                                   {33, 28, 34, 18, 19, 96,  1} };*/

    /*matriz de teste secundaria:
    int matrix[LINES][COLUMNS] = { {82, 92, 49, 59, 86, 33, 71}, 
                                   {39, 86, 18, 95, 83, 85, 36}, 
                                   {41, 47, 96, 84, 95, 67, 59}, 
                                   {99, 96, 15, 35, 43, 94, 25}, 
                                   {47, 80, 57,  0, 83, 90, 34}, 
                                   {23, 84, 29, 76, 88, 64, 54}, 
                                   {26, 18, 69, 54, 90, 25, 98} };*/

    int matrix[LINES][COLUMNS];

    ContadorInstrucao instrucao;

    instrucao.numGenerator(matrix);
    cout << "Matriz modelo" << endl;
    instrucao.print(matrix);
    cout << "Caminhos (origem -> destino)" << endl;
    instrucao.runner(matrix);
    cout << "\nQuantidade de passos: " << instrucao.getCount() << "\nTotal do caminho: " << instrucao.getSum() << endl << endl;
    cout << "Matriz percorrida" << endl;
    instrucao.print(matrix);
    return 0;
}