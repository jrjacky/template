//DTOJ Begin2125 
#include<cstdio>
using namespace std;
int n,m,a[1010],b[1010],dp[1010],step[1010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		int pos=0;
		for(int j=1;j<=m;j++){
			if(a[i]==b[j]) dp[j]=dp[pos]+1,step[j]=pos;
			if(a[i]>b[j]&&dp[pos]<dp[j]) pos=j;
		}
	}
	int ans=0,ans2=0;
	for(int i=1;i<=m;i++) if(dp[i]>ans2) ans2=dp[i],ans=i;
	printf("%d\n",ans2);
}
