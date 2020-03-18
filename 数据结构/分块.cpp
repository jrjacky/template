//POJ 3468
#include<iostream>
#include<cmath>
using namespace std;
long long a[100010],sum[100010],add[100010];
int n,m,D,L[100010],R[100010],pos[100010];
long long ask(int l,int r){
	int p=pos[l],q=pos[r];
	long long ans=0;
	if(p==q){
		for(int i=l;i<=r;i++) ans+=a[i];
		ans+=add[p]*(r-l+1);
	}
	else{
		for(int i=p+1;i<=q-1;i++) ans+=sum[i]+add[i]*(R[i]-L[i]+1);
		for(int i=l;i<=R[p];i++) ans+=a[i];
		ans+=add[p]*(R[p]-l+1);
		for(int i=L[q];i<=r;i++) ans+=a[i];
		ans+=add[q]*(r-L[q]+1);
	}
	return ans;
}
void change(int l,int r,int d){
	int p=pos[l],q=pos[r];
	if(p==q){
		for(int i=l;i<=r;i++) a[i]+=d;
		sum[p]+=d*(r-l+1);
	}
	else{
		for(int i=p+1;i<=q-1;i++) add[i]+=d;
		for(int i=l;i<=R[p];i++) a[i]+=d;
		sum[p]+=d*(R[p]-l+1);
		for(int i=L[q];i<=r;i++) a[i]+=d;
		sum[q]+=d*(r-L[q]+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	D=sqrt(1.0*n);
	for(int i=1;i<=D;i++) L[i]=(i-1)*sqrt(1.0*n)+1,R[i]=i*sqrt(1.0*n);
	if(R[D]<n) D++,L[D]=R[D-1]+1,R[D]=n;
	for(int i=1;i<=D;i++) for(int j=L[i];j<=R[i];j++) pos[j]=i,sum[i]+=a[j];
	while(m--){
		int l,r,d;
		char op[2];
		scanf("%s%d%d",op,&l,&r);
		if(op[0]=='Q') printf("%lld\n",ask(l,r));
		else scanf("%d",&d),change(l,r,d);
	}
}
