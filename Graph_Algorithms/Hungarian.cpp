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
    int *Hungarian_belong;
public:
    Graph(int V)
    {
        this->V = V;
        edges             = new vector<Node>[V];
        visited           = new int[V];
        Hungarian_belong  = new int[V];
    }
    #define Hungarian_addedge(u, v) addedge(u, v, 0, true)  // 有向边（为什么？）
    void addedge      (int u, int v, int w, bool is_directed)
    {
        edges[u].push_back(Node(v, w));
        if (!is_directed)
            edges[v].push_back(Node(u, w));
    }
    bool Hungarian_DFS(int x)
    {
        for (auto& edge : edges[x])
        {	
            int i = edge.to;
            if (visited[i] == 0)
            {
                visited[i] = 1;
                if (Hungarian_belong[i] == -1 || Hungarian_DFS(Hungarian_belong[i]))
                {
                    Hungarian_belong[i] = x;
                    return true;
                }
            }
        }
        return false;
    }
    int  Hungarian    (void)
    {
        memset(visited, 0, sizeof(int) * V);
        memset(Hungarian_belong, 0xff, sizeof(int) * V);
        int total = 0;
        for (int i = 0; i < V; i++)
        {
            memset(visited, 0, sizeof(int) * V);
            if (Hungarian_DFS(i))
                total++;
        }
        return total;
    }
};
int main(void)
{
    // freopen("data.in", "r", stdin);
    // Hungarian 算法例子
    int N, M;
    cin >> N >> M;
    Graph g(N);
    while (M--)
    {
        int u, v;
        cin >> u >> v;
        g.Hungarian_addedge(u, v);
    }
    cout << g.Hungarian() << endl;
    return 0;
}
