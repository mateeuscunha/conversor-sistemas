#include <iostream>

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
	if (base == 2) {
		for (unsigned i = 0; i < numero.size(); i++) 
			if ((numero[i] != '0') and (numero[i] != '1'))
				valido = false;
	} else if (base == 8) {
		//falta fazer
	} else if (base == 10) {
		//falta fazer
	} else if (base == 16) {
		//falta fazer
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
	
	while (!validarNumero(numero, base)) {
		cout << "Digite um número válido para essa base (" << base << "): ";
		cin >> numero;
	}

	return 0;
}
