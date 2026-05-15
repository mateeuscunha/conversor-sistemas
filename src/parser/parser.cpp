#include "parser.h"
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
	bool pontoEncontrado = false; // controle do separador decimal
	
	if (base == 2) { // binário
		unsigned contador = 0;
		for (unsigned i = 0; i < numero.size(); i++) {
			// permite ponto ou vírgula (separador decimal)
			if ((numero[i] == '.') or (numero[i] == ',')) {
				if (!pontoEncontrado) {
					pontoEncontrado = true;
					contador++;  // conta como caractere válido
				} else {
					valido = false;  // segundo separador, inválido
				}
			}
			// dígitos válidos do binário
			else if ((numero[i] == '0') or (numero[i] == '1')) {
				contador++;
			}
			else {
				valido = false;
			}
		}
		if (!(contador == numero.size()))
			valido = false;
				
	} else if (base == 8) { // octal
		unsigned contador = 0;
		for (unsigned i = 0; i < numero.size(); i++) {
			// permite ponto ou vírgula (separador decimal)
			if ((numero[i] == '.') or (numero[i] == ',')) {
				if (!pontoEncontrado) {
					pontoEncontrado = true;
					contador++;
				} else {
					valido = false;
				}
			}
			// dígitos válidos do octal
			else switch(numero[i]) {
				case '0': contador++; break;
				case '1': contador++; break;
				case '2': contador++; break;
				case '3': contador++; break;
				case '4': contador++; break;
				case '5': contador++; break;
				case '6': contador++; break;
				case '7': contador++; break;
				default: valido = false;
			}
		}
		if (!(contador == numero.size()))
			valido = false;
					
	} else if (base == 10) { // decimal
		unsigned contador = 0;
		for (unsigned i = 0; i < numero.size(); i++) {
			// permite ponto ou vírgula (separador decimal)
			if ((numero[i] == '.') or (numero[i] == ',')) {
				if (!pontoEncontrado) {
					pontoEncontrado = true;
					contador++;
				} else {
					valido = false;
				}
			}
			// dígitos válidos do decimal
			else switch(numero[i]) {
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
				default: valido = false;
			}
		}
		if (!(contador == numero.size()))
			valido = false;
			
	} else if (base == 16) { // hexadecimal
		unsigned contador = 0;
		for (unsigned i = 0; i < numero.size(); i++) {
			// permite ponto ou vírgula (separador decimal)
			if ((numero[i] == '.') or (numero[i] == ',')) {
				if (!pontoEncontrado) {
					pontoEncontrado = true;
					contador++;
				} else {
					valido = false;
				}
			}
			// dígitos válidos do hexadecimal
			else switch(numero[i]) {
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
				default: valido = false;
			}
		}
		if (!(contador == numero.size()))
			valido = false;
	}
	
	return valido;
}
