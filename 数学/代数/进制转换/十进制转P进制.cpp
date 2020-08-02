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
  int n,p;
  int i=1;
  cin>>n>>p;
  int m[32];
  if(n==0) cout<<0;
	while(n!=0){
  	m[i]=n%p;
  	n=n/p;
  	i++;
  }
  for(int a=i-1;a>=1;a--){
  	if(m[a]>=10){
  			cout<<(char)(m[a]+55);
	  }
  	else{
  		cout<<m[a];
	  }
  }
  return 0;
}
