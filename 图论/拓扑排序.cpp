//hdu 1285
#include<iostream>
#include<cstring>
using namespace std; 
int n,m,deg[510],g[510][510];
int main()
{
    while(cin>>n>>m){
        memset(g,0,sizeof(g));
        memset(deg,0,sizeof(deg));
        for(int i=1,u,v;i<=m;i++){
            cin>>u>>v;
            if(!g[u][v]) g[u][v]=1,deg[v]++;
        }
    	for(int i=1,temp;i<=n;i++){
    	    for(int j=1;j<=n;j++) if(!deg[j]){cout<<j,deg[j]--,temp=j;break;}
    	    for(int j=1;j<=n;j++) if(g[temp][j]) g[temp][j]=0,deg[j]--;
    		if(i!=n) cout<<" ";
    		else cout<<endl;
		}
    }
}
