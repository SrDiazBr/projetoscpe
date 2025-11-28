#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#define MAX_LINE 512
using namespace std;

int main()
{
     char url[MAX_LINE];
     char destino[MAX_LINE];

    HRESULT    dl;
    
    typedef HRESULT (WINAPI * URLDownloadToFileA_t)(LPUNKNOWN pCaller, LPCSTR szURL, LPCSTR szFileName, DWORD dwReserved, void * lpfnCB);
    URLDownloadToFileA_t xURLDownloadToFileA;
    xURLDownloadToFileA = (URLDownloadToFileA_t)GetProcAddress(LoadLibraryA("urlmon"), "URLDownloadToFileA");
    
    cout << "Digite a URL a ser baixada. Coloque o nome completo. Exemplo: http://www.unb.br\n";
    cin >> url;
    cout << "\nDigite o nome do arquivo destino com o codigo HTML\n";
    cin >> destino;
    
      cout << "\nEspere um momento, baixando o arquivo ...";

    dl = xURLDownloadToFileA(NULL, url, destino, 0, NULL);

    
    if(dl == S_OK) 
    {
        cout << "\nArquivo foi baixado ! \n";
        ifstream fin(destino);
	    char szBuff[2048];
	    while(fin.getline(szBuff, 2048))
	    {
		     cout << szBuff << "\n";
	    }
    } 
    else if(dl == E_OUTOFMEMORY) 
    {
       cout << "\nErro: Memoria Insuficiente ! ";
        return 0;
    } 
    else 
    {
        cout << "\nErro desconhecido ao baixar o arquivo !";
        return 0;
    }
    #include <algorithm> // transform()

if(dl == S_OK) 
{
    cout << "\nArquivo foi baixado ! \n";

    // Lê o HTML baixado
    ifstream fin(destino);
    char szBuff[2048];

    // Pergunta palavra-chave ao usuário
    string chave;
    cout << "Digite a palavra-chave que deseja buscar no HTML: ";
    cin >> chave;

    // Pergunta nome do arquivo .txt para salvar os resultados
    string nomeTxt;
    cout << "Digite o nome do arquivo TXT para salvar os resultados (ex: resultado.txt): ";
    cin >> nomeTxt;

    // Converte chave para minúsculas (busca case-insensitive)
    string chaveLower = chave;
    transform(chaveLower.begin(), chaveLower.end(), chaveLower.begin(), ::tolower);

    // Abre arquivo de saída com o nome informado
    ofstream fout(nomeTxt);
    fout << "Resultados para a palavra: " << chave << "\n\n";

    int linha = 0;
    bool encontrou = false;

    // Loop lendo o HTML linha por linha
    while (fin.getline(szBuff, 2048))
    {
        linha++;

        string linhaStr = szBuff;
        string linhaLower = linhaStr;
        transform(linhaLower.begin(), linhaLower.end(), linhaLower.begin(), ::tolower);

        // Verifica se contém a palavra
        if (linhaLower.find(chaveLower) != string::npos)
        {
            encontrou = true;

            cout << "Linha " << linha << ": " << linhaStr << "\n";
            fout << "Linha " << linha << ": " << linhaStr << "\n";
        }
    }

    if (!encontrou)
    {
        cout << "\nNenhuma ocorrência encontrada.\n";
        fout << "Nenhuma ocorrência encontrada.\n";
    }

    fin.close();
    fout.close();

    cout << "\nResultados salvos em '" << nomeTxt << "'\n";
}

}