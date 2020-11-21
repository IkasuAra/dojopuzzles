#ifndef TELEFONE_H
#define TELEFONE_H

#include <string>

using namespace std;

bool desbloquearTelefone(string pin, string desbloquear, string &msg){
    if(pin != desbloquear){
        msg = "PIN incorreto! Digite o PIN novamente. \n";
        return false;
    }
    msg = "Telefone desbloqueado com sucesso!";
    return true;
}

bool validarPin(string pin, string padrao, string &msg){
    if(pin.size() < 2 and pin.size() > 17){
        msg = "Erro! O pin deve conter de 2 até 9 digitos conforme o formato " + padrao + ". Digite novamente o PIN.\n";
        return false;
    }
    for(int index = 0; index <= pin.size(); index++){
        if(index % 2 != 0 and pin[index] != '-' and index < pin.size() - 1){
            msg = "Erro! Deve conter '-' entre os numeros conforme o formato " + padrao + ". Digite novamente o PIN.\n";
            return false;
        }else if(index % 2 == 0 or index == 0){
            char umCaracter = pin[index]; 
            int versaoInteiraCaracter = (int) umCaracter;
            
            if(versaoInteiraCaracter < 48 and versaoInteiraCaracter > 57){
                msg = "Erro! O numero do PIN não segue o formato " + padrao + " em que X representa um numero de 0 a 9. Digite novamente. \n";
                return false;
            }
            if(pin[index] == pin[index + 2] or pin[index] == pin[index + 4] or pin[index] == pin[index + 6] or pin[index] == pin[index + 8] or pin[0] == pin[10] == pin[12] == pin[14] == pin[16]){
                msg = "Erro! Os numeros contidos no PIN nao devem se repetir. Digite novamente. \n";
                return false;
            }
            if(pin[index] < 0){
                msg = "Erro! Os numeros do PIN nao deve conter numeros menores que zero. Digite novamente. \n";
                return false;
            }
        }else{}
    }
    msg = "O seu PIN foi guardado com sucesso!";
    return true;
}

int padroesValidos(string pin){
    int quantidadePadroesValidos = 9, quantidadeTracos = 0;
    
    for(int index = 0; index <= (pin.size() - 1); index++){
        if(index % 2 != 0 or pin[index] == '-')
            quantidadeTracos ++;
    }
    
    int apenasNumeros = pin.size() - quantidadeTracos;

    for(int i = 8; i >= apenasNumeros; i--){
        quantidadePadroesValidos = quantidadePadroesValidos * i;
    }
    return quantidadePadroesValidos;
}


#endif /* TELEFONE_H */