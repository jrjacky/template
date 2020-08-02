// �����������ģ��
#include<cstdlib>
#include<ctime>

int random(int n) {
    return (long long)rand() * rand() % n;
}

int main() {
    srand((unsigned)time(0));
    // ...��������...
}

// ʵ�������������������
// ������100000������ֵ��1000000000�ڵ�����
int n = random(100000) + 1;
int m = 1000000000;
for (int i = 1; i <= n; i++) {
    a[i] = random(2 * m + 1) - m;
}

// ʵ�����������������
for (int i = 1; i <= m; i++) {
    int l = random(n) + 1;
    int r = random(n) + 1;
    if (l > r) swap(l, r);
    printf("%d %d\n", l, r);
}

// ʵ�������������
for (int i = 2; i <= n; i++) {
    // �� 2~n ֮���ÿ���� i �� 1~i-1 ֮��ĵ������һ����
    int fa = random(i - 1) + 1;
    int val = random(1000000000) + 1;
    printf("%d %d %d\n", fa, i, val);
}

// ʵ�����������ͼ
// ����ͼ����ͨ�������رߡ��Ի�
pair<int, int> e[1000005]; // ��������
map< pair<int, int>, bool > h; // ��ֹ�ر�
// ������һ��������֤��ͨ
for (int i = 1; i < n; i++) {
    int fa = random(i) + 1;
    e[i] = make_pair(fa, i + 1);
    h[e[i]] = h[make_pair(i + 1, fa)] = 1;
}
// ������ʣ��� m-n+1 ����
for (int i = n; i <= m; i++) {
    int x, y;
    do {
        x = random(n) + 1, y = random(n) + 1;
    } while (x == y || h[make_pair(x, y)]);
    e[i] = make_pair(x, y);
    h[e[i]] = h[make_pair(y, x)] = 1;
}
// ������ң����
random_shuffle(e + 1, e + m + 1);
for (int i = 1; i <= m; i++)
    printf("%d %d\n", e[i].first, e[i].second);


// Windowsϵͳ���ĳ���
#include<cstdlib>
#include<cstdio>
#include<ctime>
int main() {
    for (int T = 1; T <= 10000; T++) {
        // �����趨�ʵ���·��
        system("C:\\random.exe");
        // ���ص�ǰ�����Ѿ����е�CPUʱ�䣬windows�µ�λms����unix�µ�λs
        double st = clock();
        system("C:\\sol.exe");
        double ed = clock();
        system("C:\\bf.exe");
        if (system("fc C:\\data.out C:\\data.ans")) {
            puts("Wrong Answer");
            // ���������˳�����ʱdata.in��Ϊ������������ݣ����˹����㡢����
            return 0;
        }
        else {
            printf("Accepted, ���Ե� #%d, ��ʱ %.0lfms\n", T, ed - st);
        }
    }
}
