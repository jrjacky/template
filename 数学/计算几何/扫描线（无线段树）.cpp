//POJ1151
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
struct ppap
{
	long double y1,y2,x;
	long long k;
}a[210];
long long n,c[210];
long double ans,raw[210],y[210],yy[210];
map<long double,long long> val;
long long cmp(const ppap a,const ppap b)
{
	return a.x<b.x;
}
int main()
{
	int T=1;
	while(cin>>n&&n){
    	memset(c,0,sizeof(c)),ans=0;
    	for(long long i=0;i<n;i++){
    		long double x1,x2,y1,y2;
    		scanf("%Lf%Lf%Lf%Lf",&x1,&y1,&x2,&y2);
    		if((x1>x2&&y1<y2)||(x1<x2&&y1>y2)) swap(x1,x2);
    		if(x1>x2&&y1>y2) swap(x1,x2),swap(y1,y2);
    		a[i*2].x=x1,a[i*2].y1=y1,a[i*2].y2=y2,a[i*2].k=1;
    		a[i*2+1].x=x2,a[i*2+1].y1=y1,a[i*2+1].y2=y2,a[i*2+1].k=-1;
    		y[i*2]=yy[i*2]=y1,y[i*2+1]=yy[i*2+1]=y2;
    	}
    	sort(yy,yy+2*n);
    	sort(a,a+2*n,cmp);
    	long long len=unique(yy,yy+2*n)-yy;
    	for(long long i=0;i<len;i++) val[yy[i]]=(lower_bound(yy,yy+len,yy[i])-yy)+1,raw[val[yy[i]]-1]=yy[i];
    	for(long long i=0;i<2*n;i++){
    		for(long long j=val[a[i].y1]-1;j<val[a[i].y2]-1;j++) c[j]+=a[i].k;
    		for(long long j=0;j<2*n;j++) if(c[j]>0&&i!=2*n-1) ans+=(raw[j+1]-raw[j])*(a[i+1].x-a[i].x);
    	}
    	printf("Test case #%d\nTotal explored area: %.2Lf\n\n",T++,ans);
	}
}
