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
long long maxflow,flow[210];
queue<int> q;
void add(int x,int y,int z)
{
	e[++tot].nxt=head[x],head[x]=tot,e[tot].to=y,e[tot].w=z;
	e[++tot].nxt=head[y],head[y]=tot,e[tot].to=x,e[tot].w=0;
}
int bfs()
{
	memset(v,0,sizeof(v));
	while(q.size()) q.pop();
	q.push(s),v[s]=1,flow[s]=0x7fffffffffffffff;
	while(q.size()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt) if(e[i].w&&(!v[e[i].to])){
			flow[e[i].to]=min(flow[x],e[i].w),fr[e[i].to]=i,q.push(e[i].to),v[e[i].to]=1;
			if(e[i].to==t) return 1;
		}
	}
	return 0;
}
void EdmondsKarp()
{
	long long x=t;
	while(x!=s) e[fr[x]].w-=flow[t],e[fr[x]^1].w+=flow[t],x=e[fr[x]^1].to; 
	maxflow+=flow[t];
}
int main()
{
	memset(head,0,sizeof(head));
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=0,x,y,z;i<m;i++) scanf("%d%d%d",&x,&y,&z),add(x,y,z);
	while(bfs()) EdmondsKarp();
	printf("%lld",maxflow);
}
