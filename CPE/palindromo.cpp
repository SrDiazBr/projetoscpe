#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string palavra;
    string concatena;
    cout << "Digite uma palavra para a verificacao: \n";
    cin >> palavra;
    // Converter para minúsculas
    for (char &c : palavra) {
        c = tolower(static_cast<unsigned char>(c));
    }
    for (int i = palavra.length() - 1; i >= 0; i--) {
        concatena = concatena + palavra[i];
    }
    if (palavra == concatena) {
        cout << "A palavra '" << palavra << "' e um palindromo." << endl;
    } else {
        cout << "A palavra '" << palavra << "' nao e um palindromo." << endl;
    }
    return 0;
}
