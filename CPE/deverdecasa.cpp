//Gustavo Andres Diaz Araujo - 252003506
#include <iostream>
using namespace std;
//declaracao de variaveis
int main() {
    int a=0,b=1,c=2,d=3,e=4,f=5,g=6,h=7,i=8,j=9,k=10,l=11,m=12,n=13,o=14,p=15,q=16,r=17,s=18,t=19,u=20,v=21,w=22,x=23,y=24,z=25;
    int chave, n1,n2,n3,n4,n5;
//cout para aaparecr na tela com cin para 'guardar' o valor desejado
    cout << "Escreva uma sequencia de 5 numeros inteiros entre 0 e 25: \n";
    cout << "\nPrimeiro numero: ";  cin >> n1;
    cout << "\nSegundo numero: ";  cin >> n2;
    cout << "\nTerceiro numero: "; cin >> n3;
    cout << "\nQuarto numero: ";   cin >> n4;
    cout << "\nQuinto numero: ";   cin >> n5;
//if para conferir se os numeros estao entre 0 e 25
    if(!(n1>=0 && n1<=25 && n2>=0 && n2<=25 && n3>=0 && n3<=25 && n4>=0 && n4<=25 && n5>=0 && n5<=25)){
        cout << "Entrada invalida!\n";
        cout << "Aperte enter para sair!\n";
        system("pause");
        return 0;
    }
//aqui comeca as chaves para cifra de cesar
    cout << "\nDigite um valor entre 0 e 7 para a cifra de cesar: ";
    cin >> chave;
    if(!(chave>=0 && chave<=7)){
        cout << "Chave invalida!\n";
        cout << "Aperte enter para sair!\n";
        system("pause");
        return 0;
    }

    // aqui comeca a cifrar
    n1 = (n1+chave>25)? n1+chave-26 : n1+chave;
    n2 = (n2+chave>25)? n2+chave-26 : n2+chave;
    n3 = (n3+chave>25)? n3+chave-26 : n3+chave;
    n4 = (n4+chave>25)? n4+chave-26 : n4+chave;
    n5 = (n5+chave>25)? n5+chave-26 : n5+chave;

    cout << "\nMensagem cifrada (em numeros):\n" << n1 << "\n" << n2 << "\n" << n3 << "\n" << n4 << "\n" << n5 << "\n";

    cout << "\nCifragem (convertido a letras): ";
    int temp;

    temp = n1; if(temp==a)cout<<"a";else if(temp==b)cout<<"b";else if(temp==c)cout<<"c";else if(temp==d)cout<<"d";else if(temp==e)cout<<"e";else if(temp==f)cout<<"f";else if(temp==g)cout<<"g";else if(temp==h)cout<<"h";else if(temp==i)cout<<"i";else if(temp==j)cout<<"j";else if(temp==k)cout<<"k";else if(temp==l)cout<<"l";else if(temp==m)cout<<"m";else if(temp==n)cout<<"n";else if(temp==o)cout<<"o";else if(temp==p)cout<<"p";else if(temp==q)cout<<"q";else if(temp==r)cout<<"r";else if(temp==s)cout<<"s";else if(temp==t)cout<<"t";else if(temp==u)cout<<"u";else if(temp==v)cout<<"v";else if(temp==w)cout<<"w";else if(temp==x)cout<<"x";else if(temp==y)cout<<"y";else if(temp==z)cout<<"z";
    temp = n2; if(temp==a)cout<<"a";else if(temp==b)cout<<"b";else if(temp==c)cout<<"c";else if(temp==d)cout<<"d";else if(temp==e)cout<<"e";else if(temp==f)cout<<"f";else if(temp==g)cout<<"g";else if(temp==h)cout<<"h";else if(temp==i)cout<<"i";else if(temp==j)cout<<"j";else if(temp==k)cout<<"k";else if(temp==l)cout<<"l";else if(temp==m)cout<<"m";else if(temp==n)cout<<"n";else if(temp==o)cout<<"o";else if(temp==p)cout<<"p";else if(temp==q)cout<<"q";else if(temp==r)cout<<"r";else if(temp==s)cout<<"s";else if(temp==t)cout<<"t";else if(temp==u)cout<<"u";else if(temp==v)cout<<"v";else if(temp==w)cout<<"w";else if(temp==x)cout<<"x";else if(temp==y)cout<<"y";else if(temp==z)cout<<"z";
    temp = n3; if(temp==a)cout<<"a";else if(temp==b)cout<<"b";else if(temp==c)cout<<"c";else if(temp==d)cout<<"d";else if(temp==e)cout<<"e";else if(temp==f)cout<<"f";else if(temp==g)cout<<"g";else if(temp==h)cout<<"h";else if(temp==i)cout<<"i";else if(temp==j)cout<<"j";else if(temp==k)cout<<"k";else if(temp==l)cout<<"l";else if(temp==m)cout<<"m";else if(temp==n)cout<<"n";else if(temp==o)cout<<"o";else if(temp==p)cout<<"p";else if(temp==q)cout<<"q";else if(temp==r)cout<<"r";else if(temp==s)cout<<"s";else if(temp==t)cout<<"t";else if(temp==u)cout<<"u";else if(temp==v)cout<<"v";else if(temp==w)cout<<"w";else if(temp==x)cout<<"x";else if(temp==y)cout<<"y";else if(temp==z)cout<<"z";
    temp = n4; if(temp==a)cout<<"a";else if(temp==b)cout<<"b";else if(temp==c)cout<<"c";else if(temp==d)cout<<"d";else if(temp==e)cout<<"e";else if(temp==f)cout<<"f";else if(temp==g)cout<<"g";else if(temp==h)cout<<"h";else if(temp==i)cout<<"i";else if(temp==j)cout<<"j";else if(temp==k)cout<<"k";else if(temp==l)cout<<"l";else if(temp==m)cout<<"m";else if(temp==n)cout<<"n";else if(temp==o)cout<<"o";else if(temp==p)cout<<"p";else if(temp==q)cout<<"q";else if(temp==r)cout<<"r";else if(temp==s)cout<<"s";else if(temp==t)cout<<"t";else if(temp==u)cout<<"u";else if(temp==v)cout<<"v";else if(temp==w)cout<<"w";else if(temp==x)cout<<"x";else if(temp==y)cout<<"y";else if(temp==z)cout<<"z";
    temp = n5; if(temp==a)cout<<"a";else if(temp==b)cout<<"b";else if(temp==c)cout<<"c";else if(temp==d)cout<<"d";else if(temp==e)cout<<"e";else if(temp==f)cout<<"f";else if(temp==g)cout<<"g";else if(temp==h)cout<<"h";else if(temp==i)cout<<"i";else if(temp==j)cout<<"j";else if(temp==k)cout<<"k";else if(temp==l)cout<<"l";else if(temp==m)cout<<"m";else if(temp==n)cout<<"n";else if(temp==o)cout<<"o";else if(temp==p)cout<<"p";else if(temp==q)cout<<"q";else if(temp==r)cout<<"r";else if(temp==s)cout<<"s";else if(temp==t)cout<<"t";else if(temp==u)cout<<"u";else if(temp==v)cout<<"v";else if(temp==w)cout<<"w";else if(temp==x)cout<<"x";else if(temp==y)cout<<"y";else if(temp==z)cout<<"z";

    // aqui comeca a decifragem ? para ver se e verdadeiro ou falso
    n1 = (n1-chave<0)? n1-chave+26 : n1-chave;
    n2 = (n2-chave<0)? n2-chave+26 : n2-chave;
    n3 = (n3-chave<0)? n3-chave+26 : n3-chave;
    n4 = (n4-chave<0)? n4-chave+26 : n4-chave;
    n5 = (n5-chave<0)? n5-chave+26 : n5-chave;

    cout << "\n\nMensagem decifrada (em numeros):\n" << n1 << "\n" << n2 << "\n" << n3 << "\n" << n4 << "\n" << n5 << "\n";
    cout << "\nDecifragem (em letras): \n";
    temp = n1; if(temp==a)cout<<"a";else if(temp==b)cout<<"b";else if(temp==c)cout<<"c";else if(temp==d)cout<<"d";else if(temp==e)cout<<"e";else if(temp==f)cout<<"f";else if(temp==g)cout<<"g";else if(temp==h)cout<<"h";else if(temp==i)cout<<"i";else if(temp==j)cout<<"j";else if(temp==k)cout<<"k";else if(temp==l)cout<<"l";else if(temp==m)cout<<"m";else if(temp==n)cout<<"n";else if(temp==o)cout<<"o";else if(temp==p)cout<<"p";else if(temp==q)cout<<"q";else if(temp==r)cout<<"r";else if(temp==s)cout<<"s";else if(temp==t)cout<<"t";else if(temp==u)cout<<"u";else if(temp==v)cout<<"v";else if(temp==w)cout<<"w";else if(temp==x)cout<<"x";else if(temp==y)cout<<"y";else if(temp==z)cout<<"z";
    temp = n2; if(temp==a)cout<<"a";else if(temp==b)cout<<"b";else if(temp==c)cout<<"c";else if(temp==d)cout<<"d";else if(temp==e)cout<<"e";else if(temp==f)cout<<"f";else if(temp==g)cout<<"g";else if(temp==h)cout<<"h";else if(temp==i)cout<<"i";else if(temp==j)cout<<"j";else if(temp==k)cout<<"k";else if(temp==l)cout<<"l";else if(temp==m)cout<<"m";else if(temp==n)cout<<"n";else if(temp==o)cout<<"o";else if(temp==p)cout<<"p";else if(temp==q)cout<<"q";else if(temp==r)cout<<"r";else if(temp==s)cout<<"s";else if(temp==t)cout<<"t";else if(temp==u)cout<<"u";else if(temp==v)cout<<"v";else if(temp==w)cout<<"w";else if(temp==x)cout<<"x";else if(temp==y)cout<<"y";else if(temp==z)cout<<"z";
    temp = n3; if(temp==a)cout<<"a";else if(temp==b)cout<<"b";else if(temp==c)cout<<"c";else if(temp==d)cout<<"d";else if(temp==e)cout<<"e";else if(temp==f)cout<<"f";else if(temp==g)cout<<"g";else if(temp==h)cout<<"h";else if(temp==i)cout<<"i";else if(temp==j)cout<<"j";else if(temp==k)cout<<"k";else if(temp==l)cout<<"l";else if(temp==m)cout<<"m";else if(temp==n)cout<<"n";else if(temp==o)cout<<"o";else if(temp==p)cout<<"p";else if(temp==q)cout<<"q";else if(temp==r)cout<<"r";else if(temp==s)cout<<"s";else if(temp==t)cout<<"t";else if(temp==u)cout<<"u";else if(temp==v)cout<<"v";else if(temp==w)cout<<"w";else if(temp==x)cout<<"x";else if(temp==y)cout<<"y";else if(temp==z)cout<<"z";
    temp = n4; if(temp==a)cout<<"a";else if(temp==b)cout<<"b";else if(temp==c)cout<<"c";else if(temp==d)cout<<"d";else if(temp==e)cout<<"e";else if(temp==f)cout<<"f";else if(temp==g)cout<<"g";else if(temp==h)cout<<"h";else if(temp==i)cout<<"i";else if(temp==j)cout<<"j";else if(temp==k)cout<<"k";else if(temp==l)cout<<"l";else if(temp==m)cout<<"m";else if(temp==n)cout<<"n";else if(temp==o)cout<<"o";else if(temp==p)cout<<"p";else if(temp==q)cout<<"q";else if(temp==r)cout<<"r";else if(temp==s)cout<<"s";else if(temp==t)cout<<"t";else if(temp==u)cout<<"u";else if(temp==v)cout<<"v";else if(temp==w)cout<<"w";else if(temp==x)cout<<"x";else if(temp==y)cout<<"y";else if(temp==z)cout<<"z";
    temp = n5; if(temp==a)cout<<"a";else if(temp==b)cout<<"b";else if(temp==c)cout<<"c";else if(temp==d)cout<<"d";else if(temp==e)cout<<"e";else if(temp==f)cout<<"f";else if(temp==g)cout<<"g";else if(temp==h)cout<<"h";else if(temp==i)cout<<"i";else if(temp==j)cout<<"j";else if(temp==k)cout<<"k";else if(temp==l)cout<<"l";else if(temp==m)cout<<"m";else if(temp==n)cout<<"n";else if(temp==o)cout<<"o";else if(temp==p)cout<<"p";else if(temp==q)cout<<"q";else if(temp==r)cout<<"r";else if(temp==s)cout<<"s";else if(temp==t)cout<<"t";else if(temp==u)cout<<"u";else if(temp==v)cout<<"v";else if(temp==w)cout<<"w";else if(temp==x)cout<<"x";else if(temp==y)cout<<"y";else if(temp==z)cout<<"z";
    system("pause");
    return 0;
    // saida do programa
}

