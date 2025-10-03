#include <iostream>
using namespace std;
int main() { string frase;
cout << "Digite a frase (minusculas, sem acento): ";
getline(cin, frase);
string binarioTotal; // guarda todos os bits da frase
// Aqui passa parte por parte da frase, convertendo cada caractere para binario
for (int k = 0; k < frase.length(); k++) {
    int valor = (int)frase[k];  // ASCII do caractere
    int restos[8];
    // Aqui faz adivisão sucessiva por 2, guardando os restos e "traduzindo" o caractere  Ascii para binario
    for (int i = 0; i < 8; i++) {
        restos[i] = valor % 2;
        valor = valor / 2;
    }
    // Aqui esta fazendo a inversao dos restos para formar o binario correto, para que cada caractere seja representado por 8 bits do sistema binario
    for (int i = 7; i >= 0; i--) {
        binarioTotal += (restos[i] + '0');
    }
}   
cout << "Binario original: " << binarioTotal << endl;
// Agora comprimir a string binarioTotal usando o length de binariototal
cout << "Resultado comprimido: ";
int count = 1;
for (int i = 1; i <= binarioTotal.length(); i++) {
    if (i < binarioTotal.length() && binarioTotal[i] == binarioTotal[i-1]) {
        count++;
    } else {
        if (count >= 7) {
            cout << count; // aqui esta fazendo, a compresao daquele que tem mais de sete na sequencia de binarios
        } else {
            for (int j = 0; j < count; j++) {
                cout << binarioTotal[i-1];
            }
        }
        count = 1;
    }
}
cout << endl;
return 0;//e finalmente retorna ,esse treco que me fez fumacar a cabeca, tive ajuda da nossa amiga ia, mas creio que so quando fiquei empacado
}
   