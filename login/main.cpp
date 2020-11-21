/*Ao realizar seu cadastro em um site o usuário deve definir um login juntamente de sua senha. 
definições: * O login deve ser único * Ao o usuário se deparar com a indisponibilidade
do login desejado sugerir outros 3 possíveis logins não utilizados no banco de dados 
* Os logins sugeridos devem conter trechos de combinação do nome, sobrenome e email 
informados pelo usuário, também podem ser utilizados números 
Exemplo 1: Nome: Andre Cardoso Nascimento: 05/09/1986 Email: andrecardosodev@gmail 
Login desejado: andrecardoso -- ao estar utilizado 
Sugestões: cardosoandre, devcardoso, andrev 
Exemplo 1: Com números Nome: Andre Cardoso Nascimento: 
05/09/1986 Email: andrecardosodev@gmail Login desejado: andrecardoso -- 
ao estar utilizado Sugestões: cardosoandre05, devcardoso05, andrev1986*/

#include <iostream>
#include "Login.h"

using namespace std;

int main(){
	string nome, sobrenome, nascimento, email, login, msg = "";

	do{
		cout << msg << endl;
		
		cout << "Digite seu primeiro e ultimo nome: ";
		cin >> nome >> sobrenome;

	}while(!validarNome(nome, sobrenome, msg));

	msg = "";
	
	do{
		cout << msg << endl;
		
		cout << "Digite sua data de nascimento [dd/mm/aaaa]: ";
		cin >> nascimento;
		
	}while(!validarNascimento(nascimento, msg));

	msg = "";

	do{
		cout << msg;
		
		cout << "Digite seu email [x@y.z]: ";
		cin >> email;

	}while(!validarEmail(email, msg));

	msg = "";

	do{	
		cout << msg;

		cout << "Login desejado: ";
		cin >> login;

	}while(!sugestaoLogin(login, nome, sobrenome, email, nascimento, msg));

	cout << "cadastro realizado com sucesso!" << endl;
    
	return 0;
}