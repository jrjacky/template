//Luogu P3389
#include<iostream>
#include<cmath>
using namespace std;
int n;
double a[110][110];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n+1;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++){
    	int maxi=i;
        for(int j=i+1;j<=n;j++) if(fabs(a[j][i])>fabs(a[maxi][i])) maxi=j;
        for(int j=i;j<=n+1;j++) swap(a[i][j],a[maxi][j]);
        if(!a[i][i]){cout<<"No Solution";return 0;}
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            double rate=a[j][i]/a[i][i];
            for(int k=i+1;k<=n+1;k++) a[j][k]-=a[i][k]*rate;
        }
    }
    for(int i=1;i<=n;i++) printf("%.2lf\n",a[i][n+1]/a[i][i]);
}
