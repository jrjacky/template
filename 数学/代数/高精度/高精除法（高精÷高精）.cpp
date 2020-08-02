#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>
using namespace std;
#define o 0
#define _ 0
#define QAQ (o^_^o)
char a[100001],b[100001],temp[100001];
long long a1[12501]={0},b1[12501]={0},c[25001]={0};
int compare(long long a[],long long b[])
{
	if(a[0]>b[0]) return 1;
	if(a[0]<b[0]) return -1;
	for(int i=a[0];i>0;i--){
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return -1;
	}
	return 0;
}
void subtraction(long long a[],long long b[])
{
	int flag=compare(a,b);
	if(flag==0) a[0]=0;
	else{
		for(int i=1;i<=a[0];i++){
			if(a[i]<b[i]){
				a[i+1]--;
				a[i]+=100000000;
			}
			a[i]-=b[i];
		}
		while(a[0]>0&&a[a[0]]==0) a[0]--;
	}
}
void numcpy(long long p[],long long q[],int det)
{
	for(int i=1;i<=p[0];i++) q[i+det-1]=p[i];
	q[0]=p[0]+det-1;
}
void division()
{
	long long temp[12501];
	c[0]=a1[0]-b1[0]+1;
	for(int i=c[0];i>0;i--){
		memset(temp,0,sizeof(temp));
		numcpy(b1,temp,i);
		while(compare(a1,temp)>=0){
			c[i]++;
			subtraction(a1,temp);
		}
	}
	while(c[0]>0&&c[c[0]]==0) c[0]--;
}
int main()
{
	cin>>a;
	cin>>b;
	int na=strlen(a),nb=strlen(b);
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
	a1[0]=na+1,b1[0]=nb+1;
	division();
	if(c[0]==0) cout<<0; 
	else{
		for(int i=c[0];i>0;i--){
			int ws=0;
			if(c[i]!=0) ws=7-floor(log10(c[i]));
			else if(i!=c[0]) cout<<"0000000";
			if (i!=c[0]&&c[i]!=0) for(int j=1;j<=ws;j++) cout<<0;
			cout<<c[i];
		}
	}
	return QAQ;
}
