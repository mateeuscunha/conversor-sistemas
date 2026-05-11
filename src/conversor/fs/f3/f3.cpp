#include <iostream>

using namespace std;

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
	string binario;
	cin >> binario;

	cout << BtoH(binario) << endl;

	return 0;
}
