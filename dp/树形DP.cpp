//POJ2342
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int s[6010],fa[6010],d[6010],g[6010],f[6010];
int n,sum=0;
void dfs(int x)
{
	f[x]=s[x]; 
	for(int i=1;i<=n;i++) if(fa[i]==x){
		dfs(i);
		f[fa[i]]+=g[i];
		g[fa[i]]+=max(g[i],f[i]);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF&&x!=0&&y!=0) fa[x]=y;
	int gen;
	for(int i=1;i<=n;i++){
		if(fa[i]==0){gen=i;break;}
	}
	dfs(gen);
	cout<<max(g[gen],f[gen])<<endl;
}
