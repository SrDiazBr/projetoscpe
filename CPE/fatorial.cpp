#include <iostream>
#include <string>
using namespace std;
int main() {
    int n ;
    cout << "Digite um numero: ";
    cin >> n;
    long long int fatorial = 1;
    for (int i = n; i >= 1; i--) {
        fatorial = fatorial* i;
    }
    cout << "O fatorial do numero e: " << n << " e " << fatorial << endl;
    return 0;
}
    