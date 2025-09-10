#include <iostream>
using namespace std;
int main() {
    cout << "Digite uma palavra: ";
    string palavra;
    getline(cin, palavra);
    int i=0;
    int vogais=0;
    while ( i < palavra.length()) {
        palavra[i] = tolower(palavra[i]);
        if (palavra[i]=='a' || palavra[i]=='e' || palavra[i]=='i' || palavra[i]=='o' || palavra[i]=='u' ) {
            vogais++;
            cout << "A posicao " << i <<" ,Tem vogal " << palavra[i] << endl;
        }
        i++;
    }
    cout << "A palavra " << palavra << " tem " << vogais << " vogais" << endl;
    return 0;    
}
        
   
