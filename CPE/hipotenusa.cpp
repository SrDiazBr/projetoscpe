#include <iostream>
#include <cmath>
using namespace std;
int main (){
    float a, b;
    cout << "Digite o valor do cateto oposto: ";
    cin >> a;
    cout << "Digite o valor do cateto adjacente: ";
    cin >> b;
    float hipotenusa = sqrt(a*a + b*b);
    cout << "O valor da hipotenusa e: " << hipotenusa << endl;
    return 0;
}