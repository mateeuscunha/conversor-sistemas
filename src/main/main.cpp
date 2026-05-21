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
	
	// limitando em 16 casas depois da virgula
	bool truncamento = false;
	if (fracao.length() > 16) {
		fracao = fracao.substr(0, 15);
		truncamento = true;
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
	
	string resultado = resultadoSwitch(base, base_requerida, inteira, fracao);
	
	// saida final
	resultadoFinal(base, numero, base_requerida, resultado);

	if (truncamento)
		avisoTruncamento();

	return 0;
}
