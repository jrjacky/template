next[1] = 0;
for (int i = 2, j = 0; i <= n; i++) {
	while (j > 0 && a[i] != a[j+1]) j = next[j];
	if (a[i] == a[j+1]) j++;
	next[i] = j;
}

for (int i = 1, j = 0; i <= m; i++) {
	while (j > 0 && (j == n || b[i] != a[j+1])) j = next[j];
	if (b[i] == a[j+1]) j++;
	f[i] = j;
	// if (f[i] == n)，此时就是A在B中的某一次出现
}
