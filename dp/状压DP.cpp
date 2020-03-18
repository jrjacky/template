//Luogu 1896 
#include<iostream>
#include<cstring>
using namespace std;
long long g[512],h[512],f[10][512][82],n,k,ans=0;
int main()
{
	cin>>n>>k;
	memset(f,0,sizeof(f));
	for(int i=0;i<(1<<n);i++){
		if(!(i&(i>>1))&&!(i&(i<<1))) g[i]=1;
		int w=i;
		while(w){
			if(w%2) h[i]++;
			w/=2;
		}
		if(g[i]) f[1][i][h[i]]=1;
	}
	for(int i=2;i<=n;i++) for(int j=0;j<(1<<n);j++) if(g[j]) for(int l=0;l<(1<<n);l++)
		if(g[l]&&!(j&l)&&!(j&(l>>1))&&!(j&(l<<1))) for(int w=0;w+h[l]<=k;w++) f[i][l][w+h[l]]+=f[i-1][j][w];
	for(int i=0;i<(1<<n);i++) ans+=f[n][i][k];
	cout<<ans;
}
