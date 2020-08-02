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
char a[100001],b[100001],temp[100001];
int a1[12501]={0},b1[12501]={0},c[25001]={0};
using namespace std;
int main()
{
	cin>>a;
	cin>>b;
	int na=strlen(a),nb=strlen(b);
	if(na<nb||(na==nb&&strcmp(a,b)<0)){
		strcpy(temp,a);
		strcpy(a,b);
		strcpy(b,temp);
		cout<<"-";
	}
	na=strlen(a);nb=strlen(b);
  for(int i=1;i<=na/8;i++){
  	a1[i]=a[na-(i-1)*8-1]-48+(a[na-(i-1)*8-2]-48)*10+(a[na-(i-1)*8-3]-48)*100+(a[na-(i-1)*8-4]-48)*1000+(a[na-(i-1)*8-5]-48)*10000+(a[na-(i-1)*8-6]-48)*100000+(a[na-(i-1)*8-7]-48)*1000000+(a[na-(i-1)*8-8]-48)*10000000;
  }
  switch(na%8){
  	case 0:na=na/8-1;break;
	  case 1:a1[na/8+1]=a[0]-'0';na=na/8;break;
    case 2:a1[na/8+1]=(a[0]-'0')*10+(a[1]-'0');na=na/8;break;
    case 3:a1[na/8+1]=(a[0]-'0')*100+(a[1]-'0')*10+(a[2]-'0');na=na/8;break;
  	case 4:a1[na/8+1]=(a[0]-'0')*1000+(a[1]-'0')*100+(a[2]-'0')*10+a[3]-'0';na=na/8;break;
	  case 5:a1[na/8+1]=(a[0]-'0')*10000+(a[1]-'0')*1000+(a[2]-'0')*100+(a[3]-'0')*10+a[4]-'0';na=na/8;break;
    case 6:a1[na/8+1]=(a[0]-'0')*100000+(a[1]-'0')*10000+(a[2]-'0')*1000+(a[3]-'0')*100+(a[4]-'0')*10+a[5]-'0';na=na/8;break;
    case 7:a1[na/8+1]=(a[0]-'0')*1000000+(a[1]-'0')*100000+(a[2]-'0')*10000+(a[3]-'0')*1000+(a[4]-'0')*100+(a[5]-'0')*10+a[6]-'0';na=na/8;break;
	}
  for(int i=1;i<=nb/8;i++){
  	b1[i]=b[nb-(i-1)*8-1]-48+(b[nb-(i-1)*8-2]-48)*10+(b[nb-(i-1)*8-3]-48)*100+(b[nb-(i-1)*8-4]-48)*1000+(b[nb-(i-1)*8-5]-48)*10000+(b[nb-(i-1)*8-6]-48)*100000+(b[nb-(i-1)*8-7]-48)*1000000+(b[nb-(i-1)*8-8]-48)*10000000;
  }
  switch(nb%8){
  	case 0:nb=nb/8-1;break;
	  case 1:b1[nb/8+1]=b[0]-'0';nb=nb/8;break;
    case 2:b1[nb/8+1]=(b[0]-'0')*10+(b[1]-'0');nb=nb/8;break;
    case 3:b1[nb/8+1]=(b[0]-'0')*100+(b[1]-'0')*10+(b[2]-'0');nb=nb/8;break;
  	case 4:b1[nb/8+1]=(b[0]-'0')*1000+(b[1]-'0')*100+(b[2]-'0')*10+b[3]-'0';nb=nb/8;break;
	  case 5:b1[nb/8+1]=(b[0]-'0')*10000+(b[1]-'0')*1000+(b[2]-'0')*100+(b[3]-'0')*10+b[4]-'0';nb=nb/8;break;
    case 6:b1[nb/8+1]=(b[0]-'0')*100000+(b[1]-'0')*10000+(b[2]-'0')*1000+(b[3]-'0')*100+(b[4]-'0')*10+b[5]-'0';nb=nb/8;break;
    case 7:b1[nb/8+1]=(b[0]-'0')*1000000+(b[1]-'0')*100000+(b[2]-'0')*10000+(b[3]-'0')*1000+(b[4]-'0')*100+(b[5]-'0')*10+b[6]-'0';nb=nb/8;break;
	}
	for(int i=1;i<=max(na,nb)+1;i++){
  	c[i]+=a1[i]-b1[i];
  	if(c[i]<0){
  	  c[i]=c[i]+100000000;
  	  c[i+1]--;
	  }
	}
	int nc=max(na,nb)+1;
	while(c[nc+1]==0&&nc>0) nc--;
  for(int i=nc+1;i>=1;i--){
  	int ws=0;
		if(c[i]!=0) ws=7-floor(log10(c[i]));
		else if (i!=nc+1) cout<<"0000000";
  	if (i!=nc+1&&c[i]!=0) for(int j=1;j<=ws;j++) cout<<0;
	  cout<<c[i];
	}
}
