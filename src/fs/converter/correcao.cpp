#include <iostream>
#include <cmath>

using namespace std;

string HtoD(string numero) { // hexadecimal para decimal
    int resultado = 0;
    int tamanho = numero.size();
    
    for (int i = 0; i < tamanho; i++) {
		char caractere = numero[i];
		
		int valorDigito;
		if ((caractere >= '0') and (caractere <= '9'))
			valorDigito = caractere - '0'; // exemplo: '0' (48) - '0' (48) = 0 (valor correspondente)
		else // está A-F
			valorDigito = caractere - 'A' + 10; // +10, já que A vale 10, B vale 11 e etc
		
		int peso = 1; // para cada posicao (for de cima) calculamos o peso (for abaixo)
		for (int j = 0; j < (tamanho - 1 - i); j++)
			peso *= 16;
			
		resultado += valorDigito * peso;
	}
	
	return to_string(resultado);
}

int main() {
	
	string numero;
	cout << endl << "qual numero?: ";
	cin >> numero;
	
	cout << HtoD(numero) << endl;



	return 0;
}
