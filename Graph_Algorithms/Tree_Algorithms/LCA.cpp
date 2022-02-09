#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0;
int b[15] = {};
int d[405] = {};
int fa[405][15] = {};
vector<int> edges[405] = {};
int diff[405] = {};

void dfs(int pos, int par) 
{
	fa[pos][0] = par;
	d[pos] = d[par] + 1;
	for (auto & nex: edges[pos]) 
		if (nex != par) 
			dfs(nex, pos);
}

int find(int x, int y) 
{
	if (d[x] < d[y])
		swap(x, y);
	for (int i = 10; i >= 0; i--)
		if (d[x] - d[y] >= b[i]) 
			x = fa[x][i];
	if (x == y) 
		return x;
	for (int i = 10; i >= 0; i--) 
		if (fa[x][i] != fa[y][i])
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	return fa[x][0];
}

pair<int, int> solve(int pos, int par) 
{
	int cur = diff[pos], ans = 0;
	for (auto & nex: edges[pos]) 
	{
		if (nex == par) 
			continue;
		pair<int, int> p = solve(nex, pos);
		cur += p.first;
		ans = max(ans, p.second);
	}
	ans = max(ans, cur);
	return make_pair(cur, ans);
}

int main(void) 
{
	b[0] = 1;
	for (int i = 1; i <= 10; i++) 
		b[i] = b[i - 1] * 2;
	int T = 0;
	scanf("%d", &T);
	while (T--) 
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			diff[i] = 0;
			edges[i].clear();
		}
		for (int i = 2; i <= n; i++) 
		{
			int u = 0, v = 0;
			scanf("%d%d", &u, &v);
			edges[u].emplace_back(v);
			edges[v].emplace_back(u);
		}
		dfs(1, 0);
		for (int i = 0; i <= n; i++) 
			for (int j = 1; j <= 10; j++)
				fa[i][j] = fa[fa[i][j - 1]][j - 1];
		for (int i = 1; i <= m; i++) 
		{
			int u = 0, v = 0, lca = 0;
			scanf("%d%d", &u, &v);
			diff[u]++;
			diff[v]++;
			diff[lca = find(u, v)]--;
		   	diff[fa[lca][0]]--;
		}
		printf("%d\n", solve(1, 0).second);
	}
	return 0;
}
