#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
struct ppap
{
	int u,v,f,c,Next;
}e[100010];
int n,s,t,tot=1,a[101][101],head[100010],p[100010],l[100010],f[100010],v[100010],d[100010];
void add(int a,int b,int f,int c)
{
	e[++tot]=(ppap){a,b,f,c,head[a]},head[a]=tot;
}
bool SPFA()
{
	memset(f,0x7f,sizeof(f));
	memset(d,0x7f,sizeof(d));
	memset(v,0,sizeof(v));
	queue<int> q;
	q.push(s);
	v[s]=1,d[s]=0,p[t]=-1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		v[x]=0;
		for(int i=head[x];i;i=e[i].Next){
			int y=e[i].v;
			if(e[i].f>0&&d[y]>d[x]+e[i].c){
				d[y]=d[x]+e[i].c,p[y]=x,l[y]=i;
				f[y]=min(f[x],e[i].f);
				if(!v[y]){
					v[y]=1;
					q.push(y);
				}
			}
		}
	}
	return p[t]!=-1;
}
int work()
{
	int ans=0;
	while(SPFA()){
		int temp=t;
		ans+=f[t]*d[t];
		while(temp!=s){
			e[l[temp]].f-=f[t];
			e[l[temp]^1].f+=f[t];
			temp=p[temp];
		}
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	cin>>a[i][j],add(i,j+n,1,a[i][j]),add(j+n,i,0,-a[i][j]);
	s=0,t=1000;
	for(int i=1;i<=n;i++) add(s,i,1,0),add(i,s,0,0),add(n+i,t,1,0),add(t,n+i,0,0);
	cout<<work()<<endl;
	memset(e,0,sizeof(e));
	memset(head,0,sizeof(head));
	memset(l,0,sizeof(l));
	memset(p,0,sizeof(p));
	tot=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) add(i,j+n,1,-a[i][j]),add(j+n,i,0,a[i][j]);
	s=0,t=n+n+1;
	for(int i=1;i<=n;i++) add(s,i,1,0),add(i,s,0,0),add(n+i,t,1,0),add(t,n+i,0,0);
	cout<<-work();
}
