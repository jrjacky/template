// tarjan�㷨������ͼ�ĸ�㡢��˫��ͨ����������
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int SIZE = 100010;
int head[SIZE], ver[SIZE * 2], Next[SIZE * 2];
int dfn[SIZE], low[SIZE], stack[SIZE], new_id[SIZE], c[SIZE];
int n, m, tot, num, root, top, cnt, tc;
bool cut[SIZE];
vector<int> dcc[SIZE];
int hc[SIZE], vc[SIZE * 2], nc[SIZE * 2];

void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void add_c(int x, int y) {
	vc[++tc] = y, nc[tc] = hc[x], hc[x] = tc;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++num;
	stack[++top] = x;
	if (x == root && head[x] == 0) { // ������
		dcc[++cnt].push_back(x);
		return;
	}
	int flag = 0;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!dfn[y]) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
			if (low[y] >= dfn[x]) {
				flag++;
				if (x != root || flag > 1) cut[x] = true;
				cnt++;
				int z;
				do {
					z = stack[top--];
					dcc[cnt].push_back(z);
				} while (z != y);
				dcc[cnt].push_back(x);
			}
		}
		else low[x] = min(low[x], dfn[y]);
	}
}

int main() {
	cin >> n >> m;
	tot = 1;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == y) continue;
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) root = i, tarjan(i);
	for (int i = 1; i <= n; i++)
		if (cut[i]) printf("%d ", i);
	puts("are cut-vertexes");
	for (int i = 1; i <= cnt; i++) {
		printf("v-DCC #%d:", i);
		for (int j = 0; j < dcc[i].size(); j++)
			printf(" %d", dcc[i][j]);
		puts("");
	}
	// ��ÿ�����һ���µı��(��Ŵ�cnt+1��ʼ)
	num = cnt;
	for (int i = 1; i <= n; i++)
		if (cut[i]) new_id[i] = ++num;
	// ����ͼ����ÿ��v-DCC�������������и������
	tc = 1;
	for (int i = 1; i <= cnt; i++)
		for (int j = 0; j < dcc[i].size(); j++) {
			int x = dcc[i][j];
			if (cut[x]) {
				add_c(i, new_id[x]);
				add_c(new_id[x], i);
			}
			else c[x] = i; // ������⣬�����������1��v-DCC
		}
	printf("����֮���ɭ�֣����� %d������ %d\n", num, tc / 2);
	printf("��� 1~%d ��Ϊԭͼ��v-DCC����� >%d ��Ϊԭͼ���\n", cnt, cnt);
	for (int i = 2; i < tc; i += 2)
		printf("%d %d\n", vc[i ^ 1], vc[i]);
}
