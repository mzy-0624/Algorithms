#include <bits/stdc++.h>
using namespace std;
#define Node pair<int, int>
#define cost first
#define to   second
class Graph {
    int V;
    vector<vector<Node>> edges;
    unordered_set<int>   visited;
    vector<int>          minDis;
public:
    Graph(int V)
    {
        this->V = V;
        edges.resize(V);
        minDis.resize(V);
    }
    void addedge(int u, int v, int w, bool is_directed)
    {
		edges[u].push_back({w, v});
        if (!is_directed)
			edges[v].push_back({w, u});
    }
    void Dijkstra(int src)
    {
        visited.clear();
        for (int i = 0; i < V; i++)
            minDis[i] = 0x3f3f3f3f;
        minDis[src] = 0;
        priority_queue<Node, vector<Node>, greater<Node>> q;
        q.push({0, src});
        while (!q.empty())
        {
            Node t = q.top();
            q.pop();
            if (visited.find(t.to) != visited.end())
                continue;
            visited.insert(t.to);
            for (auto& k : edges[t.to])
            {
                minDis[k.to] = min(minDis[k.to], t.cost + k.cost);
                q.push({minDis[k.to], k.to});
            }
        }
    }
    int getDis(int des) const
    {
        return minDis[des];
    }
};

int main(void)
{
#ifdef __DEBUG__ON
	freopen("data.in", "r", stdin);
#endif
    int N, M;
    cin >> N >> M;
    Graph g(N);
    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addedge(u, v, w, 0); // 无向边
        // g.addedge(u, v, w, 1); // 有向边
    }
    g.Dijkstra(0);
    for (int i = 0; i < N; i++)
        cout << i << ": " << g.getDis(i) << endl;
    return 0;
}
