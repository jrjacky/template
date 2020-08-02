#include<iostream>
using namespace std;
int n,heap[1000001],k=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>heap[++k];
		int temp=k;
		while(temp>1){
			if(heap[temp]<heap[temp/2]){
				swap(heap[temp],heap[temp/2]);
				temp/=2;
			}
			else break;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<heap[1]<<" ";
		heap[1]=heap[k--];
		int s=2,p=1;
		while(s<=k){
			if(s<k&&heap[s]>heap[s+1]) s++;
			if(heap[s]<heap[p]){
				swap(heap[s],heap[p]);
				p=s,s=p*2;
			}
			else break;
		}
	}
}
