#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

void mochila(int pMoc, vector<int> valor, vector<int> peso, int n)
{   int i, w;

	// tabela que ser� preenchida
    int V[n + 1][pMoc + 1];

    string valores;
	// inicializando a primeira linha e primeira coluna com 0
	for(w = 0; w <= pMoc; w++)
		V[0][w] = 0;
	for(i = 1; i <= n; i++)
		V[i][0] = 0;

    //Valores come�a com 1 porque a primeira linha e primeira coluna s�o valor 0
	for(i = 1; i <= n; i++)
	{
		for(w = 1; w <= pMoc; w++)
		{
			// verifica se elemento pode fazer parte da solu��o
			if(peso[i - 1] <= w)
			{
				// Verifica o maior valor
                V[i][w] = max(valor[i-1]+V[i-1][w-peso[i-1]],V[i-1][w]);
			}
			else{
				V[i][w] = V[i - 1][w]; //
			}
		}
	}

    i--;
    w--;
	int max_valor = V[n][pMoc];

	cout << "Valor maximo: " << max_valor << endl;
	cout << "\nElementos Escolhidos: " << endl;
    vector <int> element;

	while(V[i][w])
   {    //Verifica se ouve varia��o na tabela, se n�o houve varia��o decrementa o i e testa novamente
		if(V[i][w] == V[i-1][w])
		{
			i--;
		}
		else //Se houve varia��o coloca o elemento na solu��o.
		{
			element.push_back(i);
			i--;
			w = w - peso[i];
		}
    }
    //Imprime os elementos da solu��o
    for(int f = element.size()-1; f>=0; f--)
    {
        cout << element[f] << ", ";
    }

}

int main(int argc, char *argv[])
{
    string url = argv[1];
    string line;
    ifstream file(url);
    int value;
    // capacidade m�xima da mochila: W
	int W;

	// n�mero de elementos
	int n;

	file >> n;
	file >> W;

    vector<int>  peso;
    vector<int>  valor;

	while(!file.eof()){
        file >> value;
        peso.push_back(value);
        file >> value;
        valor.push_back(value);
	}

	// obt�m o m�ximo valor que pode ser colocado na mochila
	mochila(W, valor, peso, n);

	return 0;
}
