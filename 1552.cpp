#include <bits/stdc++.h>
#include <iostream>

using namespace std;

using ii = pair<int, int>;
using edge = pair<double, ii>;
using vi = vector<int>;

#define mkp make_pair
#define psb push_back
#define vetD vector<vector<double>>
#define vetP vector<pair<int, int>>

priority_queue<edge> pq;

class cKruskal
{
    int contador;
    vi superiores;
    vi ordem;

public:
    cKruskal(int V) : contador(V), superiores(V + 1, 0), ordem(V + 1, 0)
    {
        for (int i = 1; i <= V; ++i)
        {
            superiores[i] = i;
        }
    }

    int procura(int u)
    {
        if (superiores[u] == u)
        {
            return u;
        }

        else
        {
            return (superiores[u] = procura(superiores[u]));
        }
    }

    bool confereIguais(int u, int v)
    {
        return procura(u) == procura(v);
    }

    void agrupa(int u, int v)
    {
        if (confereIguais(u, v))
            return;

        int p = procura(u);
        int q = procura(v);

        if (ordem[p] >= ordem[q])
        {
            superiores[q] = p;
        }

        else
        {
            superiores[p] = q;
        }

        if (ordem[p] == ordem[q])
        {
            ++ordem[p];
        }

        contador--;
    }

    int count() const
    {
        return contador;
    }
};

void compara(int V)
{
    cKruskal dk2(V);
    while (not pq.empty())
    {
        auto topoG = pq.top();
        pq.pop();

        if (topoG.second.first < topoG.second.second)
        {
            dk2.agrupa(topoG.second.first, topoG.second.second);
        }

        else if (topoG.second.first > topoG.second.second)
        {
            dk2.agrupa(topoG.second.second, topoG.second.first);
        }

        else
        {
            dk2.agrupa(topoG.second.first, topoG.second.first);
            dk2.agrupa(topoG.second.second, topoG.second.second);
        }
    }
}

double kruskal(int V)
{
    cKruskal dKrsk(V);
    double quantidade = 0.0;

    while (not pq.empty())
    {
        auto topoG = pq.top();
        pq.pop();

        double w = -topoG.first;
        int u = topoG.second.first;
        int v = topoG.second.second;

        if (not dKrsk.confereIguais(u, v))
        {
            dKrsk.agrupa(u, v);
            quantidade = quantidade + w;
        }
    }

    return quantidade;
}

int main()
{

    int casosTeste, n, a, b;

    cin >> casosTeste;

    while (casosTeste--)
    {

        vetD v;
        vetP aux;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;

            v.psb({});
            aux.psb(mkp(a, b));
        }

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                double primeiro = (aux[i].first - aux[j].first);
                double segundo = (aux[i].second - aux[j].second);

                double resultado = sqrt(((primeiro) * (primeiro)) + ((segundo) * (segundo)));

                pq.push(edge(-resultado, ii(i, j)));
            }

        printf("%.2lf\n", kruskal(n * n) / 100);
    }

    return 0;
}
