//Luogu 3807 
#include<iostream>
using namespace std;
int n,m,p,T;
long long jc[1000010],ny[1000010];
long long C(long long n,long long m)
{
	if(n==0&&m==0) return 1;
    if(n<m) return 0;
    return jc[n]*ny[m]%p*ny[n-m]%p;
}
long long CC(long long n,long long m)
{
    if(n<p&&m<p) return C(n,m);
    return CC(n%p,m%p)*CC(n/p,m/p)%p;
}
int main()
{
    cin>>T;
    while(T--){
        cin>>n>>m>>p;
    	jc[0]=ny[0]=ny[1]=1;
    	for(int i=2;i<=p;i++) ny[i]=(p-p/i)*ny[p%i]%p;
    	for(int i=1;i<=p;i++) jc[i]=jc[i-1]*i%p,ny[i]=ny[i]*ny[i-1]%p;
        cout<<CC(n+m,n)<<endl;
    }
}
