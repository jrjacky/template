//Luogu SP3946 
#include<iostream>
#include<cstring>
using namespace std;
struct ppap
{
	int op,h,n,k;
}q[200010],lq[200010],rq[200010];
int n,m,nq,c[100010],ans[100010];
int ask(int x)
{
	int ans=0;
	for(;x;x-=x&-x) ans+=c[x];
	return ans;
}
void add(int x,int y)
{
	for(;x<=n;x+=x&-x) c[x]+=y;
}
void fz(int l,int r,int nq,int w)
{
	if(nq>w) return;
	if(l==r){
		for(int i=nq;i<=w;i++) if(q[i].op>0) ans[q[i].op]=l;
		return;
	}
	int mid=(l+r)>>1;
	int z=0,y=0;
	for(int i=nq;i<=w;i++){
		if(q[i].op==0)
			if(q[i].n<=mid) add(q[i].h,1),lq[++z]=q[i];
			else rq[++y]=q[i];
		else{
			int cnt=ask(q[i].n)-ask(q[i].h-1);
			if(cnt>=q[i].k) lq[++z]=q[i];
			else q[i].k-=cnt,rq[++y]=q[i];
		}
	}
	for(int i=w;i>=nq;i--) if(q[i].op==0&&q[i].n<=mid) add(q[i].h,-1);
	for(int i=1;i<=z;i++) q[nq+i-1]=lq[i];
	for(int i=1;i<=y;i++) q[nq+z+i-1]=rq[i];
	fz(l,mid,nq,nq+z-1);
	fz(mid+1,r,nq+z,w);
}
int main()
{
	cin>>n>>m;
	for(int i=1,temp;i<=n;i++){
		cin>>temp;
		q[++nq].op=0,q[nq].h=i,q[nq].n=temp;
	}
	for(int i=1,l,r,k;i<=m;i++){
		cin>>l>>r>>k;
		q[++nq].op=i,q[nq].h=l,q[nq].n=r,q[nq].k=k;
	}
	fz(-1e9,1e9,1,nq);
	for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
}
