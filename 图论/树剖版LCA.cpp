//Luogu 3379
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct ppap
{
    int u,v,nxt;
}e[1000010];
int n,m,root,tot,cnt,head[500010],dep[500010],fa[500010],son[500010],siz[500010],top[500010],dfn[500010];
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
    dfn[x]=++cnt,top[x]=Top;
    if(!son[x]) return;
    dfs2(son[x],Top);
    for(int i=head[x];i!=-1;i=e[i].nxt) if(!dfn[e[i].v]) dfs2(e[i].v,e[i].v);
}
int LCA(int x,int y)
{
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) return y;
	return x;
}
int main()
{
    memset(head,-1,sizeof(head));
    cin>>n>>m>>root;
    for(int i=1,x,y;i<=n-1;i++) cin>>x>>y,add(x,y),add(y,x);
    dfs1(root,0,1),dfs2(root,root);
    while(m--){
        int x,y;
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
}
