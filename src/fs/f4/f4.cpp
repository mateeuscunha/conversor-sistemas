#include <iostream>
using namespace std;

string HtoOtroughB (string hexadecimal) {
	// transformando o hexadecimal em binário
	string binario = "";
	
	for (unsigned i = 0; i < hexadecimal.size(); i++) {
		switch(toupper(hexadecimal[i])) {
		case '0': binario += "0000"; break;
		case '1': binario += "0001"; break;
		case '2': binario += "0010"; break;
		case '3': binario += "0011"; break;
		case '4': binario += "0100"; break;
		case '5': binario += "0101"; break;
		case '6': binario += "0110"; break;
		case '7': binario += "0111"; break;
		case '8': binario += "1000"; break;
		case '9': binario += "1001"; break;
		case 'A': binario += "1010"; break;
		case 'B': binario += "1011"; break;
		case 'C': binario += "1100"; break;
		case 'D': binario += "1101"; break;
		case 'E': binario += "1110"; break;
		case 'F': binario += "1111"; break;
		}
	}
	
	// transformando o binário em octal
	string octal = "";
	// completando com zeros à esquerda (grupos de 3)
	while (binario.size() % 3 != 0) 
		binario = "0" + binario;
		
	// pegando grupamento de 3 em 3 e transformando
	for (unsigned i = 0; i < binario.size(); i += 3) {
		int valor = ((binario[i] - '0') * 4) + ((binario[i+1] - '0') * 2) + ((binario[i+2] - '0') * 1);
		
		octal += to_string(valor);
	}
	
	return octal;
}

string OtoHtroughB(string octal) {
    string binario = "";
    
    for (unsigned i = 0; i < octal.size(); i++) {
        switch(octal[i]) {
            case '0': binario += "000"; break;
            case '1': binario += "001"; break;
            case '2': binario += "010"; break;
            case '3': binario += "011"; break;
            case '4': binario += "100"; break;
            case '5': binario += "101"; break;
            case '6': binario += "110"; break;
            case '7': binario += "111"; break;
        }
    }
    
    // completando com zeros para ficar grupamento de 4 (requerido por Hexa)
    while (binario.length() % 4 != 0) {
        binario = "0" + binario;
    }
    
    string hexadecimal = "";
    for (unsigned i = 0; i < binario.length(); i += 4) {
        int valor = (binario[i] - '0') * 8 + 
                    (binario[i+1] - '0') * 4 + 
                    (binario[i+2] - '0') * 2 + 
                    (binario[i+3] - '0') * 1;
        
        if (valor < 10) {
            hexadecimal += to_string(valor);
        } else {
            hexadecimal += char('A' + (valor - 10));
        }
    }
    
    return hexadecimal;
}

int main() {
    string hexa;
    cout << "Digite um número hexadecimal: ";
    cin >> hexa;
    
    string octal = HtoOtroughB(hexa);
    cout << hexa << "₁₆ = " << octal << "₈" << endl;
    
    return 0;
}
