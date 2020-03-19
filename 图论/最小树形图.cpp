//Luogu 4716
#include<iostream>
#include<cstring>
using namespace std;
struct ppap
{
	int u,v,w;
}e[10010];
int n,m,r,tot,fa[110],ra[110],top[110],mine[110];
long long ans;
int work()
{
    while(1){
    	memset(ra,0,sizeof(ra));
    	memset(top,0,sizeof(top));
    	memset(mine,0x7f,sizeof(mine));
        for(int i=1;i<=m;i++) if(e[i].u!=e[i].v&&e[i].w<mine[e[i].v]) fa[e[i].v]=e[i].u,mine[e[i].v]=e[i].w;
        int u=mine[r]=0;
        for(int i=1;i<=n;i++) {
            if(mine[i]==0x7f7f7f7f) return 0;
            ans+=mine[i];
            for(u=i;u!=r&&top[u]!=i&&!ra[u];u=fa[u]) top[u]=i;
            if(u!=r&&!ra[u]){
                ra[u]=++tot;
                for(int v=fa[u];v!=u;v=fa[v]) ra[v]=tot;
            }
        }
		if(!tot) return 1;
        for(int i=1;i<=n;i++) if(!ra[i]) ra[i]=++tot;
        for(int i=1;i<=m;i++) {
            int last=mine[e[i].v];
            if((e[i].u=ra[e[i].u])!=(e[i].v=ra[e[i].v])) e[i].w-=last;
        }
		n=tot,r=ra[r],tot=0;
    }
}
int main()
{
    cin>>n>>m>>r;
    for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,e[i]=(ppap){u,v,w};
    if(work()) cout<<ans;
    else cout<<-1;
}
