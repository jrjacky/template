//Luogu 2522 
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int a,b,c,d,k,miu[50010],v[50010],sum[50010];
long long fk(int x,int y)
{
	if(x>y) swap(x,y);
	long long ans=0;
	for(int i=1,j;i<=x;i=j+1){
		j=min(x/(x/i),y/(y/i));
		ans+=(long long)(sum[j]-sum[i-1])*(x/i)*(y/i);
	}
	return ans;
}
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=50000;i++) miu[i]=1,v[i]=0;
	for(int i=2;i<=50000;i++){
		if(v[i]) continue;
		miu[i]=-1;
		for(int j=2*i;j<=50000;j+=i){
			v[j]=1;
			if((j/i)%i==0) miu[j]=0;
			else miu[j]*=-1;
		}
	}
	sum[0]=0;
	for(int i=1;i<=50000;i++) sum[i]=sum[i-1]+miu[i];
	while(T--){
		cin>>a>>b>>c>>d>>k;
		cout<<fk(b/k,d/k)-fk(b/k,(c-1)/k)-fk((a-1)/k,d/k)+fk((a-1)/k,(c-1)/k)<<endl;
	}
}
