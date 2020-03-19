//Luogu 4238
#include<algorithm>
#include<iostream>
using namespace std;
const int N=2000010;
int n,MOD=998244353,a[2000010],b[2000010],c[2000010],r[2000010];
int POW(int a,int b)
{
    int ans=1;
    for(;b;b>>=1){
		if(b&1) ans=1ll*ans*a%MOD;
		a=1ll*a*a%MOD;
	}
    return ans;
}
void NTT(int *a,int op,int ln)
{
    for(int i=0;i<ln;++i) if(i<r[i]) swap(a[i],a[r[i]]);
    for(int i=1;i<ln;i<<=1){
        int w=POW(3,(MOD-1)/(i<<1));
        for(int j=0,t1,t2,W;j<ln;j+=(i<<1)){
            W=1;
            for(int k=0;k<i;k++){
                t1=a[j+k],t2=1LL*W*a[i+j+k]%MOD;
                a[j+k]=(t1+t2)%MOD,a[i+j+k]=(t1-t2+MOD)%MOD,W=1LL*W*w%MOD;
            }
        }
    }
    if(op==-1){
    	int ny=POW(ln,MOD-2);
		reverse(a+1,a+ln);
    	for(int i=0;i<ln;i++) a[i]=1ll*a[i]*ny%MOD;
	}
}
void js(int deg,int *a,int *b)
{
    if(deg==1){b[0]=POW(a[0],MOD-2);return;}
    js((deg+1)>>1,a,b);
    int l,ln;
    for(l=0,ln=1;ln<(deg<<1);ln<<=1,l++);
    for(int i=1;i<ln;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    for(int i=0;i<deg;i++) c[i]=a[i];
    for(int i=deg;i<ln;i++) c[i]=0;
    NTT(c,1,ln),NTT(b,1,ln);
    for(int i=0;i<ln;i++) b[i]=1LL*(2-1ll*c[i]*b[i]%MOD+MOD)%MOD*b[i]%MOD;
    NTT(b,-1,ln);
    for(int i=deg;i<ln;i++) b[i]=0;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    js(n,a,b);
    for(int i=0;i<n;i++) cout<<b[i]<<" ";
}
