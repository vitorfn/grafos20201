#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define MAXN 110
#define INF 1e8

vi visited;

int dfs1(int atual, int destino)
{

    if (atual == destino)
    {
        return 1;
    }

    if (visited[atual])
    {
        return 0;
    }
    visited[atual] = 1;

    int r = 0;

    return r;
}

int matriz_a[MAXN][MAXN];
int dist_a[MAXN];
int matriz_b[MAXN][MAXN];
int dist_b[MAXN];
int n;
int m;
int processado_a[MAXN];
int processado_b[MAXN];

void Viagem()
{
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
        {
            dist_a[i] = INF;
            dist_b[i] = INF;
            processado_a[i] = 0;
            processado_b[i] = 0;

            for (int j = 1; j <= n; j++)
            {
                matriz_a[i][j] = matriz_b[i][j] = INF;
            }

            matriz_a[i][i] = matriz_b[i][i] = 0;
        }

        while (m--)
        {
            int u;
            int v;
            int tipo;
            int peso;

            cin >> u >> v >> tipo >> peso;

            if (tipo == 0)
            {
                matriz_a[u][v] = peso;
            }

            else
            {
                matriz_b[u][v] = peso;
            }
        }

        processado_a[1] = 0;
        dist_a[1] = 0;

        while (true)
        {
            int davez = -1;
            int menor = INF;

            for (int i = 1; i <= n; i++)
            {
                if (processado_a[i])
                {
                    continue;
                }

                if (dist_a[i] < menor)
                {
                    menor = dist_a[i];
                    davez = i;
                }
            }

            if (davez == -1)
            {
                break;
            }

            for (int i = 1; i <= n; i++)
            {
                dist_a[i] = min(dist_a[i], dist_a[davez] + matriz_a[davez][i]);
            }

            processado_a[davez] = 1;
        }

        dist_b[1] = 0;
        processado_b[1] = 0;

        while (true)
        {
            int davez = -1;
            int menor = INF;

            for (int i = 1; i <= n; i++)
            {
                if (processado_b[i])
                {
                    continue;
                }

                if (dist_b[i] < menor)
                {
                    menor = dist_b[i];
                    davez = i;
                }
            }

            if (davez == -1)
            {
                break;
            }

            for (int i = 1; i <= n; i++)
            {
                dist_b[i] = min(dist_b[i], dist_b[davez] + matriz_b[davez][i]);
            }

            processado_b[davez] = 1;
        }

        cout << min(dist_a[n], dist_b[n]) << endl;
    }
}

int main()
{

    Viagem();
    return 0;
}