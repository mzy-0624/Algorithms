#include <bits/stdc++.h>
using namespace std;
struct Node {
    int to, cost;
    Node (int to, int cost)
    {
        this->to = to;
        this->cost = cost;
    }
};
class Graph
{
    int V;
    vector<Node> *edges;
    int *visited;
    int idx, cnt, *dfn, *low;
    stack<int> s;
public:
    int *Tarjan_ans;            // 结点 i 在 编号为 Tarjan_ans[i] 的强连通分量中
    Graph(int V)
    {
        this->V = V;
        edges      = new vector<Node>[V];
        visited    = new int[V];
        dfn        = new int[V];
        low        = new int[V];
        Tarjan_ans = new int[V];
    }
    #define Tarjan_addedge(u, v) addedge(u, v, 0, true)
    void addedge    (int u, int v, int w, bool is_directed)
    {
        edges[u].push_back(Node(v, w));
        if (!is_directed)
            edges[v].push_back(Node(u, w));
    }
    void Tarjan_init(void)
    {
        idx = cnt = 0;
        stack<int> s_temp;
        s.swap(s_temp);
        memset(dfn, 0, sizeof(int) * V);
        memset(low, 0, sizeof(int) * V);
        memset(Tarjan_ans, 0, sizeof(int) * V);
        memset(visited, 0, sizeof(int) * V);
    }
    void Tarjan     (int pos)
    {
        visited[pos] = 1;
        s.emplace(pos);
        low[pos] = dfn[pos] = ++idx;
        for (auto& Next : edges[pos])
        {
            int nex = Next.to;
            if (!dfn[nex])
            {
                Tarjan(nex);
                low[pos] = min(low[pos], low[nex]);
            }
            else
                if (visited[nex])
                    low[pos] = min(low[pos], dfn[nex]);
        }
        if (low[pos] == dfn[pos] && visited[pos])
        {
            cnt++;
            while (!s.empty() && s.top() != pos)
            {
                Tarjan_ans[s.top()] = cnt;
                visited[s.top()] = 0;
                s.pop();
            }
            if (!s.empty())
                s.pop();
            Tarjan_ans[pos] = cnt;
            visited[pos] = 0;
        }
    }
};
int main(void)
{
    // freopen("data.in", "r", stdin);
    // Tarjan 算法例子
    int N, M;
    cin >> N >> M;
    Graph g(N);
    while (M--)
    {
        int u, v;
        cin >> u >> v;
        g.Tarjan_addedge(u, v);
    }
    g.Tarjan_init();
    g.Tarjan(0);
    for (int i = 0; i < N; i++)
        cout << i << ": " << g.Tarjan_ans[i] << endl;
    return 0;
}
