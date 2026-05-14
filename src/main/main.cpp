#include <iostream>

using namespace std;

bool validarBase(int base) {
	bool valida = false;
	
	if ((base == 2) or (base == 8) or (base == 10) or (base == 16))
		valida = true;
	
	if (!valida) {
		cout << "Esta base não é válida!" << endl;
	}
	
	return valida;
}

bool validarNumero (string numero, int base) {
	bool valido = true;
	if (base == 2) {
		for (unsigned i = 0; i < numero.size(); i++) 
			if ((numero[i] != '0') and (numero[i] != '1'))
				valido = false;
	}
	
	return valido;
}


int main() {
	cout << "--- CONVERSOR UNIVERSAL DE SISTEMAS DE NUMERAÇÃO ---" << endl << endl;
	cout << "Bases válidas para conversão: " << endl;
	cout << "	- BINÁRIO     == 2" << endl;
	cout << "	- OCTAL       == 8" << endl;
	cout << "	- DECIMAL     == 10" << endl;
	cout << "	- HEXADECIMAL == 16" << endl << endl;

	cout << "Digite a base do número a ser convertido, seguido do número: ";
	string numero;
	int base;
	cin >> base >> numero;
	
	while (!validarBase(base)) {
		cout << "Digite uma base válida: ";
		cin >> base;
	}
	
	while (!validarNumero(numero, base)) {
		cout << "Digite um número válido para sua base (" << base << "): ";
		cin >> numero;
	}
	

	return 0;
}
