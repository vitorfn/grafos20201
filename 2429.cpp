#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> pilha;
typedef vector<int> vetor;
vetor grafo[10010], transposto[10010];
bool visitado[10010];

void PreencherGrafo(int n);
void GrafoDFS(int x);
void TransportadosDFS(int x);

int main()
{
	int n;
	cin >> n;

	PreencherGrafo(n);
	GrafoDFS(1);

	for (int i = 1; i <= n; i++)
	{
		if (!visitado[i])
		{
			cout << "N" << endl;
			return 0;
		}
	}

	TransportadosDFS(pilha.top());

	for (int i = 1; i <= n; i++)
	{
		if (visitado[i])
		{
			cout << "N" << endl;
			return 0;
		}
	}

	cout << "S" << endl;

	return 0;
}

void PreencherGrafo(int n)
{
	for (int i = 0; i < n; i++)
	{
		int u, v;

		cin >> u >> v;

		grafo[u].push_back(v);
		transposto[v].push_back(u);
	}
}

void GrafoDFS(int pos)
{
	visitado[pos] = true;
	for (unsigned i = 0; i < grafo[pos].size(); i++)
	{
		int v = grafo[pos][i];
		if (!visitado[v])
		{
			GrafoDFS(v);
		}
	}
	pilha.push(pos);
}

void TransportadosDFS(int pos)
{
	visitado[pos] = false;
	for (unsigned i = 0; i < transposto[pos].size(); i++)
	{
		int v = transposto[pos][i];
		if (visitado[v])
		{
			TransportadosDFS(v);
		}
	}
}
