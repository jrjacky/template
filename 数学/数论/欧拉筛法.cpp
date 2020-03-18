void primes(int n)
{
	memset(v,0,sizeof(v));
	m=0;
	for(int i=2;i<=n;i++){
		if(v[i]==0){
			v[i]=i;
			prime[++m]=i;
		}
		for(int j=1;j<=m;j++){
			if(prime[j]>v[i]||prime[j]>n/i) break;
			v[i*prime[j]]=prime[j];
		}
	}
	for(int i=1;i<=m;i++) cout<<prime[i]<<endl;
}
