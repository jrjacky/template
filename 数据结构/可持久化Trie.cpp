// �ɳ־û�Trie�����⣺BZOJ3261
const int N = 600010;
int trie[N*24][2], latest[N*24]; // latest��end�ɺϲ�Ϊһ������
int s[N], root[N], n, m, tot;
// ������Ҫͳ������latest����ʹ�õݹ����s[i]����ǰΪs[i]�ĵ�kλ
void insert(int i, int k, int p, int q) {
	if (k < 0) {
		latest[q] = i;
		return;
	}
	int c = s[i] >> k & 1;
	if (p) trie[q][c ^ 1] = trie[p][c ^ 1];
	trie[q][c] = ++tot;
	insert(i, k - 1, trie[p][c], trie[q][c]);
	latest[q] = max(latest[trie[q][0]], latest[trie[q][1]]);
}

int ask(int now, int val, int k, int limit) {
	if (k < 0) return s[latest[now]] ^ val;
	int c = val >> k & 1;
	if (latest[trie[now][c ^ 1]] >= limit)
		return ask(trie[now][c ^ 1], val, k - 1, limit);
	else
		return ask(trie[now][c], val, k - 1, limit);
}

int main() {
	cin >> n >> m;
	latest[0] = -1;
	root[0] = ++tot;
	insert(0, 23, 0, root[0]);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		s[i] = s[i - 1] ^ x;
		root[i] = ++tot;
		insert(i, 23, root[i - 1], root[i]);
	}
	for (int i = 1; i <= m; i++) {
		char op[2]; scanf("%s", op);
		if (op[0] == 'A') {
			int x; scanf("%d", &x);
			root[++n] = ++tot;
			s[n] = s[n - 1] ^ x;
			insert(n, 23, root[n - 1], root[n]);
		}
		else {
			int l, r, x; scanf("%d%d%d", &l, &r, &x);
			printf("%d\n", ask(root[r - 1], x ^ s[n], 23, l - 1));
		}
	}
}
