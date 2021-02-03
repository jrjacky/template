//Luogu 4722
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
struct edge
{
	int to,nxt;
	long long w;
}e[2000010];
int d[10010];
struct point
{
	bool operator () (const int &x,const int &y) const
	{
		return d[x]<d[y];
	}
};
int n,m,s,t,tot=1,head[10010],gap[10010],v[10010];
long long restflow[10010];
priority_queue<int,vector<int>,point> q;
queue<int> Q;
void add(int x,int y,int z)
{
	e[++tot].nxt=head[x],head[x]=tot,e[tot].to=y,e[tot].w=z;
	e[++tot].nxt=head[y],head[y]=tot,e[tot].to=x,e[tot].w=0;
}
int bfs()
{
	Q.push(t),memset(d,0x7f,sizeof(d)),d[t]=0;
	while(!Q.empty()){
		int x=Q.front();Q.pop();
		for(int i=head[x];i;i=e[i].nxt) if(e[i^1].w&&d[e[i].to]>d[x]+1) Q.push(e[i].to),d[e[i].to]=d[x]+1;
	}
	return d[s]==0x7f7f7f7f;
}
void push(int x)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].w&&d[e[i].to]+1==d[x]){
		int temp=min(restflow[x],e[i].w);
		e[i^1].w+=temp,restflow[x]-=temp,restflow[e[i].to]+=temp,e[i].w-=temp;
		if(e[i].to!=s&&e[i].to!=t&&(!v[e[i].to])) q.push(e[i].to),v[e[i].to]=1;
		if(!restflow[x]) break;
	}
}
void HLPP()
{
	if(bfs()){printf("0");return;}
	d[s]=n,memset(gap,0,sizeof(gap));
	for(int i=1;i<=n;i++) if(d[i]!=0x7f7f7f7f) gap[d[i]]++;
	for(int i=head[s];i;i=e[i].nxt) if(e[i].w){
		e[i^1].w+=e[i].w,restflow[s]-=e[i].w,restflow[e[i].to]+=e[i].w,e[i].w=0;
		if(e[i].to!=s&&e[i].to!=t&&(!v[e[i].to])) q.push(e[i].to),v[e[i].to]=1;
	}
	while(!q.empty()){
		int x=q.top();q.pop(),v[x]=0,push(x);
		if(!restflow[x]) continue;
		gap[d[x]]--;
		if(!gap[d[x]]) for(int i=1;i<=n;i++) if(i!=s&&i!=t&&d[x]<d[i]&&d[i]<=n) d[i]=n+1;
		d[x]=0x7f7f7f7f;
		for(int i=head[x];i;i=e[i].nxt) if(e[i].w&&d[e[i].to]+1<d[x]) d[x]=d[e[i].to]+1;
		gap[d[x]]++,q.push(x),v[x]=1;
	}
	printf("%lld",restflow[t]);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1,x,y,z;i<=m;i++) scanf("%d%d%d",&x,&y,&z),add(x,y,z);
	HLPP();
}
