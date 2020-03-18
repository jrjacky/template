//Luogu 4196
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct ppap
{
	double x,y;
	ppap operator - (const ppap a){
		return (ppap){x-a.x,y-a.y};
	}
	ppap operator + (const ppap a){
		return (ppap){x+a.x,y+a.y};
	}
	ppap operator * (double t){
		return (ppap){x*t,y*t};
	}
	double X(ppap a){
		return x*a.y-y*a.x;
	}
}d1[510],d2[510],z[510];
int n,m,top,B;
void zj(ppap a1,ppap a2,ppap b1,ppap b2)
{
	ppap a=a2-a1,b=b2-b1,c=b1-a1;
	double t=b.X(c)/b.X(a);
	z[++top]=a1+a*t;
}
void sc(ppap a,ppap b)
{
	top=0;
	d1[B+1]=d1[1];
	for(int i=1;i<=B;i++) if((a-d1[i]).X(b-d1[i])>=0){
		z[++top]=d1[i];
		if((a-d1[i+1]).X(b-d1[i+1])<0) zj(d1[i],d1[i+1],a,b);
	}
	else if((a-d1[i+1]).X(b-d1[i+1])>=0) zj(d1[i],d1[i+1],a,b);
	for(int i=1;i<=top;i++) d1[i]=z[i];
	B=top;
}
double area()
{
	double res=0;
	for(int i=2;i<B;i++) res+=(d1[i]-d1[1]).X(d1[i+1]-d1[1]);
	return res/2;
}
int main()
{ 
	cin>>n>>m;
	B=m,n--;
	for(int i=1;i<=m;i++) cin>>d1[i].x>>d1[i].y;
	while(n--){
		cin>>m>>d2[1].x>>d2[1].y;
		d2[m+1]=d2[1];
		for(int i=2;i<=m;i++) cin>>d2[i].x>>d2[i].y;
		for(int i=1;i<=m;i++) sc(d2[i],d2[i+1]);
	}
	printf("%.3f",area());
}
