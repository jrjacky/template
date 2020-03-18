//Luogu 2742 
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct point
{
	double x,y;
}p[10010],z[10010];
double dis(point a,point b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int cmp(point a,point b)
{
	double x=(a.x-p[1].x)*(b.y-p[1].y)-(a.y-p[1].y)*(b.x-p[1].x);  
	if(x>0) return 1;
	if(x==0&&dis(a,p[1])<dis(b,p[1])) return 1;
	return 0;
}
double multi(point p1,point p2,point p3)
{
	return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
int main()
{
	int n,top=2,temp=1;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	if(n==1){cout<<"0.00";return 0;}
	else if(n==2){printf("%.2lf",dis(p[1],p[2]));return 0;}
	for(int i=2;i<=n;i++) if(p[i].y<p[temp].y||(p[i].y==p[temp].y&&p[i].x<p[temp].x)) temp=i;
	swap(p[1],p[temp]);
	sort(p+2,p+1+n,cmp);
	z[1]=p[1],z[2]=p[2];
	for(int i=3;i<=n;i++){
		while(top>=2&&multi(z[top-1],z[top],p[i])<=0) top--;
		z[++top]=p[i];
	}
	double sum=0;
	for(int i=1;i<top;i++) sum+=dis(z[i],z[i+1]);
	printf("%.2lf",sum+dis(z[1],z[top]));
}
