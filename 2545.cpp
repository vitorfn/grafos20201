#include <iostream>
#include <deque>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define par <pair<int,int>>
#define juntar make_pair
#define empurrar push_back

vvii grafo;
vi visited, pontes;

int dfs1(int atual, int destino) {
	
 
    if(atual == destino)
		return 1;
		
	if(visited[atual])
		return 0;
		
	visited[atual] = 1;
		
	int r = 0;
	
	for(auto &it : grafo[atual])
		if(pontes[it.second])
			r += dfs1(it.first, destino);
		
	return r;
}

void Tarjan()
{
    int tarefas, finded = 0;
    while (cin >> tarefas)
    {
        int grau[tarefas + 1];
        deque par ordem;
        deque par execucao;

        deque<int> ligacoes[tarefas + 1];
        int a, b, i;

        for (i = 1; i <= tarefas; i++) {
            grau[i] = 0;
        }
        
        for (i = 1; i <= tarefas; i++)
        {
            cin >> a;
            for (int j = 0; j < a; j++)
            {
                cin >> b;
                grau[i]++;
                ligacoes[b].empurrar(i);
            }
        }

        for (i = 1; i <= tarefas; i++)
        {
            if (grau[i] == 0)
            {
                ordem.empurrar(juntar(i, 1));
            }
        }

        int k = 0;

        while (k < ordem.size())
        {
            execucao.empurrar(ordem[k]);
            for (i = 0; i < ligacoes[ordem[k].first].size(); i++)
            {
                grau[ligacoes[ordem[k].first][i]]--;
                if (grau[ligacoes[ordem[k].first][i]] == 0)
                {
                    ordem.empurrar(juntar(ligacoes[ordem[k].first][i], ordem[k].second + 1));
                }
            }
            k++;
        }
        if(finded > 0) {
            dfs1(1, 0);
        }
        
        if (execucao.size() != tarefas) {
            cout << "-1" << endl;
        }
        else
        {
           
            cout << execucao[tarefas - 1].second << endl;
        }
    }
}

int main()
{
    Tarjan();
    return 0;
}
