#include <iostream>

using namespace std;

void conversorBO(int decimal, int base){
    int restos[100];

    int iterador = 0;
    while(decimal != 0) {
        restos[iterador] = decimal % base;

        decimal /= base;
        iterador++;
    }

    for (int i = (iterador - 1); i >= 0; i--)
        cout << restos[i];
    cout << endl;


    /*Binario e octal --> ok
    hexadecimal --> ?
    
    12 / 2 = 6 ---> 0
    6 / 2 = 3 ---> 0
    3 / 2 = 1 ---> 1
    1 / 2 = 0 ---> 1
    //numero impresso --> 0011 = 3
    //numero que queremos --> 1100 = 12       [0, 0, 1, 1] --> 0011
    */
}



int main(){
    int decimal, base;

    cin >> decimal >> base; 
    
    conversorBO(decimal, base);
    return 0;
}