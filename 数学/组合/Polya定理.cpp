#include<iostream>
using namespace std;
long long n,MOD=1e9+7;
long long POW(long long a,long long b)
{
	long long ans=1;
	for(;b;b>>=1){
		if(b&1) ans=1ll*ans*a%MOD;
		a=1ll*a*a%MOD;
	}
	return ans;
}
long long PHI(long long n)
{
	long long ans=1;
	for(long long i=2;i*i<=n;i++) if(!(n%i)){
		n/=i,ans*=(i-1);
		while(!(n%i)) n/=i,ans*=i;
	}
	if(n>1) ans*=(n-1);
	return ans;
}
long long polya(long long n)
{
	long long ans=0;
	for(long long i=1;i*i<=n;i++){
		if(n%i) continue;
		ans=(ans%MOD)+PHI(i)*POW(n,n/i-1)%MOD;
		if(i*i!=n) ans=(ans%MOD)+PHI(n/i)*POW(n,i-1)%MOD;
    }
	return ans%MOD;
}
int main()
{
	int T;
    cin>>T;
    while(T--) cin>>n,cout<<polya(n)<<endl;
}
