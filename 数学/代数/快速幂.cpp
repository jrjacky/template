#include<iostream>
using namespace std;
int main()
{
	int a,b,p,ans;
	cin>>a>>b>>p;
	ans=1%p;
	for(;b;b>>=1){
		if(b&1) ans=(long long)ans*a%p;
		a=(long long)a*a%p;
	}
	cout<<ans;
	return 0;
}
