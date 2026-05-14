#include "../parser/parser.h"
#include <iostream>

using namespace std;

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
	
	// convertendo o número recebido para maiúsculas	
	for (unsigned i = 0; i < numero.size(); i++)
		numero[i] = toupper(numero[i]);
	
	// validando a base
	while (!validarBase(base)) {
		cout << "Digite uma base válida: ";
		cin >> base;
	}
	
	// validando o número
	while (!validarNumero(numero, base)) {
		cout << "Digite um número válido para sua base (" << base << "): ";
		cin >> numero;
		
		// convertendo o número recebido para maiúsculas
		for (unsigned i = 0; i < numero.size(); i++)
		numero[i] = toupper(numero[i]);
	}
	

	return 0;
}
