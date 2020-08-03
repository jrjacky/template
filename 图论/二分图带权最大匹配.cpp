// ����ͼ��Ȩ���ƥ�䣺KM�㷨
const int N = 105;
int w[N][N]; // ��Ȩ
int la[N], lb[N]; // ���Ҳ���Ķ���
bool va[N], vb[N]; // ���ʱ�ǣ��Ƿ��ڽ�������
int match[N]; // �Ҳ���ƥ������һ���󲿵�
int n, delta, upd[N];

bool dfs(int x) {
	va[x] = 1; // ���ʱ�ǣ�x�ڽ�������
	for (int y = 1; y <= n; y++)
		if (!vb[y])
			if (la[x] + lb[y] - w[x][y] == 0) { // �����ͼ
				vb[y] = 1; // ���ʱ�ǣ�y�ڽ�������
				if (!match[y] || dfs(match[y])) {
					match[y] = x;
					return true;
				}
			}
			else upd[y] = min(upd[y], la[x] + lb[y] - w[x][y]);
	return false;
}

int KM() {
	for (int i = 1; i <= n; i++) {
		la[i] = -(1 << 30); // -inf
		lb[i] = 0;
		for (int j = 1; j <= n; j++)
			la[i] = max(la[i], w[i][j]);
	}
	for (int i = 1; i <= n; i++)
		while (true) { // ֱ���󲿵��ҵ�ƥ��
			memset(va, 0, sizeof(va));
			memset(vb, 0, sizeof(vb));
			delta = 1 << 30; // inf
			for (int j = 1; j <= n; j++) upd[j] = 1 << 30; 
			if (dfs(i)) break;
			for (int j = 1; j <= n; j++)
				if (!vb[j]) delta = min(delta, upd[j]);
			for (int j = 1; j <= n; j++) { // �޸Ķ���
				if (va[j]) la[j] -= delta;
				if (vb[j]) lb[j] += delta;
			}
		}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += w[match[i]][i];
	return ans;
}
