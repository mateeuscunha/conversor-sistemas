#include <iostream>
#include <string>

using namespace std;

bool validarBase (int base) {
	bool valida = false;
	
	if ((base == 2) or (base == 8) or (base == 10) or (base == 16))
		valida = true;
	
	if (!valida) {
		cout << "ERRO: Esta base não é válida!" << endl;
	}
	
	
	
	return valida;
}

bool validarNumero (string numero, int base) {
	bool valido = true;
	if (base == 2) { // binário
		for (unsigned i = 0; i < numero.size(); i++) 
			if ((numero[i] != '0') and (numero[i] != '1'))
				valido = false;
				
	} else if (base == 8) { // octal
		unsigned contador = 0;
		for (unsigned i = 0; i < numero.size(); i++) {
			switch(numero[i]) {
				case '0': contador++; break;
				case '1': contador++; break;
				case '2': contador++; break;
				case '3': contador++; break;
				case '4': contador++; break;
				case '5': contador++; break;
				case '6': contador++; break;
				case '7': contador++; break;
			}
		}
		if (!(contador == numero.size()))
			valido = false;
			
	} else if (base == 10) { // decimal
		unsigned contador = 0;
		for (unsigned i = 0; i < numero.size(); i++) {
			switch(numero[i]) {
				case '0': contador++; break;
				case '1': contador++; break;
				case '2': contador++; break;
				case '3': contador++; break;
				case '4': contador++; break;
				case '5': contador++; break;
				case '6': contador++; break;
				case '7': contador++; break;
				case '8': contador++; break;
				case '9': contador++; break;
			}
		}
		if (!(contador == numero.size()))
			valido = false;
			
	} else if (base == 16) { // hexadecimal
		unsigned contador = 0;
		for (unsigned i = 0; i < numero.size(); i++) {
			switch(numero[i]) {
				case '0': contador++; break;
				case '1': contador++; break;
				case '2': contador++; break;
				case '3': contador++; break;
				case '4': contador++; break;
				case '5': contador++; break;
				case '6': contador++; break;
				case '7': contador++; break;
				case '8': contador++; break;
				case '9': contador++; break;
				case 'A': contador++; break;
				case 'B': contador++; break;
				case 'C': contador++; break;
				case 'D': contador++; break;
				case 'E': contador++; break;
				case 'F': contador++; break;
			}
		}
		if (!(contador == numero.size()))
			valido = false;
	}
	
	return valido;
}

int main() {
	int base;
	cout << "Digite a base: ";
	cin >> base;
	
	while (!validarBase(base)) {
		cout << "Digite a base: ";
		cin >> base;
	}
	
	string numero;
	cout << "Digite o numero: ";
	cin >> numero;
	// convertendo o número recebido para maiúsculas
	for (unsigned i = 0; i < numero.size(); i++)
		numero[i] = toupper(numero[i]);
	
	while (!validarNumero(numero, base)) {
		cout << "Digite um número válido para essa base (" << base << "): ";
		
		cin >> numero;
		
		for (unsigned i = 0; i < numero.size(); i++)
		numero[i] = toupper(numero[i]);
	}

	return 0;
}
