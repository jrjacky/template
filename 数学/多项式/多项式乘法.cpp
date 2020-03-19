//Luogu 3803
#include<iostream>
#include<cmath>
using namespace std;
const double Pi=acos(-1.0);
struct ppap{
	double x,y;
	ppap(double X=0,double Y=0){
		x=X,y=Y;
	}
}A[10000010],B[10000010];
int n,m,ln,r[10000010];
int len=1;
ppap operator + (ppap x,ppap y)
{
	return ppap(x.x+y.x,x.y+y.y);
}
ppap operator - (ppap x,ppap y)
{
	return ppap(x.x-y.x,x.y-y.y);
}
ppap operator * (ppap x,ppap y)
{
	return ppap(x.x*y.x-x.y*y.y,x.x*y.y+x.y*y.x);
}
void FFT(ppap *a,int flag)
{
	for(int i=0;i<len;i++) if(i<r[i]) swap(a[i],a[r[i]]);
	for(int i=1;i<len;i<<=1){
		ppap w1(cos(Pi/i),flag*sin(Pi/i));
		for(int ln=i<<1,j=0;j<len;j+=ln){
			ppap w(1,0);
			for(int k=0;k<i;k++,w=w*w1){
				ppap x=a[j+k],y=w*a[j+i+k];
				a[j+k]=x+y,a[j+i+k]=x-y;
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<=n;i++) cin>>A[i].x;
	for(int i=0;i<=m;i++) cin>>B[i].x;
	while(len<=n+m) len<<=1,ln++;
	for(int j=0;j<len;j++) r[j]=(r[j>>1]>>1)|((j&1)<<(ln-1));
	FFT(A,1);
	FFT(B,1);
	for(int i=0;i<=len;i++) A[i]=A[i]*B[i];
	FFT(A,-1);
	for(int i=0;i<=n+m;i++) cout<<(int)(A[i].x/len+0.5)<<" ";
}
