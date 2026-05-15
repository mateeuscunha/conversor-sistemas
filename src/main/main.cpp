#include "../parser/parser.h"
#include "../formatador/formatador.h"
#include "../conversor/conversor.h"
#include <iostream>

using namespace std;

int main() {
	printIntro();
	
	int base;
	printBase();
	cin >> base;
	
	// validando a base
	while (!validarBase(base)) {
		erroBase();
		cin >> base;
	}
	
	string numero;
	cout << endl;
	printNumero();
	cin >> numero;
	
	// convertendo o número recebido para maiúsculas	
	for (unsigned i = 0; i < numero.size(); i++)
		numero[i] = toupper(numero[i]);
	
	// validando o número
	while (!validarNumero(numero, base)) {
		erroNumero(base);
		cin >> numero;
		
		// convertendo o número recebido para maiúsculas
		for (unsigned i = 0; i < numero.size(); i++)
		numero[i] = toupper(numero[i]);
	}
	
	// vendo se tem parte fracionária ou não
	bool parteFracionaria = false;
	unsigned posVirgula;
	for (unsigned i = 0; i < numero.size(); i++) {
		if ((numero[i] == '.') or (numero[i] == ',')) {
			parteFracionaria = true;
			posVirgula = i;
		}
	}
	
	string inteira = "", fracao = "";
	
	// se tiver parte fracionária, dividir a parte inteira e a decimal
	if (parteFracionaria) {
		inteira = numero.substr(0, posVirgula);
		fracao = numero.substr(posVirgula + 1);
		cout << "parte inteira: " << inteira << endl;
		cout << "parte fracionária: " << fracao << endl;	
	} else {
		inteira = numero;
		fracao = "";
	}
	
	// pegando a base requerida
	int base_requerida;
	printBase_requerida();
	cin >> base_requerida;
	
	// validando a base requerida
	while ((!validarBase(base_requerida)) or (base_requerida == base)) {
		if (base_requerida == base)
			mesmaBase(base);
		else
			erroBase();
			
		cin >> base_requerida;
	}
	
	// CONVERSÕES
	
	string resultado;
	
	if (base == 2) { 		 // entrada é um binário
		
		if (base_requerida == 8)
			resultado = BtoO(numero);
		else if (base_requerida == 10)
			resultado = BOtoD(numero, base);
		else if (base_requerida == 16)
			resultado = BtoH(numero);			
			
	} else if (base == 8) {  // entrada é um octal
		
		if (base_requerida == 2)
			resultado = OtoB(numero);
		else if (base_requerida == 10)
			resultado = BOtoD(numero, base);
		else if (base_requerida == 16)
			resultado = OtoHtroughB(numero);
			
	} else if (base == 10) { // entrada é um decimal
		
		if (base_requerida == 2)
			resultado = DtoBO(numero, base_requerida);
		else if (base_requerida == 8)
			resultado = DtoBO(numero, base_requerida);
		else if (base_requerida == 16)
			resultado = DtoH(numero);			
			
	} else if (base == 16) { // entrada é um hexadecimal
		
		if (base_requerida == 2)
			resultado = HtoB(numero);
		else if (base_requerida == 8)
			resultado = HtoOtroughB(numero);
		else if (base_requerida == 10)
			resultado = HtoD(numero);			
			
	}
	
	// saida final
	resultadoFinal(base, numero, base_requerida, resultado);

	return 0;
}
