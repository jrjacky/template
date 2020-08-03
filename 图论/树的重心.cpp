void dfs(int x) {
	v[x] = 1; size[x] = 1; // 子树x的大小
	int max_part = 0; // 删掉x后分成的最大子树的大小
	for (int i = head[x]; i; i = next[i]) {
		int y = ver[i];
		if (v[y]) continue; // 点y已经被访问过了
		dfs(y);
		size[x] += size[y];
		max_part = max(max_part, size[y]);
	}
	max_part = max(max_part, n - size[x]);
	if (max_part < ans) {
		ans = max_part;
		pos = x;
	}
}
