#ifndef LOGIN_H
#define LOGIN_H

#include <string>

using namespace std;

bool validarNome(string nome, string sobrenome, string &msg){
    if(nome[0] < 64 or nome[0] > 91){
            cout << endl;
            msg = "Erro. A primeira letra deve ser uma letra maiuscula. Digite novamente. \n";
            return false;
    }
    for(int i = 1; i < nome.size(); i++){
        if(nome[i] < 96 or nome[i] > 123){
            cout << endl;
            msg = "Erro! O nome não devem ter simbolos e deve começar com letra maiuscula e o restante minuscula. Digite novamente. \n";
            return false;
        }
    }
    if(sobrenome[0] < 64 or sobrenome[0] > 91){
            cout << endl;
            msg = "Erro. A primeira letra do sobrenome deve ser uma letra maiuscula. Digite novamente. \n";
            return false;
    }
    for(int i = 1; i < sobrenome.size(); i++){
        if(sobrenome[i] < 96 or sobrenome[i] > 123){
            cout << endl;
            msg = "Erro! O nome não deve ter simbolos e deve começar com letra maiuscula e o restante minuscula. Digite novamente. \n";
            return false;
        }
    }
    return true;
}

bool validarNascimento(string nascimento, string &msg){
    if(nascimento[2] != '/' and nascimento[5] != '/'){
        cout << endl;
        msg = "Erro! O dia, mes e o ano devem ser separadas por /. Digite novamente. \n";
        return false;
    }
    if(nascimento[0] > 52 or nascimento[0] < 48 and nascimento[1] > 57 or nascimento[1] < 48){
        cout << endl;
        msg = "Erro! Dia invalido. Digite novamente. \n";
        return false;
    }
    if(nascimento[3] < 48 or nascimento[3] > 50 and nascimento[4] > 57 or nascimento[4] < 48){
        cout << endl;
        msg = "Erro! Mes invalido. Digite novamente. \n";
        return false;
    }
    if(nascimento[6] < 48 or nascimento[6] > 50 and nascimento[7] != 57 or nascimento[7] != 48 and nascimento[8] < 48 or nascimento[8] > 57 and nascimento[9] > 57 or nascimento[9] < 48){
        cout << endl;
        msg = "Erro! Ano invalido. Digite novamente. \n";
        return false;
    }
    return true;
}

bool validarEmail(string email, string &msg){
    string formatoPadrao = "x@y.z";
    
    int posAt = -1;
    int posDot = -1;
    
    int amountAt = 0;
    int amountDot = 0;
    
    for (int index = 0; index < email.size(); index++) {
        if(email[index] == '@' and posAt == -1){
            posAt = index;
        }else if(email[index] == '.' and posDot == -1){
            posDot = index;
        }
        
        if(email[index] == '@')
            amountAt++;
        
        if(email[index] == '.')
            amountDot++;
    }
    
    if(amountAt > 1){
        cout << endl;
        msg = "Erro de formatação: muitos @";
        return false;
    }
    
    if(amountDot > 1){
        cout << endl;
        msg = "Erro de formatação: muitos .";
        return false;
    }
    
    if(posDot < posAt){
        cout << endl;
        msg = "Erro de formatação: posição incorreta do .";
        return false;
    }

    if(amountAt == 0 or amountDot == 0){
        cout << endl;
        msg = "Erro de formatação: sem @ ou sem .";
        return false;
    }
    return true;
}

bool sugestaoLogin(string login, string nome, string sobrenome, string email, string nascimento, string &msg){
    string sugestao1 = sobrenome + nascimento[0] + nascimento[1];
    string sugestao2 = sobrenome + nascimento[8] + nascimento[9];
    string sugestao3 = nome + nascimento[6] + nascimento[7]; + nascimento[8] + nascimento[9];
    string sugestao4 = sobrenome + '@' + nascimento[8] + nascimento[9];

    if(login != sugestao1 and login != sugestao2 and login != sugestao3 and login != sugestao4){
        cout << endl;
        cout << "Login ja existente. O login deve ser unico." << endl;

        cout << "Sugestoes de login: " << endl;
        cout << sugestao1 << endl;
        cout << sugestao2 << endl;
        cout << sugestao3 << endl;
        cout << sugestao4 << endl;
        cout << endl;
        
        return false;
    }
    return true;
}

#endif