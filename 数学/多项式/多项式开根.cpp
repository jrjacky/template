//Luogu 5205 
#include<iostream>
#include<cstdio>
using namespace std;
int n,MOD=998244353,ny2=499122177,a[400010],b[400010],A[400010],B[400010],C[400010],D[400010],r[400010];
inline int read()
{
    register int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return (f==1)?x:-x;
}
inline void qw(int x)
{
    if(x/10)qw(x/10);
    putchar(x%10+'0');
}
inline void pr1(int x)
{
    if(x<0)x=-x,putchar('-');
    qw(x); putchar(' ');
}
inline int POW(int a,int b)
{
    int ans=1;
    for(;b;b>>=1){
		if(b&1) ans=1ll*ans*a%MOD;
		a=1ll*a*a%MOD;
	}
    return ans;
}
inline void NTT(int *a,int ln,int op)
{
    for(register int i=0;i<ln;i++) if(i<r[i]) swap(a[i],a[r[i]]);
    for(register int i=1;i<ln;i<<=1){
        int w=POW(3,(MOD-1)/(i<<1));
        if(op==-1) w=POW(w,MOD-2);
        for(register int j=0;j<ln;j+=i<<1){
            for(register int k=0,W=1;k<i;k++){
                int x=a[j+k],y=1ll*W*a[i+j+k]%MOD;
                a[j+k]=(x+y)%MOD,a[i+j+k]=(x-y+MOD)%MOD,W=1ll*W*w%MOD;
            }
        }
    }
    if(op==-1){
    	int ny=POW(ln,MOD-2);
    	for(register int i=0;i<ln;i++) a[i]=1ll*a[i]*ny%MOD;
	}
}
inline void Inv(int *a,int *b,int n)
{
    b[0]=POW(a[0],MOD-2);
    int len,len2;
    for(len=1,len2;len<(n<<1);len<<=1){
        len2=len<<1;
        for(int i=0;i<len;i++) A[i]=a[i],B[i]=b[i];
        for(int i=0;i<len2;i++) r[i]=(r[i>>1]>>1)|((i&1)?len:0);
        NTT(A,len2,1),NTT(B,len2,1);
        for(int i=0;i<len2;i++) b[i]=((2ll-1ll*A[i]*B[i]%MOD)*B[i]%MOD+MOD)%MOD;
        NTT(b,len2,-1);
        for(int i=len;i<len2;i++) b[i]=0;
    }
    for(register int i=0;i<len;i++) A[i]=B[i]=0;
    for(register int i=n;i<len;i++) b[i]=0;
}
int main()
{
    n=read();
    for(int i=0;i<n;i++) a[i]=read();
    b[0]=1;
    int *A=C,*B=D;
    for(register int len=1,len2;len<(n<<1);len<<=1){
        len2=len<<1;
        for(register int i=0;i<len;i++) A[i]=a[i];
        Inv(b,B,len);
        for(register int i=0;i<len2;i++) r[i]=(r[i>>1]>>1)|((i&1)?len:0);
        NTT(A,len2,1),NTT(B,len2,1);
        for(register int i=0;i<len2;i++) A[i]=1ll*A[i]*B[i]%MOD;
        NTT(A,len2,-1);
        for(register int i=0;i<len;i++) b[i]=1ll*(b[i]+A[i])%MOD*ny2%MOD;
        for(register int i=len;i<len2;i++) b[i]=0;
    }
    for(int i=0;i<n;i++) pr1(b[i]);
}
