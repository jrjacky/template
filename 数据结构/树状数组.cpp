//POJ 3468
#include<iostream>
using namespace std;
long long n,q,a[100010],sum[100010],c[2][100010];
void add(int k,int x,int y){
	for(;x<=n;x+=x&-x) c[k][x]+=y;
}
long long ask(int k,int x){
	long long ans=0;
	for(;x;x-=x&-x) ans+=c[k][x];
	return ans;
}
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]+=sum[i-1]+a[i];
	for(int i=1,l,r,d;i<=q;i++){
		char op[2];
		cin>>op>>l>>r;
		if(op[0]=='Q') cout<<sum[r]-sum[l-1]+ask(1,l-1)-l*ask(0,l-1)+(r+1)*ask(0,r)-ask(1,r)<<endl;
		else cin>>d,add(0,l,d),add(0,r+1,-d),add(1,l,l*d),add(1,r+1,-(r+1)*d);
	}
}
