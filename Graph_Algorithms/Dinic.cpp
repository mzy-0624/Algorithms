#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int v, flow, C, rev;
    Edge (int v, int flow, int C, int rev)
    {
        this->v    = v;
        this->flow = flow;
        this->C    = C;
        this->rev  = rev;
    }
};
class Graph
{
    int V;
    int *level;
    vector<Edge> *Dinic_edges;
public:
    Graph(int V)
    {
        this->V = V;
        level       = new int[V];
        Dinic_edges = new vector<Edge>[V];
    }
    void Dinic_addedge (int u, int v, int C)
    {
        Dinic_edges[u].push_back(Edge(v, 0, C, (int)Dinic_edges[v].size()));
        Dinic_edges[v].push_back(Edge(u, 0, 0, (int)Dinic_edges[u].size()));
    }
    bool Dinic_BFS     (int s, int t)
    {
        memset(level, 0xff, sizeof(int) * V);
        level[s] = 0;
        list<int> q;
        q.push_back(s);
        vector<Edge>::iterator i;
        while (!q.empty())
        {
            int u = q.front();
            q.pop_front();
            for (i = Dinic_edges[u].begin(); i != Dinic_edges[u].end(); i++)
            {
                Edge &e = *i;
                if (level[e.v] < 0 && e.flow < e.C)
                {
                    level[e.v] = level[u] + 1;
                    q.push_back(e.v);
                }
            }
        }
        return level[t] < 0 ? false : true;
    }
    int  Dinic_sendflow(int u, int flow, int t, int start[])
    {
        if (u == t)
            return flow;
        for ( ; start[u] < Dinic_edges[u].size(); start[u]++)
        {
            Edge &e = Dinic_edges[u][start[u]];
            if (level[e.v] == level[u] + 1 && e.flow < e.C)
            {
                int curr_flow = min(flow, e.C - e.flow);
                int temp_flow = Dinic_sendflow(e.v, curr_flow, t, start);
                if (temp_flow > 0)
                {
                    e.flow += temp_flow;
                    Dinic_edges[e.v][e.rev].flow -= temp_flow;
                    return temp_flow;
                }
            }
        }
        return 0;
    }
    int  Dinic_maxflow (int s, int t)
    {
        if (s == t)
            return -1;
        int total = 0;
        while (Dinic_BFS(s, t) == true)
        {
            int *start = new int[V + 1];
            while (int flow = Dinic_sendflow(s, INT_MAX, t, start))
                total += flow;
        }
        return total;
    }
};

int main(void)
{
    // freopen("data.in", "r", stdin);
    // Dinic 算法例子
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    Graph g(N + 2);
    while (M--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g.Dinic_addedge(u, v, c);
    }
    cout << g.Dinic_maxflow(S, T) << endl;
    return 0;
}
