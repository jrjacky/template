//Luogu 4717 
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const long long mod=998244353;
int n,ln;
long long a[262150],b[262150],aa[262150],bb[262150];
void FWT_OR(long long *a)
{
    for(int i=1,ii=2;i<ln;i<<=1,ii<<=1) for(int j=0;j<ln;j+=ii) for(int k=0;k<i;k++) (a[j+k+i]+=a[j+k])%=mod;
}
void IFWT_OR(long long *a)
{
    for(int i=ln>>1,ii=ln;i>0;i>>=1,ii>>=1) for(int j=0;j<ln;j+=ii) for(int k=0;k<i;k++) (a[j+k+i]-=a[j+k]-mod)%=mod;
}
void FWT_AND(long long *a)
{
    for(int i=1,ii=2;i<ln;i<<=1,ii<<=1) for(int j=0;j<ln;j+=ii) for(int k=0;k<i;k++) (a[j+k]+=a[j+k+i])%=mod;
}
void IFWT_AND(long long *a)
{
    for(int i=ln>>1,ii=ln;i>0;i>>=1,ii>>=1) for(int j=0;j<ln;j+=ii) for(int k=0;k<i;k++) (a[j+k]-=a[j+k+i]-mod)%=mod;
}
void FWT_XOR(long long *a)
{
    long long x;
    for(int i=1,ii=2;i<ln;i<<=1,ii<<=1) for(int j=0;j<ln;j+=ii) for(int k=0;k<i;k++){
    	x=a[j+k];
        (a[j+k]+=a[j+k+i])%=mod,(a[j+k+i]-=x-mod)%=mod;
    }
}
void IFWT_XOR(long long *a)
{
    long long x;
    for(int i=ln>>1,ii=ln;i>0;i>>=1,ii>>=1) for(int j=0;j<ln;j+=ii) for(int k=0;k<i;k++){
        x=a[j+k];
        a[j+k]=(a[j+k]+a[j+k+i])*((mod+1)/2)%mod,a[j+k+i]=(x-a[j+k+i]+mod)*((mod+1)/2)%mod;
    }
}

int main()
{
    cin>>n;
    ln=1<<n;
    for(int i=0;i<ln;i++) cin>>aa[i];
    for(int i=0;i<ln;i++) cin>>bb[i];
    memcpy(a,aa,sizeof(aa)),memcpy(b,bb,sizeof(bb));
    FWT_OR(a),FWT_OR(b);
    for(int i=0;i<ln;i++) a[i]=a[i]*b[i]%mod;
    IFWT_OR(a);
    for(int i=0;i<ln;i++) cout<<a[i]<<" ";
    cout<<endl;
    memcpy(a,aa,sizeof(aa)),memcpy(b,bb,sizeof(bb));
    FWT_AND(a),FWT_AND(b);
    for(int i=0;i<ln;i++) a[i]=a[i]*b[i]%mod;
    IFWT_AND(a);
    for(int i=0;i<ln;i++) cout<<a[i]<<" ";
    cout<<endl;
    memcpy(a,aa,sizeof(aa)),memcpy(b,bb,sizeof(bb));
    FWT_XOR(a),FWT_XOR(b);
    for(int i=0;i<ln;i++) a[i]=a[i]*b[i]%mod;
    IFWT_XOR(a);
    for(int i=0;i<ln;i++) cout<<a[i]<<" ";
}
