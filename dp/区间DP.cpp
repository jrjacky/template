//Luogu 1880
#include<iostream>
using namespace std;
int n,a[210]={0},f1[210][210],f2[210][210],sum[210];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[n+i]=a[i];
	}
	for(int i=1;i<=2*n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n;i++) for(int j=1;j<=2*n-i+1;j++){
		int minf=2147483647,maxf=0;
		for(int k=j;k<j+i-1;k++){
			minf=min(minf,f1[j][k]+f1[k+1][j+i-1]+sum[j+i-1]-sum[j-1]);
			maxf=max(maxf,f2[j][k]+f2[k+1][j+i-1]+sum[j+i-1]-sum[j-1]);
		}
		f1[j][j+i-1]=minf;
		f2[j][j+i-1]=maxf;
	}
	int maxf=0,minf=2147483647;
	for(int i=1;i<=n;i++) maxf=max(maxf,f2[i][i+n-1]),minf=min(minf,f1[i][i+n-1]);
	cout<<minf<<endl<<maxf;
}
