//Luogu 3376
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
struct edge
{
	int to,nxt;
	long long w;
}e[10010];
int n,m,s,t,tot=1,head[210],cur[210],d[210];
long long maxflow;
queue<int> q;
void add(int x,int y,int z)
{
	e[++tot].nxt=head[x],head[x]=tot,e[tot].to=y,e[tot].w=z;
	e[++tot].nxt=head[y],head[y]=tot,e[tot].to=x,e[tot].w=0;
}
int bfs()
{
	memcpy(cur,head,sizeof(head));
	memset(d,0,sizeof(d));
	while(q.size()) q.pop();
	q.push(s),d[s]=1;
	while(q.size()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt) if(e[i].w&&(!d[e[i].to])) q.push(e[i].to),d[e[i].to]=d[x]+1;
	}
	return d[t];
}
long long dinic(int x,long long flow)
{
	if(x==t) return flow;
	long long rest=flow,k;
	for(int &i=cur[x];i&&rest;i=e[i].nxt) if(e[i].w&&d[e[i].to]==d[x]+1){
		k=dinic(e[i].to,min(rest,e[i].w));
		if(!k) continue;
		e[i].w-=k,e[i^1].w+=k,rest-=k;
		if(!rest) break;
	}
	return flow-rest;
}
int main()
{
	cin>>n>>m>>s>>t;
	long long z;
	for(int i=1,x,y;i<=m;i++) cin>>x>>y>>z,add(x,y,z);
	while(bfs()) maxflow+=dinic(s,0x7fffffffffffffff);
	cout<<maxflow;
}
