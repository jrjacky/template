//Luogu 3376
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int inf=1<<29;
int n,m,s,t,tot=1,head[100010],ver[100010],Next[100010],d[100010];
long long edge[100010],maxflow;
queue<int> q;
void add(int x,int y,long long z)
{
	ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
	ver[++tot]=x,edge[tot]=0,Next[tot]=head[y],head[y]=tot;
}
bool bfs()
{
	memset(d,0,sizeof(d));
	while(q.size()) q.pop();
	q.push(s);
	d[s]=1;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=Next[i]) if(edge[i]&&!d[ver[i]]){
			q.push(ver[i]);
			d[ver[i]]=d[x]+1;
		}
	}
	return d[t];
}
int dinic(int x,long long flow)
{
	if(x==t) return flow;
	long long rest=flow,k;
	for(int i=head[x];i&&rest;i=Next[i]) if(edge[i]&&d[ver[i]]==d[x]+1){
		k=dinic(ver[i],min(rest,edge[i]));
		if(!k) d[ver[i]]=0;
		edge[i]-=k;
		edge[i^1]+=k;
		rest-=k;
	}
	return flow-rest;
}
int main()
{
	cin>>n>>m>>s>>t;
	long long z;
	for(int i=1,x,y;i<=m;i++) cin>>x>>y>>z,add(x,y,z);
	while(bfs()) maxflow+=dinic(s,inf);
	cout<<maxflow<<endl;
}
