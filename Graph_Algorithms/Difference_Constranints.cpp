#include <bits/stdc++.h>
using namespace std;
#define Node 	pair<int, int>
#define cost	first
#define to		second
class Graph {
    int V;
    vector<vector<Node>> edges;
    vector<bool> visited;
public:
    vector<int> DC_dist;
    int *DC_dist;
    Graph(int V)
    {
        this->V = V;
        edges.resize(V);
        visited.reserve(V);
        DC_dist.resize(V);
    }
    #define DC_addedge(u, v, w) addedge(u, v, w, true)
    void addedge (int u, int v, int w, bool is_directed)
    {
        edges[u].push_back({v, w});
        if (!is_directed)
            edges[v].push_back({u, w});
    }
    void add_super_source(void)
    {
        for (int i = 1; i < V; i++)
            DC_addedge(0, i, 0);
    }
    void SPFA(int src)
    {
        for (int i = 0; i < V; i++)
            DC_dist[i] = 0x3f3f3f3f;
        visited.clear();
		visited[src] = 1;
		DC_dist[src] = 0;
		queue<int> q;
		q.push(src);
		while (!q.empty()) 
		{
			int from = q.front(); 
			q.pop();
			visited[from] = 0;
			for (auto & edge : edges[from])
			{
				int to = edge.to, cost = edge.cost;
				if (DC_dist[to] > DC_dist[from] + cost)
				{
					DC_dist[to] = DC_dist[from] + cost;
					if (!visited[to])
					{
						visited[to] = 1;
						q.push(to);
					}
				}
			}
		}
    }
    int DC_ans(void)
    {
        int ans = 0x7f7f7f7f;
        for (int i = 1; i < V; i++)
            ans = min(ans, DC_dist[i]);
        return -ans;            // 返回负的最小值
    }
};
int main(void)
{
    freopen("data.in", "r", stdin);
	// search 差分约束
    int n, m;                   // n 个结点，m 个不等式
    cin >> n >> m;
    Graph g(n + 1);             // 需要添加超级源点，不妨设为 0，所以建一个 n + 1 个结点的图
    while (m--)
    {
        int a, b, c;            // 不等式 a - b <= c，建一条由 b 指向 a，权值为 c 的边
        // u - v >  w ==> u - v >= w - 1 ==> v - u <= 1 - w     g.DC_addedge(u, v, 1 - w);
        // u - v >= w ==> v - u <= -w                           g.DC_addedge(u, v, -w);
        // u - v <  w ==> u - v <= w - 1                        g.DC_addedge(v, u, w - 1);
        // u - v <= w                                           g.DC_addedge(v, u, w);
        g.DC_addedge(b, a, c);
    }
    g.add_super_source();
    g.SPFA(0);
    cout << g.DC_ans() << endl;
    return 0;
}
/*
    也可以将所有不等式化为 a - b >= c 的形式，建一条由 b 指向 a，权值为 c 的边
    然后添加超级源点之后求最长路
    返回 DC_dist 数组的最大值
*/
