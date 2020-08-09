//Luogu 3376
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
struct ppap
{
	int to,nxt;
	long long w;
}e[10010];
int n,m,s,t,tot=1,head[210],v[210],fr[210];
long long maxflow,flow;
queue<int> q;
void add(int x,int y,int z)
{
	e[++tot].nxt=head[x],head[x]=tot,e[tot].to=y,e[tot].w=z;
	e[++tot].nxt=head[y],head[y]=tot,e[tot].to=x,e[tot].w=0;
}
int dfs(int x,long long flow)
{
	if(x==t) return flow;
	v[x]=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].w&&(!v[e[i].to])){
		long long k=dfs(e[i].to,min(flow,e[i].w));
		if(!k) continue;
		e[i].w-=k,e[i^1].w+=k;
		return k;
	}
	return 0;
}
void FF()
{
	maxflow+=flow,memset(v,0,sizeof(v));
}
int main()
{
	memset(head,0,sizeof(head));
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=0,x,y,z;i<m;i++) scanf("%d%d%d",&x,&y,&z),add(x,y,z);
	while(flow=dfs(s,0x7fffffffffffffff)) FF();
	printf("%lld",maxflow);
}
