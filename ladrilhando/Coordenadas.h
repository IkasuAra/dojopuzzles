#ifndef COORDENADAS_H
#define COORDENADAS_H

#include <string>
#include <math.h>
using namespace std;

bool validarPontos(int A,int B, int C, int D, int E, string &msg){
    int d1 = sqrt(pow((A - 0), 2) + pow((0 - 0), 2));
    int d2 = sqrt(pow((D - 0), 2) + pow((E - 0), 2));
    int d3 = sqrt(pow((B - D), 2) + pow((C - E), 2));
    int d4 = sqrt(pow((B - A), 2) + pow((C - 0), 2));

    if(A < 0 or B < 0 or C < 0 or D < 0 or E < 0){
        msg = "As coordenadas devem conter números inteiros maiores que zero. Digite novamente. \n";
        return false;
    }
    if(B == D and C == E){
        msg = "Erro! Os vértices (B, C) e (D, E) não podem coincidir. Digite novamente.\n";
        return false;
    }
    if(d1 != d2 and d2 != d3 and d3 != d4 and d4 != d1){
        msg = "Erro! Os pontos citados não correspondem a uma sala quadrangular. Digite novamente. \n";
        return false;
    }
    return true;
}

#endif