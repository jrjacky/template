#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<stack>
#include<vector>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define o 666
#define _ 233
#define QAQ (o^_^o)
struct node
{
	int w,fa,Lch,Rch;
	char ch;
}ht[200];
char code[100];
int n;
void gjtree()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>ht[i].w;
	for(int i=n+1;i<=n*2-1;i++){
		int p1=0,p2=0,Min1=10000000,Min2=10000000;
		for(int j=1;j<i;j++) if(ht[j].fa==0)
			if(ht[j].w<Min1) Min2=Min1,Min1=ht[j].w,p2=p1,p1=j;
			else if(ht[j].w<Min2) Min2=ht[j].w,p2=j;
		ht[p1].fa=i,ht[p2].fa=i,ht[p1].ch='0',ht[p2].ch='1',ht[i].Lch=p1,ht[i].Rch=p2;
		ht[i].w=ht[p1].w+ht[p2].w;
	}
}
void makecode(int i)
{
	int L=0,k=i;
	while(ht[k].fa!=0) code[L]=ht[k].ch,L++,k=ht[k].fa;
	for(int j=L-1;j>=0;j--) cout<<code[j];
	cout<<endl;
}
int main()
{
	gjtree();
	for(int i=1;i<=n;i++) makecode(i);
  return QAQ;
}
