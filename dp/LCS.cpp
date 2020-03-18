//DTOJ Begin2589
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
char x[10010],y[10010],t;
int f[10010][3010];
int main()
{
	cin>>x>>y;
	int m=strlen(x),n=strlen(y);
	for(int i=m;i>=1;i--) x[i]=x[i-1];
	for(int i=n;i>=1;i--) y[i]=y[i-1];
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++)
		if(x[i]==y[j]) f[i][j]=f[i-1][j-1]+1;
		else f[i][j]=max(f[i][j-1],f[i-1][j]);
	cout<<f[m][n];
}
