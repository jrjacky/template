//Luogu 3367 
#include<iostream>
using namespace std;
int n,m,z,x,y,fa[10001];
int find(int n)
{
	return fa[n]==n?n:fa[n]=find(fa[n]); 
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>z>>x>>y;
		if(z==1) fa[find(x)]=find(y);
		else if(z==2) cout<<(find(x)==find(y)?"Y":"N")<<endl;
	}
}
