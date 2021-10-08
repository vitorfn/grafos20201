#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

#define MAXN 10001
#define empurrar push_back
#define minimo min(dfs_low[v], dfs_low[u]);
typedef int vetorInt;

using namespace std;

vector<int> grafo[MAXN];

vetorInt pai[MAXN],
dfs_low[MAXN], 
dfs_num[MAXN], 
dfs_parent[MAXN], 
pontosdearticulacao[MAXN];

int dfsNumberCounter, 
dfsRoot, 
dfsRootChildren, 
n, m, q;


int find(int x) {return x == pai[x] ? x : find(pai[x]);};

void join(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y){
		return;}
	if (x > y){
		swap(x, y);}
	pai[y] = x;
}
void dfs(int u)
{
	dfs_low[u] = dfs_num[u] = ++dfsNumberCounter;
	for (unsigned i = 0; i < grafo[u].size(); i++)
	{
		int v = grafo[u][i];
		if (dfs_num[v] == 0)
		{
			dfs_parent[v] = u;
			if (u == dfsRoot){
				dfsRootChildren++;}
			dfs(v);
			if (dfs_low[v] >= dfs_num[u])
			{
				pontosdearticulacao[u] = 1;
			}
			if (dfs_low[v] > dfs_num[u])
			{
				join(u, v);
			}
			dfs_low[u] = minimo;
		}
		else if (v != dfs_parent[u])
		{
			dfs_low[u] = minimo;
		}
	}
}
void Bondy()
{
	while ((cin >> n >> m >> q) and (n or m or q))
	{
		for (int i = 1; i <= n; i++)
		{
			pai[i] = i;
			dfs_low[i] = dfs_num[i] = dfs_parent[i] = pontosdearticulacao[i] = 0;
			grafo[i].clear();
		}
		dfsNumberCounter = 0;
		while (m--)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			grafo[u].empurrar(v);
			grafo[v].empurrar(u);
		}
		for (int i = 1; i <= n; i++)
		{
			if (dfs_num[i] == 0)
			{
				dfsRoot = i;
				dfsRootChildren = 0;
				dfs(i);
				pontosdearticulacao[i] = (dfsRootChildren > 1);
			}
		}
		while (q--)
		{
			int u, v;
		
			cin >> u >> v;
			printf("%c\n", find(u) == find(v) ? 'Y' : 'N');
		}
		printf("-\n");
	}
}
int main()
{
	Bondy();
	return 0;
}
