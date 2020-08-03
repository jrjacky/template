#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 100010, M = 1000010;
int head[N], ver[M], edge[M], Next[M], d[N];
int n, m, tot;
queue<int> q;
bool v[N];

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void spfa() {
	memset(d, 0x3f, sizeof(d)); // dist����
	memset(v, 0, sizeof(v)); // �Ƿ��ڶ�����
	d[1] = 0; v[1] = 1;
	q.push(1);
	while (q.size()) {
		// ȡ����ͷ
		int x = q.front(); q.pop();
		v[x] = 0;
		// ɨ�����г���
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) {
				// ���£����µĶ�Ԫ������
				d[y] = d[x] + z;
				if (!v[y]) q.push(y), v[y] = 1;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	// �����ڽӱ�
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
	}
	// ��Դ���·��
	spfa();
	for (int i = 1; i <= n; i++)
		printf("%d\n", d[i]);
}

