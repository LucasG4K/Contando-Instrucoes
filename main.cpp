#include "contador_instrucao.hpp"

int main() {
    //int matrix[LINES][COLUMNS];

    ContadorInstrucao instrucao;

    //instrucao.numGenerator(matrix);
    int matrix[7][7] = { {6,18,7,8,9,3,1}, {27,45,50,6,5,1,2}, {21,32,44,35,0,9,22}, {15,11,7,45,4,18,7}, {4,9,19,10,6,89,11}, {23,23,27,1,91,77,6}, {33,28,34,18,19,96,1} };
    cout << "Matriz modelo" << endl;
    instrucao.print(matrix);
    cout << "Caminhos (origem -> destino)" << endl;
    instrucao.runner(matrix);
    cout << "Matriz percorrida" << endl;
    instrucao.print(matrix);
    cout << "Total do caminho: " << instrucao.getSomatorio();
    return 0;
}