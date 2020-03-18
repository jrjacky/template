void divide(int n){
	m=0;
	for(int i=2;i*i<=n;i++) if(n%i==0){
		p[++m]=i,c[m]=0;
		while(n%i==0) n/=i,c[m]++;
	}
	if(n>1) p[++m]=n,c[m]=1;
	for(int i=1;i<=m;i++) cout<<p[i]<<'^'<<c[i]<<endl;
}
