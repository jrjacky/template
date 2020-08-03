// 可持久化线段树，建树
struct SegmentTree {
    int lc, rc; // 左右子节点编号
    int dat; // 区间最大值
} tree[MAX_MLOGN];
int tot, root[MAX_M]; // 可持久化线段树的总点数和每个根
int n, a[MAX_N];

int build(int l, int r) {
    int p = ++tot;
    if (l == r) { tree[p].dat = a[l]; return p; }
    int mid = (l + r) >> 1;
    tree[p].lc = build(l, mid);
    tree[p].rc = build(mid + 1, r);
    tree[p].dat = max(tree[tree[p].lc].dat, tree[tree[p].rc].dat);
    return p;
}
// 在main函数中
root[0] = build(1, n);


// 可持久化线段树，单点修改
int insert(int now, int l, int r, int x, int val) {
    int p = ++tot;
    tree[p] = tree[now]; 
    if (l == r) {
        tree[p].dat = val; 
        return p;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) 
tree[p].lc = insert(tree[now].lc, l, mid, x, val);
    else 
tree[p].rc = insert(tree[now].rc, mid + 1, r, x, val);
    tree[p].dat = max(tree[tree[p].lc].dat, tree[tree[p].rc].dat);
    return p;
}
// 在main函数中
root[i] = insert(root[i - 1], 1, n, x, val);
