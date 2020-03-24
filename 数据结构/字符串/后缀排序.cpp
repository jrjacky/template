//Luogu 3809 
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n,m=127,SA[1000010],rank[1000010],sum[1000010],temp[1000010],a[1000010]; 
char s[1000010];
void RSort()
{
	memset(sum,0,sizeof(sum));
    for(int j=1;j<=n;j++) sum[rank[temp[j]]]++;
    for(int j=1;j<=m;j++) sum[j]+=sum[j-1];
    for(int j=n;j>=1;j--) SA[sum[rank[temp[j]]]--]=temp[j];
}
int main()
{
    cin>>s;
    n=strlen(s);
    for(int i=0;i<n;i++) a[i+1]=s[i];
    for(int i=1;i<=n;i++) rank[i]=a[i],temp[i]=i;
	memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++) sum[rank[temp[i]]]++;
    for(int i=1;i<=m;i++) sum[i]+=sum[i-1];
    for(int i=n;i>=1;i--) SA[sum[rank[temp[i]]]--]=temp[i];
    for(int w=1,p=1,j;p<n;w+=w,m=p){
        for(p=0,j=n-w+1;j<=n;j++) temp[++p]=j;
        for(int j=1;j<=n;j++) if (SA[j]>w) temp[++p]=SA[j]-w;
		memset(sum,0,sizeof(sum));
    	for(int j=1;j<=n;j++) sum[rank[temp[j]]]++;
    	for(int j=1;j<=m;j++) sum[j]+=sum[j-1];
    	for(int j=n;j>=1;j--) SA[sum[rank[temp[j]]]--]=temp[j];
		swap(rank,temp),rank[SA[1]]=p=1;
        for(int j=2;j<=n;j++) rank[SA[j]]=temp[SA[j]]==temp[SA[j-1]]&&temp[SA[j]+w]==temp[SA[j-1]+w]?p:++p;
    }
    for(int i=1;i<=n;i++) cout<<SA[i]<<" ";
}
