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
struct point
{
	int x,h;
	bool operator < (const point &a) const
	{
		return h<a.h;
	}
};
const long long inf=0x7fffffffffffffff;
int n,m,s,t,tot=1,na,head[210],cur[210],aug[210],d[210],gap[210];
long long ans,restflow[210];
priority_queue<point> q;
queue<int> Q;
void add(int x,int y,int z)
{
	e[++tot].nxt=head[x],head[x]=tot,e[tot].to=y,e[tot].w=z;
	e[++tot].nxt=head[y],head[y]=tot,e[tot].to=x,e[tot].w=0;
}
void bfs()
{
	Q.push(t),d[t]=1,gap[1]=1;
	while(Q.size()){
		int x=Q.front();
		Q.pop();
		for(int i=head[x];i;i=e[i].nxt) if(e[i^1].w&&(!d[e[i].to])) Q.push(e[i].to),d[e[i].to]=d[x]+1,gap[d[e[i].to]]++;
	}
}
int push(int x,int i)
{
	int flow=min(restflow[x],e[i].w);
	e[i].w-=flow,e[i^1].w+=flow,restflow[x]-=flow,restflow[e[i].to]+=flow;
	return flow;
}
void Gap(int h)
{
	for(int i=1;i<=n;i++) if(i!=s&&i!=t&&h<d[i]&&d[i]<=n) d[i]=n+1;
}
void HLPP()
{
	bfs();
	d[s]=n,restflow[s]=inf,q.push((point){s,n});
	while(!q.empty()){
		int x=q.top().x;q.pop();
		if(!restflow[x]) continue;
		for(int i=head[x];i;i=e[i].nxt) if((x==s||d[x]==d[e[i].to]+1)&&push(x,i)&&e[i].to!=t&&e[i].to!=s) q.push((point){e[i].to,d[e[i].to]});
		if(x!=s&&x!=t&&restflow[x]){
			if(!(--gap[d[x]])) Gap(d[x]);
			d[x]++,gap[d[x]]++,q.push((point){x,d[x]});
		}
	}
	cout<<restflow[t];
}
int main()
{
	cin>>n>>m>>s>>t;
	long long z;
	for(int i=1,x,y;i<=m;i++) cin>>x>>y>>z,add(x,y,z);
	HLPP();
}
