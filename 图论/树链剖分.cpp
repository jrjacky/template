//Luogu 3384
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct ppap 
{
    int u,v,nxt;
}e[2000010];
struct Segment_Tree
{
    int l,r,sum,siz,add;
}t[2000010];
int n,m,root,MOD,tot,cnt,a[2000010],b[2000010],head[2000010],dep[2000010],fa[2000010],son[2000010],siz[2000010],top[2000010],dfn[2000010];
void add(int x,int y)
{
    e[++tot].nxt=head[x],head[x]=tot,e[tot].u=x,e[tot].v=y;
}
int dfs1(int x,int Fa,int Dep)
{
    dep[x]=Dep,fa[x]=Fa,siz[x]=1;
    int maxson=-1;
    for(int i=head[x];i!=-1;i=e[i].nxt) if(e[i].v!=Fa){
        siz[x]+=dfs1(e[i].v,x,Dep+1);
        if(siz[e[i].v]>maxson) maxson=siz[e[i].v],son[x]=e[i].v;
    }
    return siz[x];
}
void dfs2(int x,int Top)
{
    dfn[x]=++cnt,a[cnt]=b[x],top[x]=Top;
    if(!son[x]) return;
    dfs2(son[x],Top);
    for(int i=head[x];i!=-1;i=e[i].nxt) if(!dfn[e[i].v]) dfs2(e[i].v,e[i].v);
}
void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r,t[p].siz=r-l+1;
    if(l==r){t[p].sum=a[l];return;}
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].sum=(t[p*2].sum+t[p*2+1].sum+MOD)%MOD;
}
void spread(int p)
{
    if(t[p].add){
    	t[p*2].sum=(t[p*2].sum+t[p*2].siz*t[p].add)%MOD;
    	t[p*2+1].sum=(t[p*2+1].sum+t[p*2+1].siz*t[p].add)%MOD;
    	t[p*2].add=(t[p*2].add+t[p].add)%MOD;
    	t[p*2+1].add=(t[p*2+1].add+t[p].add)%MOD;
    	t[p].add=0;
	}
}
void change(int p,int l,int r,int d)
{
    if(l<=t[p].l&&t[p].r<=r){t[p].sum+=t[p].siz*d,t[p].add+=d;return;}
    spread(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(l<=mid) change(p*2,l,r,d);
    if(r>mid) change(p*2+1,l,r,d);
    t[p].sum=(t[p*2].sum+t[p*2+1].sum+MOD)%MOD;
}
int ask(int p,int l,int r)
{
    int ans=0;
    if(l<=t[p].l&&t[p].r<=r) return t[p].sum;
    spread(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(l<=mid) ans=(ans+ask(p*2,l,r))%MOD;
    if(r>mid)  ans=(ans+ask(p*2+1,l,r))%MOD;
    return ans;
}
void modify(int x,int y,int d)
{
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        change(1,dfn[top[x]],dfn[x],d);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    change(1,dfn[x],dfn[y],d);
}
void query(int x,int y)
{
    int ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans=(ans+ask(1,dfn[top[x]],dfn[x]))%MOD;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans=(ans+ask(1,dfn[x],dfn[y]))%MOD;
    cout<<ans<<endl;
}
int main()
{
    memset(head,-1,sizeof(head));
    cin>>n>>m>>root>>MOD;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1,x,y;i<=n-1;i++) cin>>x>>y,add(x,y),add(y,x);
    dfs1(root,0,1),dfs2(root,root),build(1,1,n);
    while(m--){
        int op,x,y,z;
        cin>>op;
        if(op==1) cin>>x>>y>>z,z%=MOD,modify(x,y,z);
        else if(op==2) cin>>x>>y,query(x,y);
        else if(op==3) cin>>x>>z,change(1,dfn[x],dfn[x]+siz[x]-1,z%MOD);
        else if(op==4) cin>>x,cout<<ask(1,dfn[x],dfn[x]+siz[x]-1)<<endl;
    }
}
