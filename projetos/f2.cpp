//conversor de número binário, octal e hexadecimal para decimal
#include <iostream>
#include <cmath>

// 101001 --> 41 
// 543210 #indices

using namespace std;

int converter(int numero, int base){
    int vetor[100];
    
    int iterador = 0;
    
    while (numero != 0) {
        vetor[iterador] = numero % 10; //vetor está recebendo os bits, do menos significativo para o mais significativo
        
        numero /= 10;
        iterador++;
    }

    int convertido = 0;
    for (int i = 0; i < iterador; i++) { //somando os produtos das casas com os valores
        convertido += pow(base, i) * vetor[i];
    }

    return convertido;
}

int main(){
    int numero, base;
    cout << "------- CONVERSOR DE BINARIO, OCTAL OU HEXADECIMAL PARA DECIMAL -------" << endl;
    cout << "Informe o numero a ser convertido: ";
    cin >> numero;
    cout << "Digite a base do numero informado: ";
    cin >> base;
    
    string nomeBase = "";
    if (base == 2)
        nomeBase = "binario";
    else if (base == 8)
        nomeBase = "octal";
    else 
        nomeBase = "hexadecimal";

    cout << "O numero: " << numero << " " << nomeBase << " equivale a: ";
    cout << converter(numero, base) << " em decimal" << endl;
    
    return 0;
}