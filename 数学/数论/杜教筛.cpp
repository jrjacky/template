//Luogu 4213
#include<iostream>
#include<cmath>
#include<map>
using namespace std;
const int MAXN=5000000;
int v[MAXN+10],p[MAXN+10];
long long mu[MAXN+10],phi[MAXN+10];
map<int,long long> ansmu,ansphi;
long long sp(int n)
{
    if(n<=MAXN) return phi[n];
    if(ansphi[n]) return ansphi[n];
    long long ans=0;
    for(int l=2,r;r<2147483647&&l<=n;l=r+1) r=n/(n/l),ans+=(r-l+1)*sp(n/l);
    return ansphi[n]=(unsigned long long)n*(n+1ll)/2ll-ans;
}
long long sm(int n)
{
    if(n<=MAXN) return mu[n];
    if(ansmu[n]) return ansmu[n];
    long long ans=0;
    for(int l=2,r;r<2147483647&&l<=n;l=r+1) r=n/(n/l),ans+=(r-l+1)*sm(n/l);
    return ansmu[n]=1ll-ans;
}
int main()
{
    v[1]=mu[1]=phi[1]=1;
    int s=0;
    for(int i=2;i<=MAXN;i++){
        if(!v[i]) p[++s]=i,mu[i]=-1,phi[i]=i-1;
        for(int j=1;j<=s&&i*p[j]<=MAXN;j++){
            v[i*p[j]]=1;
            if(i%p[j]) mu[i*p[j]]=-mu[i],phi[i*p[j]]=phi[i]*phi[p[j]];
            else{mu[i*p[j]]=0,phi[i*p[j]]=phi[i]*p[j];break;}
        }
    }
    for(int i=1;i<=MAXN;++i) mu[i]+=mu[i-1],phi[i]+=phi[i-1];
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cout<<sp(n)<<" "<<sm(n)<<endl;
    }
    return 0;
}
