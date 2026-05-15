#ifndef CONVERSOR_H
#define CONVERSOR_H
#include <string>
using namespace std;

string DtoBO(string decimal, int base);
string DtoH (string decimal);
string BOtoD(string numero, int base);
string HtoD(string numero);
string BtoO(string binario);
string OtoB (string octal);
string BtoH(string binario);
string HtoB (string hexadecimal);
string OtoHtroughB(string octal);
string HtoOtroughB (string hexadecimal);

#endif
