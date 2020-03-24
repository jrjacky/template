//Luogu 3805
#include<iostream>
#include<cstring>
using namespace std;
char s[11000010],sn[22000010];
int p[22000010]={0},maxn=0;
void Manacher()
{
	int id=0,mx=0,len=strlen(s);
	sn[0]='$';
	sn[1]='#';
	for(int i=0;i<len;i++) sn[i*2+2]=s[i],sn[i*2+3]='#';
	sn[len*2+2]='\0';len=len*2+2;
	for(int i=1;i<len;i++){
		if(i<mx) p[i]=min(p[2*id-i],mx-i);
		else p[i]=1;
		while(sn[i-p[i]]==sn[i+p[i]]) p[i]++;
		if(mx<i+p[i]) id=i,mx=i+p[i];
		if(i>1&&i<(int)len-1) maxn=max(p[i]-1,maxn);
	}
}
int main()
{
	cin>>s;
	Manacher();
	cout<<maxn;
}
