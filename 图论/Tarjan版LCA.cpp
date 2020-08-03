// Tarjan算法离线求LCA (模板题：HDOJ2586)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int SIZE = 50010;
int ver[2 * SIZE], Next[2 * SIZE], edge[2 * SIZE], head[SIZE];
int fa[SIZE], d[SIZE], v[SIZE], lca[SIZE], ans[SIZE];
vector<int> query[SIZE], query_id[SIZE];
int T, n, m, tot, t;

void add(int x, int y, int z) {
	ver[++tot] = y; edge[tot] = z; Next[tot] = head[x]; head[x] = tot;
}

void add_query(int x, int y, int id) {
	query[x].push_back(y), query_id[x].push_back(id);
	query[y].push_back(x), query_id[y].push_back(id);
}

int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}

void tarjan(int x) {
	v[x] = 1;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (v[y]) continue;
		d[y] = d[x] + edge[i];
		tarjan(y);
		fa[y] = x;
	}
	for (int i = 0; i < query[x].size(); i++) {
		int y = query[x][i];
		int id = query_id[x][i];
		if (v[y] == 2) {
			int lca = get(y);
			ans[id] = min(ans[id], d[x] + d[y] - 2 * d[lca]);
		}
	}
	v[x] = 2;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			head[i] = 0;
			query[i].clear(), query_id[i].clear();
			fa[i] = i, v[i] = 0;
		}
		tot = 0;
		for (int i = 1; i < n; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z), add(y, x, z);
		}
		for (int i = 1; i <= m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x == y) ans[i] = 0;
			else {
				add_query(x, y, i);
				ans[i] = 1 << 30;
			}
		}
		tarjan(1);
		for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	}
}
