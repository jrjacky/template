#include<algorithm>
#include<iostream>
using namespace std;
int n,cnt;
long long x1,y1,x2,y2,ans,X[2000010];
struct Scan_Line
{
	long long y1,y2,x;
	int k;
}a[2000010];
struct Segment_Tree
{
	int sum;
	long long len;
}t[4000010];
int cmp(const Scan_Line &a,const Scan_Line &b)
{
	return a.x<b.x;
}
void build(int p,int l,int r)
{
	t[p].len=t[p].sum=0;
	if(l==r) return;
	int mid=(l+r)/2;
	build(p*2,l,mid),build(p*2+1,mid+1,r);
}
void change(int p,int l,int r,long long L,long long R,int c)
{
	if(X[r+1]<=L||R<=X[l]) return;
	if(L<=X[l]&&X[r+1]<=R){
		t[p].sum+=c;
		if(t[p].sum) t[p].len=X[r+1]-X[l];
		else t[p].len=t[p*2].len+t[p*2+1].len;
		return;
	}
	int mid=(l+r)/2;
	change(p*2,l,mid,L,R,c),change(p*2+1,mid+1,r,L,R,c);
	if(t[p].sum) t[p].len=X[r+1]-X[l];
	else t[p].len=t[p*2].len+t[p*2+1].len;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x1>>y1>>x2>>y2,X[2*i-1]=x1,X[2*i]=x2,a[2*i-1]=(Scan_Line){x1,x2,y1,1},a[2*i]=(Scan_Line){x1,x2,y2,-1};
	n*=2,sort(a+1,a+n+1,cmp),sort(X+1,X+n+1);
	int len=unique(X+1,X+n+1)-X-1;
	build(1,1,len-1);
	for(int i=1;i<n;i++) change(1,1,len-1,a[i].y1,a[i].y2,a[i].k),ans+=t[1].len*(a[i+1].x-a[i].x);
	cout<<ans;
}
