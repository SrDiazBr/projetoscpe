#include <iostream>
using namespace std;
int main() {
    int x;
    int y;
    cout <<"Digite um numero inteiro: ";
    cin >> x;
    cout <<"Digite um numero inteiro: ";
    cin >> y;
    cout << "x+y = " << x+y << "\n"; 
    cout << "x-y = " << x-y << "\n"; 
    if (x>y)
        cout << x << " e maior que " << y << "\n";
    else if (y>x)
        cout << y << "e maior que " << x << "\n";
    else
        cout << x << " e igual a " << y << "\n";
    return 0;
}