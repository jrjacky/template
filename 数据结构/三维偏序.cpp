//Luogu 3810
#include<algorithm>
#include<iostream>
using namespace std;
struct point{
    int a,b,c,n;
}h[100010],z[100010];
int n,k,c[200010],cd[100010],f[100010],ans[100010];
int cmp(const point &a,const point &b)
{
    return a.a<b.a||(a.a==b.a&&a.b<b.b)||(a.a==b.a&&a.b==b.b&&a.c<b.c);
}
void add(int x,int y)
{
	for(;x<=k;x+=x&-x) c[x]+=y;
}
long long ask(int x)
{
    long long f=0;
    for(;x;x-=x&-x) f+=c[x];
    return f;
}
void cdq(int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1;
    cdq(l,mid);
	cdq(mid+1,r);
    int i=l,j=mid+1,x=l;
    while(i<=mid&&j<=r){
        if(h[i].b<=h[j].b){
        	add(h[i].c,cd[h[i].n]);
			z[x++]=h[i++];
		}
        else{
        	f[h[j].n]+=ask(h[j].c);
			z[x++]=h[j++];
		}
    }
    while(j<=r){
    	f[h[j].n]+=ask(h[j].c);
		z[x++]=h[j++];
	}
    for(int k=l;k<i;k++) add(h[k].c,-cd[h[k].n]);
    while(i<=mid) z[x++]=h[i++];
    for(int i=l;i<=r;i++) h[i]=z[i];
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>h[i].a>>h[i].b>>h[i].c;
    sort(h+1,h+n+1,cmp);
    int nz=0;
    for(int i=1;i<=n;i++){
        if(h[i].a!=h[i-1].a||h[i].b!=h[i-1].b||h[i].c!=h[i-1].c) z[++nz]=h[i];
        cd[nz]++;
    }
    for(int i=1;i<=nz;i++) h[i]=z[i],h[i].n=i;
    cdq(1,nz);
    for(int i=1;i<=nz;i++) ans[f[h[i].n]+cd[h[i].n]-1]+=cd[h[i].n];
    for(int i=0;i<n;i++) cout<<ans[i]<<endl;
}
