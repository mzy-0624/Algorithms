#include <bits/stdc++.h>
using namespace std;
struct Node {
    int to, cost;
    Node (int to, int cost)
    {
        this->to = to;
        this->cost = cost;
    }
    bool operator>(const Node& node) const
    {
        return this->cost > node.cost;
    }
};
class Graph
{
    int V;
    vector<Node> *edges;
    int *visited;
public:
    priority_queue<Node, vector<Node>, greater<Node>> Prim_edges;
    Graph(int V)
    {
        this->V = V;
        edges   = new vector<Node>[V];
        visited = new int[V];
    }
    #define Prim_addedge(u, v, w) addedge(u, v, w, false)
    void addedge         (int u, int v, int w, bool is_directed)
    {
        edges[u].push_back(Node(v, w));
        if (!is_directed)
            edges[v].push_back(Node(u, w));
    }
    void Prim_updateedges(int x)
    {
        for (auto & i : edges[x])
            if (!visited[i.to])
                Prim_edges.push(i);
    }
    int  Prim            (void)
    {
        memset(visited, 0, sizeof(int) * V);
        int Prim_ans = 0;
        visited[0] = 1;
        Prim_updateedges(0);
        while (!Prim_edges.empty())
        {
            Node Top = Prim_edges.top();
            if (visited[Top.to])
            {
                Prim_edges.pop();
                continue;
            }
            Prim_ans += Top.cost;
            visited[Top.to] = 1;
            Prim_edges.pop();
            Prim_updateedges(Top.to);
        }
        return Prim_ans;
    }
};


int main(void)
{
    // freopen("data.in", "r", stdin);
    //  算法例子
    int N, M;
    cin >> N >> M;
    Graph g(N);
    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.Prim_addedge(u, v, w);
    }
    cout << g.Prim() << endl;
    return 0;
}