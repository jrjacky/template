#include<iostream>
using namespace std;
long long n,l,r,x[1000010],c[1000010],p[1000010],sp[1000010],s[1000010];
long long f[1000010],q[1000010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>p[i]>>c[i];
		s[i]=s[i-1]+x[i]*p[i],sp[i]=sp[i-1]+p[i];
	}
	for(int i=1;i<=n;i++){
		while(l<r&&f[q[l+1]]+s[q[l+1]]-f[q[l]]-s[q[l]]<x[i]*(sp[q[l+1]]-sp[q[l]])) l++;
		f[i]=f[q[l]]+c[i]+x[i]*(sp[i]-sp[q[l]])-s[i]+s[q[l]];
		while(l<r&&(f[q[r]]+s[q[r]]-f[q[r-1]]-s[q[r-1]])*(sp[i]-sp[q[r]])>(f[i]+s[i]-f[q[r]]-s[q[r]])*(sp[q[r]]-sp[q[r-1]])) r--;
		q[++r]=i;
	}
	cout<<f[n];
}
