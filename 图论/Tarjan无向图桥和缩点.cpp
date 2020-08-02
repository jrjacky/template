// tarjan算法求无向图的桥、边双连通分量并缩点
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int SIZE = 100010;
int head[SIZE], ver[SIZE * 2], Next[SIZE * 2];
int dfn[SIZE], low[SIZE], c[SIZE];
int n, m, tot, num, dcc, tc;
bool bridge[SIZE * 2];
int hc[SIZE], vc[SIZE * 2], nc[SIZE * 2];

void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void add_c(int x, int y) {
	vc[++tc] = y, nc[tc] = hc[x], hc[x] = tc;
}

void tarjan(int x, int in_edge) {
	dfn[x] = low[x] = ++num;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!dfn[y]) {
			tarjan(y, i);
			low[x] = min(low[x], low[y]);
			if (low[y] > dfn[x])
				bridge[i] = bridge[i ^ 1] = true;
		}
		else if (i != (in_edge ^ 1))
			low[x] = min(low[x], dfn[y]);
	}
}

void dfs(int x) {
	c[x] = dcc;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (c[y] || bridge[i]) continue;
		dfs(y);
	}
}

int main() {
	cin >> n >> m;
	tot = 1;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i, 0);
	for (int i = 2; i < tot; i += 2)
		if (bridge[i])
			printf("%d %d\n", ver[i ^ 1], ver[i]);

	for (int i = 1; i <= n; i++)
		if (!c[i]) {
			++dcc;
			dfs(i);
		}
	printf("There are %d e-DCCs.\n", dcc);
	for (int i = 1; i <= n; i++)
		printf("%d belongs to DCC %d.\n", i, c[i]);

	tc = 1;
	for (int i = 2; i <= tot; i++) {
		int x = ver[i ^ 1], y = ver[i];
		if (c[x] == c[y]) continue;
		add_c(c[x], c[y]);
	}
	printf("缩点之后的森林，点数 %d，边数 %d\n", dcc, tc / 2);
	for (int i = 2; i < tc; i += 2)
		printf("%d %d\n", vc[i ^ 1], vc[i]);
}

