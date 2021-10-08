#include <vector>
#include <deque>
#include <iostream>

using namespace std;

bool BFS(vector<int> *arestas, vector<int> *chaves, int n)
{

    deque<int> filaInicial;

    bool checado[1001];
    bool alvo[1001];

    for (unsigned i = 0; i < 1001; i++)
    {
        checado[i] = false;
        alvo[i] = false;
    }

    for (unsigned i = 0; i < arestas[1].size(); i++)
    {
        filaInicial.push_back(arestas[1][i]);
    }

    checado[1] = true;

    for (unsigned i = 0; i < chaves[1].size(); i++)
    {
        alvo[chaves[1][i]] = true;
    }
    int cont = 0;

    while (!filaInicial.empty())
    {

        bool encontrado = false;
        for (unsigned i = 0; i < filaInicial.size(); i++)
        {

            int u = filaInicial[i];
            checado[u] = true;

            if (alvo[u])
            {
                encontrado = true;
                alvo[u] = false;

                for (unsigned j = 0; j < chaves[u].size(); j++)
                {
                    alvo[chaves[u][j]] = true;
                }

                filaInicial.erase(filaInicial.begin() + i);
                cont++;

                for (unsigned j = 0; j < arestas[u].size(); j++)
                {
                    int v = arestas[u][j];
                    if (!checado[v])
                    {
                        filaInicial.push_back(v);
                    }
                }
                break;
            }
        }

        if (!encontrado)
        {
            break;
        }
    }

    if (cont == n - 1)
    {
        return true;
    }

    return false;
}

int main()
{

    int nVertices, mArestas, aux1, aux2, kChave;

    while (cin >> nVertices >> mArestas)
    {
        vector<int> arestas[1001];
        vector<int> chaves[1001];

        for (int i = 0; i < mArestas; i++)
        {
            cin >> aux1 >> aux2;
            arestas[aux1].push_back(aux2);
            arestas[aux2].push_back(aux1);
        }

        for (int i = 2; i <= nVertices; i++)
        {
            cin >> kChave;
            chaves[kChave].push_back(i);
        }

        bool deuCerto = BFS(arestas, chaves, nVertices);
        
        if (deuCerto)
        {
            cout << "sim" << endl;
        }
        else
        {
            cout << "nao" << endl;
        }
    }

    return 0;
}
