#include <iostream>
using namespace std;
int main() {
    int arr[6];
    cout << "Digite 6 numeros inteiros:\n";
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }
    int menor = arr[0];
    int maior = arr[0];
    double soma = arr[0];
    for (int i = 1; i < 6; i++) {
        if (arr[i] < menor) menor = arr[i];
        if (arr[i] > maior) maior = arr[i];
        soma += arr[i];
    }
    double media = soma / 6;
    cout << "Menor valor: " << menor << endl;
    cout << "Maior valor: " << maior << endl;
    cout << "Soma: " << soma << endl;
    cout << "Media (inteira): " << media << endl;
    cout << "Array invertido: ";
    for (int i = 5; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}