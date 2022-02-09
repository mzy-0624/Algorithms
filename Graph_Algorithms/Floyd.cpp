#include <bits/stdc++.h>
using namespace std;
class Graph {
    int V;
public:
	vector<vector<int>> ans;
    Graph(int V)
    {
        this->V = V;
		ans.resize(V);
        for (int i = 0; i < V; i++)
        {
			ans[i].resize(V);
			for (int j = 0; j < V; j++)
				ans[i][j] = 0x3f3f3f3f;
            ans[i][i] = 0;
        }
    }
	~Graph()
	{
		ans.clear();
	}
    #define Floyd_addedge(u, v, w, is_directed) addedge(u, v, w, is_directed)
    void addedge(int u, int v, int w, bool is_directed)
    {
        ans[u][v] = w;
        if (!is_directed)
			ans[v][u] = w;
    }
    void Floyd(void)
    {
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
    }
};
int main(void)
{
#ifdef __DEBUG__
    freopen("data.in", "r", stdin);
#endif
    int N, M;
    cin >> N >> M;
    Graph g(N);
    while (M--)
    {
        int u, v, w;
	    cin >> u >> v >> w;
        g.Floyd_addedge(u, v, w, 1);
    }
    g.Floyd();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << "(" << i << ", " << j << "): " << g.ans[i][j] << endl;
    return 0;
}
