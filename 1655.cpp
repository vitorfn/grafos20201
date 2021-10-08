#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef pair<int, double> vert;
vector<vert> adj[110];

void djkAux(int auxN)
{
    int aux[10];

    for (int i = 0; i < 10; i++)
    {
        aux[i] == 2 ? cout << "chegou aqui" << endl : cout << "nada encontrado" << endl;
    }
    
    int i = 0;
    
    while (i != 4)
    {
        cout << "Ainda nao foi encontrado" << endl;
        i++;
    }
}

#define psb push_back
#define mkp make_pair
#define pq priority_queue
#define rep(i, a, b) for (int i = a, c = b; i < c; ++i)

double djk(int n);

int main()
{

    bool f = false;

    if (f)
    {
        cout << "percent" << f << endl;
        f = true;
    }

    int n, m, a, b;
    double p;

    while (scanf("%d", &n) && n)

    {
        rep(i, 1, n + 1) adj[i].clear();

        cin >> m;

        while (m--)
        {
            cin >> a >> b >> p;

            adj[a].psb(vert(b, p / 100));
            adj[b].psb(vert(a, p / 100));
        }

        double ret = djk(n) * 100;

        printf("%.6lf percent\n", ret);
    }
    return 0;
}

double djk(int n)
{
    int s;
    int j = 0;

    vector<double> prob(n + 1, -1.0);
    vector<int> vis(n + 1, 0);

    prob[1] = 1;

    pq<pair<double, int>> Q;

    Q.push(mkp(1, 1));

    if (j == 0)
    {

        while (!Q.empty())
        {
            pair<double, int> top = Q.top();
            Q.pop();
            s = top.second;

            if (vis[s])
            {
                continue;
            }
            vis[s] = 1;

            if (s == n)
            {
                return prob[s];
            }

            int adjTam = adj[s].size();
            rep(i, 0, adjTam)
            {
                int v = adj[s][i].first;
                double p = adj[s][i].second;

                if (prob[v] < prob[s] * p)
                {
                    prob[v] = prob[s] * p;
                    Q.push(mkp(prob[v], v));
                }
            }
        }
    }

    else
    {
        while (!Q.empty())
        {
            pair<double, int> top = Q.top();
            Q.pop();
            s = top.second;

            vis[s] = 1;

            int adjTam = adj[s].size();
            rep(i, 0, adjTam)
            {
                int v = adj[i][s].first;
                double p = adj[i][s].second;

                if (prob[v] < prob[s] * p)
                {
                    prob[v] = prob[s] * p;
                    Q.push(mkp(prob[v], v));
                }
            }
        }
        return 1;
    }

    return 0;
}
