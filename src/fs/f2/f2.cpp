//conversor de número binário, octal e hexadecimal para decimal
#include <iostream>
#include <cmath>

using namespace std;

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

int main(){
    cout << "------- CONVERSOR DE BINARIO, OCTAL OU HEXADECIMAL PARA DECIMAL -------" << endl;
    int base;
    cout << "Digite a base do seu numero: ";
    cin >> base;

    while((base != 2) and (base != 8) and (base != 16)){ // conferindo se a base está correta
        cout << "Informe uma base valida: ";
        cin >> base;
    } 

    string nomeBase = ""; //pegando o nome da base para imprimir no final
    if (base == 2)
        nomeBase = "binario";
    else if (base == 8)
        nomeBase = "octal";
    else 
        nomeBase = "hexadecimal";


    if (base == 16) { //se for hexadecimal 
        string numero;
        cout << "Informe o numero a ser convertido (caracteres maiusculos): ";
        cin >> numero;
        cout << "O numero: " << numero << " " << nomeBase << " equivale a: ";
        cout << HtoD(numero, base) << " em decimal" << endl;
        
    }
    else { //se for binario ou octal
        int numero;
        cout << "Informe o numero a ser convertido: ";
        cin >> numero;
        cout << "O numero: " << numero << " " << nomeBase << " equivale a: ";
        cout << BOtoD(numero, base) << " em decimal" << endl;
    }
    
    
    return 0;
}
