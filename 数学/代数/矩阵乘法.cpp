void X(int a[100][100], int b[100][100]) {
	int c[100][100];
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= p; i++)
		for (int k = 1; k <= p; k++)
			if (a[i][k])
				for (int j = 1; j <= p; j++)
					c[i][j] += a[i][k] * b[k][j];
}
