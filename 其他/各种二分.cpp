// �ڵ�����������a�в���>=x��������С��һ������x��x�ĺ�̣�
while (l < r) {
	int mid = (l + r) / 2;
	if (a[mid] >= x) r = mid; else l = mid + 1;
}

// �ڵ�����������a�в���<=x����������һ������x��x��ǰ����
while (l < r) {
	int mid = (l + r + 1) / 2;
	if (a[mid] <= x) l = mid; else r = mid - 1;
}

// ʵ������֣�����eps��
while (l + eps < r) {
	double mid = (l + r) / 2;
	if (calc(mid)) r = mid; else l = mid; 
}

// ʵ������֣��涨ѭ��������
for (int i = 0; i < 100; i++) {
	double mid = (l + r) / 2;
	if (calc(mid)) r = mid; else l = mid;	
}
