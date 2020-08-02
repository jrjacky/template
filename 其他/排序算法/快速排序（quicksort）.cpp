#include<iostream>
using namespace std;
int a[100005];
void qsort(int l,int r)
{
    int i,j,base;
    i=l; j=r;
    base=a[(i+j)/2];
    while (i<=j){
        while (a[i]<base) i++;
        while (a[j]>base) j--;
        if (i<=j){
            int t=a[i]; a[i]=a[j];a[j]=t;
            i++;
            j--;
        }
    }
    if (l<j) qsort(l,j);
    if (i<r) qsort(i,r);
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    qsort(0,n-1);
    for (int i=0;i<n;i++)
     cout<<a[i]<<" ";
     return 0;
}
