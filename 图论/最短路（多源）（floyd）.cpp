#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[310][310];
int n, m;

int main() {
	cin >> n >> m;
	// 把d数组初始化为邻接矩阵
	memset(d, 0x3f, sizeof(d));
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		d[x][y] = min(d[x][y], z);
	}
	// floyd求任意两点间最短路径
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	// 输出
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) printf("%d ", d[i][j]);
		puts("");
	}
}

