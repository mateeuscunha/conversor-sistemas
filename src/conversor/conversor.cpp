#include <iostream>
#include <cmath>

using namespace std;

void DtoBO(int decimal, int base){ //conversor de decimal para binario/octal
    int restos[100];

    int iterador = 0;
    while(decimal != 0) { //estrutura de repetição para ir dividindo e guardando os restos
        restos[iterador] = decimal % base;

        decimal /= base;
        iterador++;
    }

    for (int i = (iterador - 1); i >= 0; i--) //imprimindo o vetor de trás pra frente
        cout << restos[i];
    cout << endl;
}

void DtoH (int decimal) { //conversor de decimal para hexadecimal
    char restos[100];
    
    int iterador = 0;
    while(decimal != 0) { //estrutura de repetição para ir dividindo e guardando os restos
        if (decimal % 16 < 10) { 
            restos[iterador] = (decimal % 16) + '0'; // o + '0' é pra converter para char
        } else { //se estiver nos caracteres entre A e F
            restos[iterador] = (((decimal % 16) - 10) + 65) + '0'; 
        }

        decimal /= 16;
        iterador++; 
    }

    for (int i = (iterador - 1); i >= 0; i--)
        cout << restos[i];
    cout << endl;    
}

int BOtoD(int numero, int base) { // binario/octal para decimal
    int vetor[100];
    
    int iterador = 0;
    
    while (numero != 0) {
        vetor[iterador] = numero % 10; //vetor está recebendo os bits, do menos significativo para o mais significativo
        
        numero /= 10;
        iterador++;
    }
    
    int convertido = 0;
         
    for (int i = 0; i < iterador; i++) //somando os produtos das casas com os valores
        convertido += pow(base, i) * vetor[i];
    
    return convertido;
}

int HtoD(string numero, int base) { // hexadecimal para decimal
    int vetor[100];
    
    unsigned iterador;

    for (iterador = 0; iterador < numero.size(); iterador++) {
        vetor[iterador] = numero[(numero.size() - 1) - iterador]; //pegando os caracteres do numero, da esquerda para a direita
    }

    int convertido = 0; //esse vai ser o retorno da função
    
    for (unsigned i = 0; i < iterador; i++) //pegando cada item do vetor e multiplicando pelo valor da casa que ele se encontra
        if ((vetor[i] == 'A') or (vetor[i] == 'B') or (vetor[i] == 'C') or (vetor[i] == 'D') or (vetor[i] == 'E') or (vetor[i] == 'F'))
            convertido += pow(base, i) * (vetor[i] - 'A' + 10); //se o caracter for maior ou igual a A, faz a conversão para inteiro desse jeito
        else
            convertido += pow(base, i) * (vetor[i] - '0' + 0); //se o caracter for menor que A, faz a conversão para inteiro desse jeito

    return convertido;
}

string BtoO(string binario) {
	// Completa com zeros à esquerda
    while (binario.length() % 3 != 0) {
        binario = "0" + binario;
    }
    
    string octal = "";
    
    // Processa de 3 em 3 bits
    for (unsigned i = 0; i < binario.length(); i += 3) {
        string grupo = binario.substr(i, 3);
        
        // Converte grupo binário para octal
        int valor = (grupo[0] - '0') * 4 + (grupo[1] - '0') * 2 + (grupo[2] - '0'); // converte de caracter para inteiro e multiplica pelo peso da casa decimal
        
        octal += to_string(valor);
    }
    
    return octal;

}

string BtoH(string binario) {
	// Completa com zeros à esquerda
	while (binario.size() % 4 != 0) {
		binario = "0" + binario;
	}
	
	string hexadecimal = "";
	
	// Processa de 4 em 4 bits
	for (unsigned i = 0; i < binario.size(); i += 4) {
		// pegar grupo de 4 bits
		int bit1 = binario[i] - '0';     // primeiro bit (peso 8)
        int bit2 = binario[i+1] - '0';   // segundo bit (peso 4)
        int bit3 = binario[i+2] - '0';   // terceiro bit (peso 2)
        int bit4 = binario[i+3] - '0';   // quarto bit (peso 1)
        
        // converter para valor decimal (0 a 15)
        int valor = (bit1 * 8) + (bit2 * 4) + (bit3 * 2) + (bit4 * 1);
        
        // converter valor para caractere hexadecimal
        if (valor < 10) {
			hexadecimal += to_string(valor); // 0 a 9
		} else {
			// 10 = A, 11 = B, 12 = C, 13 = D, 14 = E, 15 = F
			char letra = 'A' + (valor - 10);
			hexadecimal += letra;
		}
	}
	return hexadecimal;
}

int main() {

	


	return 0;
}
