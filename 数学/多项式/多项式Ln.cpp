//Luogu 4725 
#include<iostream>
using namespace std;
int n,l,ln,r[400010];
long long MOD=998244353,x[400010],X[400010],y[400010],Y[400010],ans[400010];
int POW(int a,int b)
{
    int s=1;
    for(;b;b>>=1){
		if(b&1) s=1ll*s*a%MOD;
		a=1ll*a*a%MOD;
	}
    return s;
}
void NTT(long long *a,int op,int ln)
{
    for(int i=0;i<ln;i++) if(i<r[i]) swap(a[i],a[r[i]]);
    for(int i=1;i<ln;i<<=1){
        long long w=POW(3,(MOD-1)/(i<<1));
        if(op==-1) w=POW(w,MOD-2);
        for(int j=0;j<ln;j+=(i<<1)){
            long long W=1;
            for(int k=0;k<i;k++,W=w*W%MOD){
                long long x=a[j+k],y=a[j+k+i]*W%MOD;
                a[j+k]=(x+y)%MOD,a[i+j+k]=(x-y+MOD)%MOD;
            }
        }
    }
    if(op==-1){
        int ny=POW(ln,MOD-2);
        for(int i=0;i<ln;i++) a[i]=a[i]*ny%MOD;
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=1;i<n;i++) ans[i-1]=x[i]*i%MOD;
    ln=1,y[0]=POW(x[0],MOD-2),cout<<"0 ";
    for(;ln<n*2;){
        l++,ln<<=1;
    	for(int i=0;i<ln;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
        for(int i=0;i<ln>>1;i++) X[i]=x[i],Y[i]=y[i]; 
        NTT(X,1,ln),NTT(Y,1,ln);
        for(int i=0;i<ln;i++) Y[i]=(Y[i]*2ll%MOD-X[i]*Y[i]%MOD*Y[i]%MOD+MOD)%MOD;
        NTT(Y,-1,ln);
        for(int i=0;i<ln>>1;i++) y[i]=Y[i];
    }
    NTT(ans,1,ln),NTT(y,1,ln);
    for(int i=0;i<ln;i++) ans[i]=ans[i]*y[i]%MOD;
    NTT(ans,-1,ln);
    for(int i=ln-1;i>=1;i--) ans[i]=ans[i-1]*POW(i,MOD-2)%MOD;
    for(int i=1;i<n;i++) cout<<ans[i]<<" ";
}
