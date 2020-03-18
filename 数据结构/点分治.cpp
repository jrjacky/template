//Luogu 4178 
#include<algorithm>
#include<iostream>
using namespace std;
struct ppap{
    int to,nxt,v;
}edge[80010];
int n,tot,root,maxt,sz,head[40010],size[40010],v[40010];
long long k,ans,l,r,d[40010],q[40010];
void add(int x,int y,int l){
    edge[++tot].to=y;edge[tot].nxt=head[x];edge[tot].v=l;head[x]=tot;
}
void getroot(int x,int fa){
	int temp=0;
    size[x]=1;
    for(int i=head[x];i;i=edge[i].nxt){
        int u=edge[i].to;
        if(u==fa||v[u]) continue;
        getroot(u,x);
        size[x]+=size[u];
        temp=max(temp,size[u]);
    }
    temp=max(temp,sz-size[x]);
    if(temp<maxt){
        maxt=temp;root=x;
    }
}
void getdis(int x,int fa){
    q[++r]=d[x];
    for(int i=head[x];i;i=edge[i].nxt){
        int u=edge[i].to;
        if(u==fa||v[u]) continue;
        d[u]=d[x]+edge[i].v;
        getdis(u,x);
    }
}
long long js(int x,int v){
    long long s=0;
    r=0;
    d[x]=v;
    getdis(x,0);
    l=1;
    sort(q+1,q+r+1);
    while(l<r){
        if(q[l]+q[r]<=k) s+=r-l,l++;
        else r--;
    }
    return s;
}
void dfs(int x){
    ans+=js(x,0);
    v[x]=1;
    for(int i=head[x];i;i=edge[i].nxt){
        int u=edge[i].to;
        if(v[u]) continue;
        ans-=js(u,edge[i].v);
        sz=size[u];
        maxt=2147483647;
        getroot(u,0);
        dfs(root);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y,l;
        cin>>x>>y>>l;
        add(x,y,l);
		add(y,x,l);
    }
    cin>>k;
    sz=n;
    maxt=2147483647;
    getroot(1,0);
    dfs(root);
    cout<<ans;
    return 0;
}
