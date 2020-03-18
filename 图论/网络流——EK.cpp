//Luogu 2740 
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int inf=1<<29,N=2010,M=20010;
int n,m,s,t,tot,maxflow,head[2010],ver[20010],edge[20010],nxt[20010],v[2010],minc[2010],pre[2010];
int add(int x,int y,int z)
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
	int x=t;
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
	cin>>m>>n;
	s=1,t=n,tot=1,maxflow=0;
	for(int i=0;i<m;i++){
		int x,y,c;
		cin>>x>>y>>c;
		add(x,y,c);
	}
	while(bfs()) EdmondsKarp();
	cout<<maxflow;
	getchar();getchar();
}
