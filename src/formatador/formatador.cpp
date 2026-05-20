#include "formatador.h"
#include <iostream>

using namespace std;

void printIntro () {
	cout << "--- CONVERSOR UNIVERSAL DE SISTEMAS DE NUMERAÇÃO ---" << endl << endl;
	cout << "Bases válidas para conversão: " << endl;
	cout << "	- BINÁRIO     == 2" << endl;
	cout << "	- OCTAL       == 8" << endl;
	cout << "	- DECIMAL     == 10" << endl;
	cout << "	- HEXADECIMAL == 16" << endl << endl;
}

void printBase () {
	cout << "Digite a base do número a ser convertido: ";
}

void printNumero () {
	cout << "Digite o número a ser convertido: ";
}

void erroBase () {
	cout <<  "ERRO: Digite uma base válida (2, 8, 10 ou 16): ";
}

void mesmaBase (int base) {
	cout << "A base da entrada informada é " << base << ". Informe uma base diferente de " << base << ": ";
}

void erroNumero(int base) {
	string base_txt = "";
	switch (base) {
		case 2: base_txt = "binário"; break;
		case 8: base_txt = "octal"; break;
		case 10: base_txt = "decimal"; break;
		case 16: base_txt = "hexadecimal"; break;
	}
	
	cout << "Você informou base " << base << ", digite um número " << base_txt << " válido: ";
}

void printBase_requerida() {
	cout << "Informe a base para qual o número vai ser convertido: ";
}

void resultadoFinal(int base, string numero, int base_requerida, string resultado) {
	string base_txt = "";
	switch (base) {
		case 2: base_txt = "binário"; break;
		case 8: base_txt = "octal"; break;
		case 10: base_txt = "decimal"; break;
		case 16: base_txt = "hexadecimal"; break;
	}
	
	string base_requerida_txt = "";
	switch (base_requerida) {
		case 2: base_requerida_txt = "binário"; break;
		case 8: base_requerida_txt = "octal"; break;
		case 10: base_requerida_txt = "decimal"; break;
		case 16: base_requerida_txt = "hexadecimal"; break;
	}
	
	cout << "O número " << base_txt << " " << numero << " convertido para " << base_requerida_txt;
	cout << " é: " << endl << " = " << resultado << endl;
}

void avisoTruncamento() {
	cout << "O número foi limitado para 16 casas decimais!!" << endl;
}
