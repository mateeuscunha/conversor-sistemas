#ifndef CONVERSOR_H
#define CONVERSOR_H
#include <string>
using namespace std;

string DtoBO(int decimal, int base);
string DtoH (int decimal);
int BOtoD(int numero, int base);
int HtoD(string numero, int base);
string BtoO(string binario);
string OtoB (string octal);
string BtoH(string binario);
string HtoB (string hexadecimal);
string OtoHtroughB(string octal);
string HtoOtroughB (string hexadecimal);

#endif
