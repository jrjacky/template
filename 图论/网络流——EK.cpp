#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int inf=1<<29;
int n,m,s,t,tot,head[210],ver[10010],nxt[10010],v[210],pre[210];
long long maxflow,edge[10010],minc[210];
void add(int x,int y,int z)
{
	ver[++tot]=y,edge[tot]=z,nxt[tot]=head[x],head[x]=tot;
	ver[++tot]=x,edge[tot]=0,nxt[tot]=head[y],head[y]=tot;
}
int bfs()
{
	memset(v,0,sizeof(v));
	queue<int> q;
	q.push(s);
	v[s]=1;
	minc[s]=inf;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i]) if(edge[i]){
			int y=ver[i];
			if(v[y]) continue;
			minc[y]=min(minc[x],edge[i]);
			pre[y]=i;
			q.push(y);
			v[y]=1;
			if(y==t) return 1;
		}
	}
	return 0;
}
void EdmondsKarp()
{
	long long x=t;
	while(x!=s){
		int i=pre[x];
		edge[i]-=minc[t];
		edge[i^1]+=minc[t];
		x=ver[i^1]; 
	}
	maxflow+=minc[t];
}
int main()
{
	memset(head,0,sizeof(head));
	scanf("%d%d%d%d",&n,&m,&s,&t);
	tot=1,maxflow=0;
	for(int i=0;i<m;i++){
		int x,y;
		long long c;
		scanf("%d%d%lld",&x,&y,&c);
		add(x,y,c);
	}
	while(bfs()) EdmondsKarp();
	printf("%lld",maxflow);
}
