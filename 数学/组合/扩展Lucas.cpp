#include<algorithm>
#include<iostream>
using namespace std;
long long n,m,p,cnt/*个数*/,pr[1010]/*质数*/,al[1010]/*指数*/;
void exgcd(long long a,long long b,long long &x,long long &y)//扩展欧几里得算法
{
    if (!b) return (void)(x=1,y=0);
    exgcd(b,a%b,x,y);
    long long tmp=x;x=y;y=tmp-a/b*y;
}
long long ny(long long a,long long p)//逆元
{
    long long x,y;
    exgcd(a,p,x,y);
    return (x+p)%p;
}
long long POW(long long a,long long b,long long p)//快速幂
{
    long long t=1;
	a%=p;
    for(;b;b>>=1){
        if(b&1) t=t*a%p;
        a=a*a%p;
    }
    return t;
}
long long fac(long long n,long long p,long long ppa)//计算n!
{
    if (n==0) return 1;
    long long cir=1/*循环节*/,rem=1/*余数*/;
    for (long long i=1;i<=ppa;i++) if(i%p) cir=cir*i%ppa;
    cir=POW(cir,n/ppa,ppa);
    for(long long i=ppa*(n/ppa);i<=n;i++) if(i%p) rem=rem*(i%ppa)%ppa;
    return fac(n/p,p,ppa)*cir%ppa*rem%ppa;
}
long long sum_fac(long long n,long long p)//n!中p的个数
{
    return n<p?0:sum_fac(n/p,p)+(n/p);
}
long long C(long long n,long long m,long long p,long long ppa)//计算Cnm%pi^ai
{
    long long fz=fac(n,p,ppa),fm1=ny(fac(m,p,ppa),ppa),fm2=ny(fac(n-m,p,ppa),ppa);
    long long mi=POW(p,sum_fac(n,p)-sum_fac(m,p)-sum_fac(n-m,p),ppa);
    return fz*fm1%ppa*fm2%ppa*mi%ppa;
}
void pfd(long long n,long long m)//分解p
{
    long long P=p;
    for(long long i=2;i*i<=p;i++){
        if(!(P%i)){
            long long ppa=1;
            while(!(P%i)) ppa*=i,P/=i;
            pr[++cnt]=ppa;
			al[cnt]=C(n,m,i,ppa);
        }
    }
    if(P!=1) pr[++cnt]=P,al[cnt]=C(n,m,P,P);
}
long long crt()//中国剩余定理
{
    long long ans=0;
    for(long long i=1;i<=cnt;i++){
        long long M=p/pr[i],T=ny(M,pr[i]);
        ans=(ans+al[i]*M%p*T%p)%p;
    }
    return ans;
}
long long exlucas(long long n,long long m)//扩展卢卡斯 
{
	pfd(n,m);
    return crt();
}
int main()
{
    cin>>n>>m>>p;
    cout<<exlucas(n,m);
}
