//Luogu 4512 
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define MOD 998244353
int n,m,len,ln,f[300010],g[300010],q[300010],R[300010],r[300010],inv[300010],W[300010],A[300010],B[300010];
int POW(int a,int b)
{
    int s=1;
    for(;b;b>>=1){
		if(b&1) s=1ll*s*a%MOD;
		a=1ll*a*a%MOD;
	}
    return s;
}
void NTT(int *a,int op,int ln)
{
    int l=0;
	for(int i=1;i<ln;i<<=1) l++;
    for(int i=0;i<ln;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    for(int i=0;i<ln;i++) if(i<r[i]) swap(a[i],a[r[i]]);
    for(int i=1;i<ln;i<<=1){
        int w=POW(3,(MOD-1)/(i<<1));
		W[0]=1;
        for(int k=1;k<i;++k) W[k]=1ll*W[k-1]*w%MOD;
        for(int p=i<<1,j=0;j<ln;j+=p) for(int k=0;k<i;++k){
            int X=a[j+k],Y=1ll*W[k]*a[i+j+k]%MOD;
            a[j+k]=(X+Y)%MOD;
			a[i+j+k]=(X-Y+MOD)%MOD;
        }
    }
    if(op==-1){
        reverse(&a[1],&a[ln]);
        for(int i=0,inv=POW(ln,MOD-2);i<ln;i++) a[i]=1ll*a[i]*inv%MOD;
    }
}
void INV(int *a,int *b,int len)
{
    if(len==1){inv[0]=POW(a[0],MOD-2);return;}
    INV(a,b,len>>1);
    for(int i=0;i<len;i++) A[i]=a[i],B[i]=b[i];
    NTT(A,1,len<<1);
	NTT(B,1,len<<1);
    for(int i=0;i<len<<1;i++) A[i]=1ll*A[i]*B[i]%MOD*B[i]%MOD;
    NTT(A,-1,len<<1);
    for(int i=0;i<len;i++) b[i]=(b[i]+b[i])%MOD;
    for(int i=0;i<len;i++) b[i]=(b[i]+MOD-A[i])%MOD;
    for(int i=0;i<len<<1;i++) A[i]=B[i]=0;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++) cin>>f[i];
    for(int i=0;i<=m;i++) cin>>g[i];
    reverse(&f[0],&f[n+1]);
	reverse(&g[0],&g[m+1]);
    for(len=1;len<=n-m+1;len<<=1);
	INV(g,inv,len);
    for(ln=1;ln<=n+len;ln<<=1);
    NTT(inv,1,ln);
	NTT(f,1,ln);
    for(int i=0;i<ln;i++) q[i]=1ll*f[i]*inv[i]%MOD;
    NTT(inv,-1,ln);
	NTT(f,-1,ln);
	NTT(q,-1,ln);
    for(int i=n-m+1;i<ln;i++) q[i]=0;
    reverse(&f[0],&f[n+1]);
	reverse(&g[0],&g[m+1]);
	reverse(&q[0],&q[n-m+1]);
    for(int i=0;i<=n-m;i++) printf("%d ",q[i]);
    cout<<endl;
    for(ln=1;ln<=n;ln<<=1);
    NTT(g,1,ln);
	NTT(q,1,ln);
    for(int i=0;i<ln;++i) g[i]=1ll*g[i]*q[i]%MOD;
    NTT(g,-1,ln);
    for(int i=0;i<ln;++i) R[i]=(f[i]+MOD-g[i])%MOD;
    for(int i=0;i<m;++i) printf("%d ",R[i]);
    return 0;
}
