//Luogu 2495 
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
stack<int> ss;
vector<int> xuf;
vector<pair<int,int> > sb[300010],xs[300010];
int n,m,now,sum,ki,dep[300010],h[300010],dfn[300010],fa[300010][20],xu[300010];
long long dis[300010],f[300010];
int cmp(const int &a,const int &b)
{
    return dfn[a]<dfn[b];
}
void add(int x,int y)
{
    if(dep[x]>dep[y]) swap(x,y);
    xs[x].push_back(make_pair(y,dis[y]));
    xs[y].push_back(make_pair(x,dis[y]));
}
void dfs(int now,int pre)
{
    for(int a=1;a<=18;a++) fa[now][a]=fa[fa[now][a-1]][a-1];
    dfn[now]=++sum;
    int SIZE=sb[now].size();
    for(int i=0;i<SIZE;i++){
        int nxt=sb[now][i].first;
        long long len=sb[now][i].second;
        if(nxt==pre) continue;
        dep[nxt]=dep[now]+1;
        dis[nxt]=min(dis[now],len);
        fa[nxt][0]=now;
        dfs(nxt,now);
    }
}
int lca(int x,int y)
{
    if(dep[y]>dep[x]) swap(x,y);
    for(int i=18;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    if(x==y) return x;
    for(int i=18;i>=0;i--) if(fa[x][i]!=fa[y][i]){
        x=fa[x][i];
        y=fa[y][i];
    }
    return fa[x][0];
}
void buildxs()
{
    xuf.push_back(1),ss.push(1);
    for(int i=1;i<=ki;i++){
        int now=h[i],x=ss.top(),LCA=lca(x,now);
        xuf.push_back(now);
        ss.pop();
        if(dep[LCA]==dep[x]){ss.push(x),ss.push(now);continue;}
        while(!ss.empty()){
            int y=ss.top();
            if(dep[y]<=dep[LCA]){
                if(dep[LCA]!=dep[y]){
                    ss.push(LCA);
                    xuf.push_back(LCA);
                }
                break;
            }
            ss.pop();
            add(x,y),x=y;
        }
        ss.push(now);
        add(x,LCA);
    }
    if(!ss.empty()){
        int x=ss.top();
        ss.pop();
        while(!ss.empty()){
            int y=ss.top();
            ss.pop();
            add(x,y),x=y;
        }
    }
}
void DP(int x,int fa)
{
    int SIZE=xs[x].size();
    if(SIZE==1&&fa!=-1) return;
    for(int i=0;i<SIZE;i++){
        int nxt=xs[x][i].first;
        long long len=xs[x][i].second;
        if(nxt==fa) continue;
        DP(nxt,x);
        if(xu[nxt]) f[x]+=len;
        else f[x]+=min(len,f[nxt]);
    }
}
int main()
{
    cin>>n;
    for(int i=1,u,v,w;i<n;i++){
        cin>>u>>v>>w;
        sb[u].push_back(make_pair(v,w)),sb[v].push_back(make_pair(u,w));
    }
    cin>>m;
    dep[1]=1,dis[1]=0x7fffffffffffffff;
    dfs(1,0);
    while(m--){
        cin>>ki;
        for(int i=1;i<=ki;i++) cin>>h[i];
        sort(h+1,h+1+ki,cmp);
        for(int i=1;i<=ki;i++) xu[h[i]]=1;
        buildxs();
        DP(1,-1);
        cout<<f[1]<<endl;
    	int SIZE=xuf.size();
    	for(int i=0;i<SIZE;i++) f[xuf[i]]=0,xs[xuf[i]].clear();
    	xuf.clear();
        for(int i=1;i<=ki;i++) xu[h[i]]=0;
    }
    return 0;
}
