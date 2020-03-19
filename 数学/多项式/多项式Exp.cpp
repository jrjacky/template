//Luogu 4726 
#include<iostream>
#include<cstdio>
using namespace std;
int r[400010],n;
long long MOD=998244353,x[400010],Inv[400010],inv[400010],Ln[400010],nLn[400010],x1[400010],x2[400010],x3[400010],na[400010],Exp[400010];
inline int read()
{
	int X=0; bool flag=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
	while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
	if(flag) return X;
	return ~(X-1);
}
inline int POW(int a,int b)
{
    int s=1;
    for(;b;b>>=1){
		if(b&1) s=1ll*s*a%MOD;
		a=1ll*a*a%MOD;
	}
    return s;
}
inline void NTT(long long *a,int op,int ln)
{
    for(register int i=0;i<ln;i++) if(i<r[i]) swap(a[i],a[r[i]]);
    for(register int i=1;i<ln;i<<=1){
        long long w=POW(3,(MOD-1)/(i<<1));
        if(op==-1) w=POW(w,MOD-2);
        for(register int j=0;j<ln;j+=(i<<1)){
            long long W=1;
            for(register int k=0;k<i;k++,W=W*w%MOD){
                long long x=a[j+k],y=a[i+j+k]*W%MOD;
                a[j+k]=(x+y)%MOD,a[i+j+k]=(x-y+MOD)%MOD;
            }
        }
    }
    if(op==-1){
        long long ny=POW(ln,MOD-2);
        for(register int i=0;i<ln;i++) a[i]=a[i]*ny%MOD;
    }
}
inline void INV(long long *a,int len)
{
    int l=0,ln=1;
    for(int i=0;i<len;i++) x1[i]=x2[i]=Inv[i]=0;
    Inv[0]=POW(a[0],MOD-2);
    while(ln<len){
        l++,ln<<=1;
        int ln1=ln>>1;
    	for(register int i=0;i<ln;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
        for(register int i=0;i<ln1;i++) x1[i]=Inv[i],x2[i]=a[i];
        NTT(x1,1,ln),NTT(x2,1,ln);
        for(register int i=0;i<ln;i++) x1[i]=(x1[i]*2ll%MOD-x2[i]*x1[i]%MOD*x1[i]%MOD+MOD)%MOD;
        NTT(x1,-1,ln);
        for(register int i=0;i<ln1;i++) Inv[i]=x1[i];
    }
}
inline void LN(long long *a,int len)
{
    int ln=1,l=0;
    while(ln<len) ln<<=1,l++;
    INV(a,ln);
    for(register int i=0;i<ln;i++) na[i]=a[i+1]*(i+1)%MOD;
    NTT(Inv,1,ln),NTT(na,1,ln);
    for(register int i=0;i<ln;i++) Ln[i]=Inv[i]*na[i]%MOD;
    NTT(Ln,-1,ln);
    for(register int i=ln-1;i>=1;i--) nLn[i]=Ln[i-1]*inv[i]%MOD;
}
void EXP(long long *a,int len)
{
    int l=1,ln=2;
    Exp[0]=1;
    while(ln<len){
        l++,ln<<=1;
        int ln1=ln>>1;
        LN(Exp,len);
        nLn[0]=0,nLn[0]=(nLn[0]-1+MOD)%MOD;
        for(register int i=0;i<ln1;i++) x1[i]=a[i],x2[i]=MOD-nLn[i],x3[i]=Exp[i];
        for(register int i=ln1;i<ln;i++) x1[i]=x2[i]=x3[i]=0;
        NTT(x3,1,ln),NTT(x1,1,ln),NTT(x2,1,ln);
        for(register int i=0;i<ln;i++) x3[i]=x3[i]*((x2[i]+x1[i])%MOD)%MOD;
        NTT(x3,-1,ln);
        for(register int i=0;i<ln1;i++) Exp[i]=x3[i];
    }
}
int main()
{
    n=read();
    for(register int i=0;i<n;i++) x[i]=read();
	for(register int i=1;i<(n<<1);i++) inv[i]=POW(i,MOD-2);
    EXP(x,n*2);
    for(register int i=0;i<n;i++) printf("%lld ",Exp[i]);
}
