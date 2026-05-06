#include <iostream>

using namespace std;

void conversorBO(int decimal, int base){ //conversor de decimal para binario/octal
    int restos[100];

    int iterador = 0;
    while(decimal != 0) { //estrutura de repetição para ir dividindo e
        restos[iterador] = decimal % base;

        decimal /= base;
        iterador++;
    }

    for (int i = (iterador - 1); i >= 0; i--) //imprimindo o vetor de trás pra frente
        cout << restos[i];
    cout << endl;

}

void hexadecimal (int decimal) { //conversor de decimal para hexadecimal
    char restos[100];
    
    int iterador = 0;
    while(decimal != 0) {
        if (decimal % 16 < 10) {
            restos[iterador] = (decimal % 16) + '0'; // o + '0' é pra converter para char
        } else {
            restos[iterador] = (((decimal % 16) - 10) + 65) + '0'; 
        }

        decimal /= 16;
        iterador++; 
    }

    for (int i = (iterador - 1); i >= 0; i--)
        cout << restos[i];
    cout << endl;    
}

int main(){
    int decimal, base;
    
    cout << "------- CONVERSOR DE DECIMAL PARA BINARIO, OCTAL OU HEXACIMAL -------" << endl;
    
    cout << "Informe o decimal a ser convertido: ";
    cin >> decimal; 
    
    cout << "Informe a base desejada (2, 8 ou 16): ";
    cin >> base;

    while ((base != 2) and (base != 8) and (base != 16)) {
        cout << "Informe uma base valida (2, 8 ou 16): ";
        cin >> base;
    }

    if (base == 16) {
        hexadecimal(decimal);
    } else {
        conversorBO(decimal, base);
    }
    
        
    return 0;
}

// nao receber letras <!> trava o codigo tudo 
/* fazer voltar see o usuario quiser (estrutura de repetição na main inteira) ex --> digite 1 para se quiser converter outro numero OU digite 0 para encerrar o programa*/


/*Binario e octal --> ok
    hexadecimal --> ?
    
    12 / 2 = 6 ---> 0
    6 / 2 = 3 ---> 0
    3 / 2 = 1 ---> 1
    1 / 2 = 0 ---> 1
    //numero impresso --> 0011 = 3
    //numero que queremos --> 1100 = 12       [0, 0, 1, 1] --> 0011
    */

/*
Decimal	Hexadecimal
0	0
1	1
2	2
3	3
4	4
5	5
6	6
7	7
8	8
9	9
10	A
11	B
12	C
13	D
14	E
15	F
16	10
17	11
18	12
*/