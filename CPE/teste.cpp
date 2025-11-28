#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_LINE 512
using namespace std;

int main()
{
    char url[MAX_LINE];
    char destino[MAX_LINE];

    HRESULT dl;

    typedef HRESULT(WINAPI* URLDownloadToFileA_t)(LPUNKNOWN pCaller, LPCSTR szURL, LPCSTR szFileName, DWORD dwReserved, void* lpfnCB);
    URLDownloadToFileA_t xURLDownloadToFileA;
    xURLDownloadToFileA = (URLDownloadToFileA_t)GetProcAddress(LoadLibraryA("urlmon"), "URLDownloadToFileA");

    cout << "Digite a URL a ser baixada (ex: http://www.unb.br):\n";
    cin >> url;

    cout << "\nDigite o nome do arquivo destino para salvar o HTML (ex: pagina.html):\n";
    cin >> destino;

    cout << "\nEspere um momento, baixando o arquivo ...\n";

    dl = xURLDownloadToFileA(NULL, url, destino, 0, NULL);

    if (dl == S_OK)
    {
        cout << "\nArquivo foi baixado com sucesso!\n";

        // ========== LER HTML COMPLETO ==========
        ifstream fin(destino);
        if (!fin.is_open())
        {
            cout << "Erro ao abrir o arquivo HTML baixado.\n";
            return 0;
        }

        string html;
        string temp;

        while (getline(fin, temp))
        {
            html += temp + "\n"; // Concatena todo o HTML
        }

        fin.close();

        // ========== BUSCA DE PALAVRA-CHAVE ==========

        string chave;
        cout << "Digite a palavra-chave que deseja buscar no HTML: ";
        cin >> chave;

        string nomeTxt;
        cout << "Digite o nome do arquivo TXT para salvar os resultados (ex: resultado.txt): ";
        cin >> nomeTxt;

        // converter para minúsculas (busca case-insensitive)
        string htmlLower = html;
        string chaveLower = chave;
        transform(htmlLower.begin(), htmlLower.end(), htmlLower.begin(), ::tolower);
        transform(chaveLower.begin(), chaveLower.end(), chaveLower.begin(), ::tolower);

        ofstream fout(nomeTxt);
        fout << "Resultados da busca por: " << chave << "\n\n";

        size_t pos = 0;
        int ocorrencias = 0;

        // busca todas as ocorrências
        while ((pos = htmlLower.find(chaveLower, pos)) != string::npos)
        {
            ocorrencias++;

            // Coletar contexto da ocorrência
            size_t inicio = (pos > 40 ? pos - 40 : 0);
            size_t fim = pos + chave.length() + 40;
            if (fim > html.size()) fim = html.size();

            string trecho = html.substr(inicio, fim - inicio);

            // Exibir e salvar
            cout << "Ocorrência " << ocorrencias << ": ... " << trecho << " ...\n\n";
            fout << "Ocorrência " << ocorrencias << ": ... " << trecho << " ...\n\n";

            pos += chave.length(); // avança no texto
        }

        if (ocorrencias == 0)
        {
            cout << "\nNenhuma ocorrência encontrada.\n";
            fout << "Nenhuma ocorrência encontrada.\n";
        }
        else
        {
            cout << "\nTotal de ocorrências encontradas: " << ocorrencias << "\n";
        }

        fout.close();
        cout << "\nResultados salvos em '" << nomeTxt << "'\n";
    }
    else if (dl == E_OUTOFMEMORY)
    {
        cout << "\nErro: Memória insuficiente!";
        return 0;
    }
    else
    {
        cout << "\nErro desconhecido ao baixar o arquivo!";
        return 0;
    }

    return 0;
}
