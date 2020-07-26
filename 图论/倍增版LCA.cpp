//Luogu 3379
#include<iostream>
using namespace std;
struct ppap
{
    int to,nxt;
}e[1000010];
int n,m,s,tot,head[500010],dep[500010],Fa[500010][25],lg[500010];
void add(int x,int y)
{
    e[++tot].to=y,e[tot].nxt=head[x],head[x]=tot;
}
void dfs(int x,int fa)
{
    Fa[x][0]=fa,dep[x]=dep[fa]+1;
    for(int i=1;i<=lg[dep[x]];i++) Fa[x][i]=Fa[Fa[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x);
}
int LCA(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y]) x=Fa[x][lg[dep[x]-dep[y]]-1];
    if(x==y) return x;
    for(int k=lg[dep[x]]-1;k>=0;k--) if(Fa[x][k]!=Fa[y][k]) x=Fa[x][k],y=Fa[y][k];
    return Fa[x][0];
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1,x,y;i<=n-1;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
    dfs(s,0);
    for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),printf("%d\n",LCA(x,y));
}
