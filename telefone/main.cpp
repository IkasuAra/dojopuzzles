/*Uma das maneiras de desbloquear um telefone é deslizando os dedos sobre uma seqüência
de números em um teclado numérico `1 - 9`. 
Para um padrão ser válido, ele precisa satisfazer o seguinte:
- Todos os números selecionados devem ser distintos 
(não podemos selecionar o mesmo número mais de uma vez) e;
- Dois números não podem se conectar pulando um terceiro número, 
a não ser que esse número já tenha sido utilizado anteriormente. 
Por exemplo, `4 - 2 - 1 - 7` é um padrão válido, enquanto `2 - 1 - 7` não é. 
Encontre o número total de padrões válidos de tamanho `N`, onde `1 <= N <= 9`.*/

#include <iostream>
#include "Telefone.h"

using namespace std;

int main(){
    string padrao = "(X-X-X-X)";
    string pin;
    string desbloquear;
    string msg = "";

    do{
        cout << msg;
        
        cout << "Digite um novo PIN para o seu telefone no formato " + padrao + ": ";
        cin >> pin;
        
        cout << endl;
    
    }while(!validarPin(pin, padrao, msg));

    cout << msg << endl;

    cout << "Havia pelo menos " << padroesValidos(pin) << " padroes validos contidos nesta quantidade de digitos." << endl;

    msg = "";

    do{
        cout << msg;

        cout << "\nDigite o PIN para desbloquear o telefone: ";
        cin >> desbloquear;
        
        cout << endl;

    }while(!desbloquearTelefone(pin, desbloquear, msg));

    cout << msg << endl;

    return 0;
}