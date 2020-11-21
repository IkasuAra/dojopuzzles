/* Um arquiteto gosta muito de projetar salas em formato quadrangular, 
que normalmente não são tão complicadas de se construir, exceto quando os lados não são perpendiculares uns aos outros.
Nestes casos, na hora de ladrilhar as salas, existe uma dificuldade em saber o número exato de ladrilhos 
retangulares que deverão ser utilizados para não haver desperdício dos ladrilhos que devem ser cortados 
para se ajustar o chão às paredes.

Uma sala é definida pelos pontos (0, 0), (A, 0), (B, C) e (D, E) onde todas as coordenadas (A, B, C, D e E)
são inteiros maiores que zero;
Os vértices (B, C) e (D, E) não são coincidentes;
Um ladrinho possui dimensões F x G (com F e G inteiros maior que zero);
A parte não utilizada de um ladrilho cortado é jogada fora (mesmo que pudesse ser reutilizada em outra parte da sala);
Os ladrilhos começam a ser posicionados a partir da posição (0, 0) perpendiculares à parede formada por (0, 0) e (A, 0).
Você deve ajudar este arquiteto desenvolvendo um programa que, dado as coordenadas da sala e o tamanho dos ladrilhos, 
retorne a quantidade exata de ladrilhos que serão suficientes para cobrir toda a sala.*/

#include <iostream>
#include <string>
#include "Coordenadas.h"
#include "Ladrilhos.h"

using namespace std;

int main(){
    int coordenadaA = 0;
    int coordenadaB = 0;
    int coordenadaC = 0;
    int coordenadaD = 0; 
    int coordenadaE = 0; 
    int larguraLadrilho; 
    int alturaLadrilho = 0;
    int distancia = 0;
    string msg = "";
    
    do{
        cout << msg;
        cout << "Complete os quatro pontos de cada vértice da sala (0, 0), (A, 0), (B, C) e (D, E)" << endl;
        cout << "A: ";
        cin >> coordenadaA;
        cout << "B: ";
        cin >> coordenadaB;
        cout << "C: ";
        cin >> coordenadaC;
        cout << "D: ";
        cin >> coordenadaD;
        cout << "E: ";
        cin >> coordenadaE;
        cout << endl;
    
    }while(!validarPontos(coordenadaA, coordenadaB, coordenadaC, coordenadaD, coordenadaE, msg));

    do{
        msg = "";
        cout << "Informe o tamanho do ladrilho [Altura x Largura]: ";
        cin >> alturaLadrilho >> larguraLadrilho;
        cout << endl;

    }while(!validarTamanho(alturaLadrilho, larguraLadrilho, msg));

    cout << "Quantidade de ladrinhos para cobrir a sala atual: " << calcularLadrilhos(coordenadaA, coordenadaB, coordenadaC, coordenadaD, coordenadaE, alturaLadrilho, larguraLadrilho) << endl;

    return 0;
    
    }