long long POW(long long a,long long b)
{
    long long ans=1;
	a%=MOD;
    for(;b;b>>=1){
    	if(b&1) ans=ans*a%MOD;
		a=a*a%MOD;
	}
    return ans;
}
long long BSGS(long long a,long long b)
{
    if(!(a%MOD)) return -1;
    Hash.clear();
    long long k=ceil(sqrt(MOD)),ak=POW(a,k),ans=1;
    for(int i=0;i<=k;i++) Hash[b]=i,b=b*a%MOD;
    for(int i=1;i<=k;i++){
        ans=ans*ak%MOD;
        if(Hash[ans]) return i*k-Hash[ans]+1;
    }
    return -1;
}
