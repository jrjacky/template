//Luogu 3796 
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct ppap
{
    int s,fail,zm[30];
}ms[100010];
struct node
{
    int next,to;
}lb[150010];
char m[200][100],w[1000010];
int n,h,t,s,ans,sum,pos[200],c[150010],head[150010],q[105010];
void build(int x)
{
    int temp=0,ns=strlen(m[x]);
    for(int i=0;i<ns;i++){
        if(!ms[temp].zm[m[x][i]-'a']) ms[temp].zm[m[x][i]-'a']=++sum;
        temp=ms[temp].zm[m[x][i]-'a'];
    }
    ms[temp].s++;
	pos[x]=temp;
}
void dfs(int x)
{
    for(int i=head[x];i;i=lb[i].next){
        dfs(lb[i].to);
		c[x]+=c[lb[i].to];
    }
}
int main()
{
    while(cin>>n&&n){
		sum=0;
        memset(ms,0,sizeof(ms));
        memset(m,0,sizeof(m));
        memset(pos,0,sizeof(pos));
        memset(c,0,sizeof(c));
        memset(head,0,sizeof(head));
        for (int i=1; i<=n; i++){
            cin>>m[i];
            build(i);
        }
    	h=t=1;
		q[h]=0;
    	while(h<=t){
        	int x=q[h];
        	for(int i=0;i<26;i++){
            	if(x==0){
                	if(ms[x].zm[i]){
                    	ms[ms[x].zm[i]].fail=0;
                    	q[++t]=ms[x].zm[i];
                	}
                	continue;
            	}
            	if(ms[x].zm[i]){
                	ms[ms[x].zm[i]].fail=ms[ms[x].fail].zm[i];
                	q[++t]=ms[x].zm[i];
            	}
            	else ms[x].zm[i]=ms[ms[x].fail].zm[i];
        	}
        	h++;
    	}
		cin>>w;
		s=0;
        for(int i=1;i<=sum;i++){
    		lb[++s].next=head[ms[i].fail];
    		lb[s].to=i;
			head[ms[i].fail]=s;
		} 
        int temp=0,ns=strlen(w);
        for(int i=0;i<ns;i++){
            temp=ms[temp].zm[w[i]-'a'];
            c[temp]++;
        }
        dfs(0);
		ans=0;
        for(int i=1;i<=n;i++) if(ans<c[pos[i]]) ans=c[pos[i]];
        cout<<ans<<endl;
		for(int i=1;i<=n;i++) if(ans==c[pos[i]]) cout<<m[i]<<endl;
    }
    return 0;
}
