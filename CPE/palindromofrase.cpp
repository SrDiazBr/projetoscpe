#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main() {
    string frase;
    cout << "Digite uma frase para a verificacao: \n";
    getline(cin, frase);
    string tirabrancos = "";
    for (char c : frase) {
        if (c != ' ') {
            tirabrancos += tolower(static_cast<unsigned char>(c));
        }
    }
    string invertida = "";
    for (int i = tirabrancos.length() - 1; i >= 0; i--) {
        invertida += tirabrancos[i];
    }
    if (tirabrancos == invertida) {
        cout << "A frase '" << frase << "' e um palindromo." << endl;
    } else {
        cout << "A frase '" << frase << "' nao e um palindromo." << endl;
    }
    return 0;
}