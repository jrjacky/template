//Luogu 3366
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m,tot,sum,ans,head[5010],dis[5010],v[5010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
struct ppap
{
    int to,ver,nxt;
}e[400010];
void add(int u,int v,int w)
{
    e[++tot].to=v,e[tot].ver=w,e[tot].nxt=head[u],head[u]=tot;
}
int main()
{
    memset(dis,0x7f,sizeof(dis));
    cin>>n>>m;
    for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,add(u,v,w),add(v,u,w);
    dis[1]=0,q.push(make_pair(0,1));
    while(!q.empty()&&sum<n){
        int d=q.top().first,u=q.top().second;
        q.pop();
        if(v[u]) continue;
        sum++,ans+=d,v[u]=1;
        for(int i=head[u];i;i=e[i].nxt) if(e[i].ver<dis[e[i].to]) dis[e[i].to]=e[i].ver,q.push(make_pair(dis[e[i].to],e[i].to));
    }
    if(sum==n) cout<<ans;
    else cout<<"orz";
}
