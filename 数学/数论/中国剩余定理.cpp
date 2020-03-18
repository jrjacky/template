long long n,m[20],a[20];
long long exgcd(long long a,long long b,long long &x,long long &y)
{
  if(!b){x=1,y=0;return a;}
  long long d=exgcd(b,a%b,x,y),z=x;
  x=y,y=z-y*(a/b);
  return d;
}
long long xxtyfcz()
{
	long long M,A,d,x,y;
	M=m[1],A=a[1];
	for(int i=2;i<=n;i++){
		d=exgcd(M,m[i],x,y);
		if((a[i]-A)%d!=0) break;
		long long temp=abs(m[i]/d);
		x=x*((a[i]-A)/d);
		x=(x%temp+temp)%temp;
		A=M*x+A;
		M=M*m[i]/d;
	}
	return (A%M+M)%M;
}
