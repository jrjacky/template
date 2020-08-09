//Luogu 3376
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
struct edge
{
	int fr,to,nxt;
	long long w;
}e[10010];
int n,m,s,t,tot=1,na,head[210],cur[210],aug[210],d[210],gap[210];
long long ans;
queue<int> q;
void add(int x,int y,int z)
{
	e[++tot].nxt=head[x],head[x]=tot,e[tot].fr=x,e[tot].to=y,e[tot].w=z;
	e[++tot].nxt=head[y],head[y]=tot,e[tot].fr=y,e[tot].to=x,e[tot].w=0;
}
void bfs()
{
	q.push(t),d[t]=1,gap[1]=1;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].nxt) if(e[i^1].w&&(!d[e[i].to])) q.push(e[i].to),d[e[i].to]=d[x]+1,gap[d[e[i].to]]++;
	}
}
void ISAP()
{
	bfs();
	memcpy(cur,head,sizeof(head));
	int x=s;
	while(d[s]<=n){
		if(x==t){
			int minf=0x7fffffff,hminf=n;
			for(int i=0;i<na;i++) if(minf>e[aug[i]].w) minf=e[aug[i]].w,hminf=i;
			for(int i=0;i<na;i++) e[aug[i]].w-=minf,e[aug[i]^1].w+=minf;
			ans+=minf,na=hminf,x=e[aug[na]].fr;
		}
		int i;
		for(i=cur[x];i;i=e[i].nxt) if(e[i].w&&d[x]==d[e[i].to]+1) break;
		if(i) cur[x]=i,aug[na++]=i,x=e[i].to;
		else{
			if(!(--gap[d[x]])) break;
			int mind=n;
			for(int j=head[x];j;j=e[j].nxt) if(e[j].w&&mind>d[e[j].to]) mind=d[e[j].to],cur[x]=j;
			d[x]=mind+1,gap[d[x]]++;
			if(x!=s) x=e[aug[--na]].fr;
		}
	}
	cout<<ans;
}
int main()
{
	cin>>n>>m>>s>>t;
	long long z;
	for(int i=1,x,y;i<=m;i++) cin>>x>>y>>z,add(x,y,z);
	ISAP();
}
