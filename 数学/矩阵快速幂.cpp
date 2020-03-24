//Luogu 3390 
#include<iostream>
using namespace std;
struct ppap
{
	long long a[110][110];
}a,ans;
long long n,k,MOD=1e9+7;
void X(ppap &a,ppap b)
{
	ppap c;
    for(long long i=0;i<n;i++) for(long long k=0;k<n;k++){
        long long sum=0;
        for(long long j=0;j<n;j++) sum=(sum+a.a[i][j]*b.a[j][k]%MOD)%MOD;
    	c.a[i][k]=sum;
    }
    for(long long i=0;i<n;i++) for(long long j=0;j<n;j++) a.a[i][j]=c.a[i][j];
}
int main()
{
	cin>>n>>k;
	for(long long i=0;i<n;i++) for(long long j=0;j<n;j++) cin>>a.a[i][j],ans.a[i][i]=1;
	for(;k;k>>=1){
		if(k&1) X(ans,a);
		X(a,a);
	}
	for(long long i=0;i<n;i++){for(long long j=0;j<n;j++) cout<<ans.a[i][j]<<" ";cout<<endl;}
}
