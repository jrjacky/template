//Luogu 3388
#include<iostream>
using namespace std;
struct ppap
{
    int nxt,to;
}e[200010];
int n,m,cnt,tot,ans,head[1000010],dfn[1000010],low[1000010],cut[1000010];
void add(int x,int y)
{
   e[++tot].to=y,e[tot].nxt=head[x],head[x]=tot;
}
void tarjan(int u,int fa)
{
    int son=0;
    dfn[u]=low[u]=++cnt;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]){
        	tarjan(v,fa);
        	low[u]=min(low[u],low[v]);
        	if(low[v]>=dfn[u]&&u!=fa) cut[u]=1;
            if(u==fa) son++;
        }
        low[u]=min(low[u],dfn[v]);
    }   
    if(son>=2&&fa==u) cut[u]=1;        
}
int main()
{
    cin>>n>>m;
    for(int i=1,x,y;i<=m;i++) cin>>x>>y,add(x,y),add(y,x);
    for(int i=1;i<=n;i++)
    if(dfn[i]==0)
    tarjan(i,i);
    for(int i=1;i<=n;i++)
    if(cut[i]) ans++;
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) if(cut[i]) cout<<i<<" ";
    return 0;
}
