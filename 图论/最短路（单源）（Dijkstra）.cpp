//Luogu 4779
#include<algorithm> 
#include<algorithm> 
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int head[100010],edge[200010],nxt[200010],ver[200010],v[100010],d[100010];
int n,m,c,tot=0;
priority_queue<pair<int,int> > q;
void add(int x,int y,int w)
{
	ver[++tot]=y,edge[tot]=w,nxt[tot]=head[x],head[x]=tot;
}
void dijkstra()
{
	for(int i=0;i<=n;i++) d[i]=2147483647;
	memset(v,0,sizeof(v));
	d[c]=0;q.push(make_pair(0,c));
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(v[x]) continue;
		v[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=m;i++){
		int s,e,t; 
		scanf("%d%d%d",&s,&e,&t);
		add(s,e,t);
	}
	dijkstra();
	for(int i=1;i<=n;i++) cout<<d[i]<<" ";
}
