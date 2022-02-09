#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;                                  // 图的结点数
public:
    int *DS_ptr;
    Graph(int V)
    {
        this->V = V;
        DS_ptr = new int[V];
    }
    void DisjointSet_init (void)
    {
        for (int i = 0; i < V; i++)
            DS_ptr[i] = i;
    }
    void DisjointSet_union(int x, int y)
    {
        x = DisjointSet_find(x);
        y = DisjointSet_find(y);
        x < y ? DS_ptr[y] = x : DS_ptr[x] = y;
    }
    int  DisjointSet_find (int x)
    {
        return (x == DS_ptr[x] ? x : (DS_ptr[x] = DisjointSet_find(DS_ptr[x])));
    }
};

int main(void)
{
    // freopen("data.in", "r", stdin);
    //  算法例子
    int N, M;
    cin >> N >> M;
    Graph g(N);
    g.DisjointSet_init();
    while (M--)
    {
        int u, v;
        cin >> u >> v;
        g.DisjointSet_union(u, v);
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << (g.DisjointSet_find(i) == g.DisjointSet_find(j)) ? "Yes\n" : "No\n";
    return 0;
}