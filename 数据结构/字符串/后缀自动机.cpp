//Luogu 3804
#include<iostream>
#include<cstring>
using namespace std;
struct ppap
{
	int fa,len,s[26];
	ppap()
	{
		memset(s,0,sizeof(s)),fa=len=0;
	}
}dot[2000010];
int tot=1,last=1,Tot=0,head[2000010],nxt[2000010],to[2000010];
long long ans,t[2000010];
char s[2000010];
void Add(int a,int b)
{
	nxt[++Tot]=head[a],to[Tot]=b,head[a]=Tot;
}
void add(int c)
{
	int p=last,P=last=++tot;
	t[tot]=1,dot[P].len=dot[p].len+1;
	for(;p&&!dot[p].s[c];p=dot[p].fa) dot[p].s[c]=P;
	if(!p) dot[P].fa=1;
	else{
		int q=dot[p].s[c];
		if(dot[q].len==dot[p].len+1) dot[P].fa=q;
		else{
			int Q=++tot;
			dot[Q]=dot[q],dot[Q].len=dot[p].len+1;
			dot[q].fa=dot[P].fa=Q;
			for(;p&&dot[p].s[c]==q;p=dot[p].fa) dot[p].s[c]=Q;
		}
	}
}
void dfs(int u)
{
	for(int i=head[u];i;i=nxt[i]) dfs(to[i]),t[u]+=t[to[i]];
	if(t[u]!=1) ans=max(ans,t[u]*dot[u].len); 
}
int main()
{
	cin>>s;
	int n=strlen(s);
	for(int i=0;i<n;i++) add(s[i]-'a');
	for(int i=2;i<=tot;i++) Add(dot[i].fa,i);
	dfs(1);
	cout<<ans;
}
