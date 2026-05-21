#include "conversor.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string resultadoSwitch(int base, int base_requerida, string inteira, string fracao) {
	string resultado = "";
	
	bool fracaoVazia = false;
	if (fracao == "")
		fracaoVazia = true;
	
	if (base == 2) { 		 // entrada é um binário
		
		if (base_requerida == 8) {
			resultado = BtoO(inteira);
			if (!fracaoVazia)
				resultado += "," + BtoO(fracao);
		}
		else if (base_requerida == 10) {
			resultado = BOtoD(inteira, base);
			if (!fracaoVazia)
				resultado += "," + BOtoD(fracao, base);
		}
		else if (base_requerida == 16) {
			resultado = BtoH(inteira);
			if (!fracaoVazia)
				resultado += "," + BtoH(fracao);
		}	
			
	} else if (base == 8) {  // entrada é um octal
		
		if (base_requerida == 2) {
			resultado = OtoB(inteira);
			if (!fracaoVazia)
				resultado += "," + OtoB(fracao);
		}
		else if (base_requerida == 10) {
			resultado = BOtoD(inteira, base);
			if (!fracaoVazia)
				resultado += "," + BOtoD(fracao, base);
		}
		else if (base_requerida == 16) {
			resultado = OtoHtroughB(inteira);
			if (!fracaoVazia)
				resultado += "," + OtoHtroughB(fracao);
		}
			
	} else if (base == 10) { // entrada é um decimal
		
		if (base_requerida == 2) {
			resultado = DtoBO(inteira, base_requerida);
			if (!fracaoVazia)
				resultado += "," + DtoBO(fracao, base_requerida);
		}
		else if (base_requerida == 8) {
			resultado = DtoBO(inteira, base_requerida);
			if (!fracaoVazia)
				resultado += "," + DtoBO(fracao, base_requerida);
		}
		else if (base_requerida == 16) {
			resultado = DtoH(inteira);
			if (!fracaoVazia)
				resultado +=  "," + DtoH(fracao);
		}
			
	} else if (base == 16) { // entrada é um hexadecimal
		
		if (base_requerida == 2) {
			resultado = HtoB(inteira);
			if (!fracaoVazia)
				resultado += "," + HtoB(fracao);
		}
		else if (base_requerida == 8) {
			resultado = HtoOtroughB(inteira);
			if (!fracaoVazia)
				resultado += "," + HtoOtroughB(fracao);
		}
		else if (base_requerida == 10) {
			resultado = HtoD(inteira);
			if (!fracaoVazia)
				resultado += "," + HtoD(fracao);
		}
			
	}
		
	return resultado;
}

string DtoBO(string numero, int base){ // conversor de decimal para binario/octal
 int decimal = stoi(numero);
    int restos[100];
    int iterador = 0;
    
    // MOSTRANDO O TRACE
    cout << "\n--- PROCESSO DE CONVERSÃO ---" << endl;
    cout << "Convertendo " << decimal << " decimal para base " << base << ":" << endl;
    cout << "Divisões sucessivas:" << endl;
    
    int original = decimal;
    while(decimal != 0) {
        restos[iterador] = decimal % base;
        cout << decimal << " ÷ " << base << " = " << (decimal/base) 
             << " (resto " << restos[iterador] << ")" << endl;
        decimal /= base;
        iterador++;
    }
    
    // MOSTRANDO OS RESTOS LIDOS DE TRÁS PRA FRENTE
    cout << "\nRestos (lidos de baixo para cima): ";
    for (int i = (iterador-1); i >= 0; i--) {
        cout << restos[i];
        if (i > 0) cout << " ";
    }
    cout << endl;
    
    // MOSTRANDO O SOMATÓRIO POSICIONAL
    cout << "\nSomatório posicional:" << endl;
    string resultado = "";
    for (int i = (iterador-1); i >= 0; i--) {
        int posicao = (iterador-1 - i);
        int peso = pow(base, posicao);
        resultado += (restos[i] + '0');
        
        cout << restos[i] << " × " << base << "^" << posicao 
             << " = " << restos[i] * peso;
        if (i > 0) cout << " + ";
        else cout << " = " << original << endl;
    }
    
    cout << "Resultado: " << resultado << " (base " << base << ")" << endl;
    cout << "-------------------------------\n" << endl;
    
    return resultado;
}

string DtoH (string numero) { // conversor de decimal para hexadecimal
    int decimal = stoi(numero);
    char restos[100];
    
    int iterador = 0;
    while(decimal != 0) { //estrutura de repetição para ir dividindo e guardando os restos
        if (decimal % 16 < 10) { 
            restos[iterador] = (decimal % 16) + '0'; // o + '0' é pra converter para char
        } else { //se estiver nos caracteres entre A e F
            restos[iterador] = (((decimal % 16) - 10) + 65); 
        }

        decimal /= 16;
        iterador++; 
    }

	// lendo os restos, ao contrario, e jogando na string resposta
	string resposta = "";
    for (int i = (iterador - 1); i >= 0; i--)
        resposta += restos[i];    
        
    return resposta;
}

string BOtoD(string numero_txt, int base) { // binario/octal para decimal
    int numero = stoi(numero_txt); // convertendo para inteiro para facilitar
    
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
    
    string convertido_txt = to_string(convertido);
    
    return convertido_txt;
}

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

string BtoO(string binario) { // binario para octal (agrupamento 3 em 3)
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

string OtoB (string octal) { // octal para binario
	
	string binario = "";
	
	// Percorrendo o octal caracter por caracter
	for (unsigned i = 0; i < octal.length(); i++) { 
		char digito = octal[i];
		
		switch(digito) {
			case '0': binario += "000"; break;
			case '1': binario += "001"; break;
			case '2': binario += "010"; break;
            case '3': binario += "011"; break;
            case '4': binario += "100"; break;
            case '5': binario += "101"; break;
            case '6': binario += "110"; break;
            case '7': binario += "111"; break;
            default:
				cout << "Erro: dígito octal inválido - " << digito << endl;
                return "";
		}
	}
	
	return binario;
}

string BtoH(string binario) { // binario para hexadecimal (agrupamento 4 em 4)
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

string HtoB (string hexadecimal) { // hexadecimal para binario
	string binario = "";
	
	for (unsigned i = 0; i < hexadecimal.length(); i++) {
		char digito = hexadecimal[i];
		
		switch(digito) {
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
		default: 
			cout << "Erro: dígito hexadecimal inválido - " << digito << endl;
			return "";
		};
	}
	
	return binario;
}

string OtoHtroughB(string octal) { // octal para hexadecimal passando por binário
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

string HtoOtroughB (string hexadecimal) { // hexadecimal para octal passando por binário
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

