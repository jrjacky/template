#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct rec { int x, y, z; } edge[500010];
int fa[100010], n, m, ans;
bool operator <(rec a, rec b) {
    return a.z < b.z;
}
int get(int x) {
    if (x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].z);
    // 按照边权排序
    sort(edge + 1, edge + m + 1);
    // 并查集初始化
    for (int i = 1; i <= n; i++) fa[i] = i;
    // 求最小生成树
    for (int i = 1; i <= m; i++) {
        int x = get(edge[i].x);
        int y = get(edge[i].y);
        if (x == y) continue;
        fa[x] = y;
        ans += edge[i].z;
    }
    cout << ans << endl;
}
