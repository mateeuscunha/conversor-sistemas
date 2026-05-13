#include <iostream>
using namespace std;

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
    string octal;
    cout << "Digite um número octal: ";
    cin >> octal;
    
    string hexadecimal = OtoHtroughB(octal);
    cout << octal << "₈ = " << hexadecimal << "₁₆" << endl;
    
    return 0;
}
