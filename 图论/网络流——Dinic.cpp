#include<iostream>
#include<cstring>
#include<cstdio>
//Luogu 2756
#include<queue>
using namespace std;
const int inf=1<<29;
int n,m=0,s,t,tot=0,maxflow=0,head[100010],ver[100010],edge[100010],Next[100010],d[100010];
queue<int> q;
void add(int x,int y,int z)
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
int dinic(int x,int flow)
{
	if(x==t) return flow;
	int rest=flow,k;
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
	int n1,x,y;
	cin>>n>>n1;
	s=0,t=n1+1,tot=1;
	for(int i=1;i<=n;i++) add(s,i,1);
	for(int i=n+1;i<=n1;i++) add(i,t,1);
	while(scanf("%d%d",&x,&y)!=EOF&&x!=-1&&y!=-1){
		add(x,y,1);
		m++;
	}
	while(bfs()) maxflow+=dinic(s,inf);
	if(!maxflow){cout<<"No Solution!";return 0;}
	cout<<maxflow<<endl;
	for(int i=2;i<=tot;i+=2) if(ver[i]!=s&&ver[i^1]!=s&&ver[i]!=t&&ver[i^1]!=t&&edge[i^1]!=0)
	cout<<ver[i^1]<<" "<<ver[i]<<endl;
}
