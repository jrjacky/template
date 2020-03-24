//Luogu 4782
#include<iostream>
using namespace std;
struct ppap
{
    int to,nxt;
}edge[4000010];
int n,m,tot,num,top,cnt,head[2000010],low[2000010],dfn[2000010],stack[2000010],y[2000010],in[2000010];
void add(int u,int v)
{
    edge[++tot].to=v,edge[tot].nxt=head[u],head[u]=tot;
}
void tarjan(int u)
{
    low[u]=dfn[u]=++num;
    stack[top++]=u;
	in[u]=1;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
		else if(in[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        cnt++;
        int v;
        do{
            v=stack[--top],in[v]=0,y[v]=cnt;
        }while(u!=v);
    }
}
bool two_SAT()
{
    for(int i=1;i<=2*n;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++) if(y[i]==y[i+n]) return 0;
    return 1;
}
int main()
{
    cin>>n>>m;
    for(int i=1,a,b,A,B;i<=m;i++) cin>>a>>A>>b>>B,add(a+(A^1)*n,b+B*n),add(b+(B^1)*n,a+A*n); 
    if(two_SAT()){
        cout<<"POSSIBLE"<<endl;
        for(int i=1;i<=n;i++) cout<<(y[i]>y[i+n])<<" ";
    }
	else cout<<"IMPOSSIBLE";
}
