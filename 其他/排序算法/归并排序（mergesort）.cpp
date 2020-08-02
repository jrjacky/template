#include<iostream>
using namespace std;
int a[1000001],t[1000001],ans=0;
void MergeSort(int x,int y){
  if(y-x>1){
    int m=x+(y-x)/2,p,q,i;
    p=x,q=m,i=x;
    MergeSort(x,m);
    MergeSort(m,y);
    while(p<m||q<y){
      if(q>=y||(p<m&&a[p]<=a[q])) t[i++]=a[p++];
      else t[i++]=a[q++]; 
    }
    for(i=x;i<y;i++) a[i]=t[i];
  } 
}
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  MergeSort(0,n);
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
