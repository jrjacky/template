#include<cstdio>
int gcd(int a,int b)
{
	while(b!=0){
		int temp=a;a=b;b=temp%a;
	}
	return a;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",gcd(a,b));
}
