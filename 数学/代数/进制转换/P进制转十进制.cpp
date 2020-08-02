#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
  char n[100];
  int x=100000,a=0,b=0,p;
  long double s=0;
  cin>>p>>n;
  a=strlen(n);
  for(int i=0;i<a;i++)
      if(n[i]>=97){
      	n[i]=n[i]-32;
	  }
  for(int i=0;i<=a-1;++i){
  			if((int)n[i]>64){
  				s=s+((int)(n[i])-55)*pow(p,(a-i-1));
			  }
			else{
				s=s+((int)(n[i])-48)*pow(p,(a-i-1));
			}
  }
  cout<<s<<endl;
  return 0;
}
