#ifndef LADRILHOS_H
#define LADRILHOS_H

#include <string>
#include <math.h>

using namespace std;

int calcularLadrilhos(int A, int B, int C, int D, int E, int altura, int largura){
    int d1 = sqrt(pow((A - 0), 2) + pow((0 - 0), 2));
    int d2 = sqrt(pow((D - 0), 2) + pow((E - 0), 2));
    int d3 = sqrt(pow((B - D), 2) + pow((C - E), 2));
    int d4 = sqrt(pow((B - A), 2) + pow((C - 0), 2));
    int areaSala = 0;
    
    if(d1 == d2 == d3 == d4)
        areaSala = pow(d1,2);
    else 
        areaSala = d1 * d2;
    
    int areaLadrilho = altura * largura;
    
    return areaSala / areaLadrilho;
}

bool validarTamanho(int altura, int largura, string &msg){
    if(altura <= 0 or largura <= 0){
        msg = "Erro! O tamanho do ladrilho deve ser numeros inteiros maiores que zero. \n";
        return false;
    }
    return true;
}

#endif