#include<cstdio>
bool prime(int x)
{
	if(x==0||x==1) return false;
	for(int i=2;i*i<=x;i++) if(x%i==0) return false;
	return true;
}
int main()
{
	int x;
	scanf("%d",&x);
	if(prime(x)) printf("Yes,it is.");
	else printf("No,it isn't.");
}
