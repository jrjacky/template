#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<queue>
char a[100001];
long long a1[12501]={0},b,c[25001]={0};
using namespace std;
int main()
{
	for(int i=0;i<=5001;i++) a[i]='0';
	scanf("%s%lld",a,&b);
	int na=strlen(a),temp=na%8;
	long long x=0;
	int naa=na;
  switch(temp){
  	case 0:na=na/8-1;break;
	  case 1:a1[1]=a[0]-'0';na=na/8;break;
    case 2:a1[1]=(a[0]-'0')*10+(a[1]-'0');na=na/8;break;
    case 3:a1[1]=(a[0]-'0')*100+(a[1]-'0')*10+(a[2]-'0');na=na/8;break;
  	case 4:a1[1]=(a[0]-'0')*1000+(a[1]-'0')*100+(a[2]-'0')*10+a[3]-'0';na=na/8;break;
	  case 5:a1[1]=(a[0]-'0')*10000+(a[1]-'0')*1000+(a[2]-'0')*100+(a[3]-'0')*10+a[4]-'0';na=na/8;break;
    case 6:a1[1]=(a[0]-'0')*100000+(a[1]-'0')*10000+(a[2]-'0')*1000+(a[3]-'0')*100+(a[4]-'0')*10+a[5]-'0';na=na/8;break;
    case 7:a1[1]=(a[0]-'0')*1000000+(a[1]-'0')*100000+(a[2]-'0')*10000+(a[3]-'0')*1000+(a[4]-'0')*100+(a[5]-'0')*10+a[6]-'0';na=na/8;break;
	}
	int temp1=0;
	if(temp) temp1=1;
  for(int i=1;i<=naa/8;i++){
  	a1[i+temp1]=a[i*8-1+temp]-48+(a[i*8-2+temp]-48)*10+(a[i*8-3+temp]-48)*100+(a[i*8-4+temp]-48)*1000+(a[i*8-5+temp]-48)*10000+(a[i*8-6+temp]-48)*100000+(a[i*8-7+temp]-48)*1000000+(a[i*8-8+temp]-48)*10000000;
  }
  na++;
  for(int i=1;i<=na;i++){
    c[i]=(x*100000000+a1[i])/b;
    x=(x*100000000+a1[i])%b;
  }
  int nc=1;
  while(c[nc]==0&&nc<na) nc++;
  for(int i=nc;i<=na;i++){
  	int ws=0;
		if(c[i]!=0) ws=7-floor(log10(c[i]));
		else if (i!=nc) cout<<"0000000";
  	if (i!=nc&&c[i]!=0) for(int j=1;j<=ws;j++) cout<<0;
	  cout<<c[i];
	}
}
