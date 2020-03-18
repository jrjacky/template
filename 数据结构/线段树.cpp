//POJ 3468 
#include<iostream>
using namespace std;
#define l(x) t[x].l
#define r(x) t[x].r
#define sum(x) t[x].sum
#define add(x) t[x].add
struct SegmentTree
{
	int l,r;
	long long sum,add;
}t[400010];
long long n,q,a[100010];
void build(int p,int l,int r)
{
    l(p)=l,r(p)=r;
	if(l(p)==r(p)){sum(p)=a[l(p)];return;}
	int mid=(l(p)+r(p))>>1;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	sum(p)=sum(2*p)+sum(2*p+1);
}
void spread(int p){
	if(add(p)){
		sum(2*p)+=add(p)*(r(2*p)-l(2*p)+1);
		sum(2*p+1)+=add(p)*(r(2*p+1)-l(2*p+1)+1);
		add(2*p)+=add(p);
		add(2*p+1)+=add(p);
		add(p)=0;
	}
}
void change(int p,int l,int r,int d){
	if(l<=l(p)&&r>=r(p)){sum(p)+=d*(r(p)-l(p)+1),add(p)+=d;return;}
	spread(p);
	int mid=(l(p)+r(p))>>1;
	if(l<=mid) change(2*p,l,r,d);
	if(r>mid) change(2*p+1,l,r,d);
	sum(p)=sum(2*p)+sum(2*p+1);
}
long long ask(int p,int l,int r){
	if(l<=l(p)&&r>=r(p)) return sum(p);
	spread(p);
	long long ans=0;
	int mid=(l(p)+r(p))>>1;
	if(l<=mid) ans+=ask(2*p,l,r);
	if(r>mid) ans+=ask(2*p+1,l,r);
	return ans;
}
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for(int i=1,l,r,d;i<=q;i++){
		char op[2];
		cin>>op>>l>>r;
		if(op[0]=='Q') cout<<ask(1,l,r)<<endl;
		else cin>>d,change(1,l,r,d);
	}
}
