/*MMASS - Mass of Molecule*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string cadena;

	cin >> cadena;

	stack <char> pila;
	stack <int> valor;

	for (int i = 0; i < cadena.size(); ++i){
		
		if(cadena[i] == '(')
			pila.push('(');
		
		else if( isalpha(cadena[i])){
			
			pila.push(cadena[i]);
			
			if(cadena[i] == 'H')
				valor.push(1);
			if(cadena[i] == 'C')
				valor.push(12);
			if(cadena[i] == 'O')
				valor.push(16);
		}

		else if(cadena[i] == ')'){
			
			int suma = 0;

			while(!pila.empty()){

				if(pila.top() == '('){
					pila.pop();
					break;
				}
				suma += valor.top();
				valor.pop();
				pila.pop();
			}

			valor.push(suma);
			pila.push('I');
		}
		else{
			int aux;

			aux = cadena[i] - '0';
			aux = aux * valor.top();

			valor.pop();
			valor.push(aux);

		}		
	}

	int total = 0;

	while(!valor.empty()){
		total += valor.top();
		valor.pop();
	}

	cout << total <<'\n';
	return 0;
}