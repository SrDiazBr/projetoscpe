#include <iostream>
#include <string>
using namespace std;
int main() {
    int n=0;
    cout << "Digite um numero inteiro positivo: \n";
    cin >> n;
    int total=0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
        if (total == n) {
            cout << n << " e um numero triangular." << endl;
        } 
        else {
        cout << n << " nao e um numero triangular." << endl;
        }
    return 0;
}