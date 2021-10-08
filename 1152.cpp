#include <algorithm>
#include <iostream>

using namespace std;

#define mkpar make_pair
#define primeiro first
#define segundo second
#define par pair<int, int>

int pai[200100];
int peso[200100];
int n;
int m;

pair<int, par>  vetor[200100];

int Procura(int x){return pai[x] == x ? x : Procura(pai[x]);}

void join(int x, int y)
{
    x = Procura(x);
    y = Procura(y);
    if (peso[x] < peso[y])
    {
        pai[x] = y;
    }
    else if (peso[x] > peso[y])
    {
        pai[y] = x;
    }
    else
    {
        pai[x] = y;
        peso[y]++;
    }
}

void Kruskall()
{
    while (1)
    {
        int total = 0;
        cin >> n >> m;

        if (n == 0 && m == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            pai[i] = i;
            peso[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            int u, v, peso;
            cin >> u >> v >> peso;
            total += peso;
            vetor[i] = mkpar(peso, mkpar(u, v));
        }
        sort(vetor, vetor + m);
        for (int i = 0; i < m; i++)
        {
            if (Procura(vetor[i].segundo.primeiro) != Procura(vetor[i].segundo.segundo))
            {
                total -= vetor[i].primeiro;
                join(vetor[i].segundo.primeiro, vetor[i].segundo.segundo);
            }
        }
        cout << total << endl;
    }
}

int main()
{
    Kruskall();
    return 0;
}
