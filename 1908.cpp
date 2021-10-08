#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN 11234
#define MAXK 1123
#define empurrar push_back
#define vi vector<int>
#define fila queue<int>

vector<vi> ls(MAXN);
vector<vi> cs(MAXK);

int distancia[MAXN];

void loop(int k)
{
	int l, c;
	for (int i = 0; i < k; i++)
	{
		cin >> l;
		for (int j = 0; j < l; j++)
		{
			cin >> c;
			ls[c].empurrar(i);
			cs[i].empurrar(c);
		}
	}
}

int bfs(int s, int d)
{
	int u, v;
	memset(distancia, -1, sizeof(distancia));
	fila filaBFS;

	distancia[s] = 0;
	
	filaBFS.push(s);

	while (!filaBFS.empty())
	{
		u = filaBFS.front();
		filaBFS.pop();

		if (u == d)
		{
			break;
		}
		for (int i = 0; i < (int)ls[u].size(); i++)
		{
			for (int j = 0; j < (int)cs[ls[u][i]].size(); j++)
			{
				v = cs[ls[u][i]][j];
				if (distancia[v] == -1)
				{
					distancia[v] = distancia[u] + 1;
					filaBFS.push(v);
				}
			}
		}
	}
	return distancia[d];
}

int main()
{
	int n, k;
	cin >> n >> k;
	loop(k);
	cout << bfs(1, n) << endl;
	return 0;
}
