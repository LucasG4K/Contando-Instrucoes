#ifndef CONTADOR_INSTRUCAO_HPP
#define CONTADOR_INSTRUCAO_HPP
#include <iostream>
#include <String>
#include <ctime>
using namespace std;
#define LINES 7
#define COLUMNS 7

class ContadorInstrucao {
private:
    static int SOMATORIO;

public:
    int numGenerator(int randomMatrix[][COLUMNS]);
    void runner(int randomMatrix[][COLUMNS]);
    void print(int randomMatrix[][COLUMNS]);
    int getSomatorio();
    
    
};
#endif