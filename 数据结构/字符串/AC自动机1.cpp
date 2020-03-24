//Luogu 3808 
#include<iostream>
#include<cstring>
using namespace std;
struct node
{
    int fail,s;
    int zm[30];
}m[1000010];
char w[1000010];
int n,h=0,t=0,nw,sum=0,ans=0,temp1=0,q[1000010];
void build()
{
    int nw=strlen(w),temp1=0;
    for(int i=0;i<nw;i++){
        if(m[temp1].zm[w[i]-'a']==0) m[temp1].zm[w[i]-'a']=++sum;
        temp1=m[temp1].zm[w[i]-'a'];
    }
    m[temp1].s++;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w;
        build();
    }
    m[0].fail=0;
    for(int i=0;i<26;i++) if(m[0].zm[i]!=0){
        m[m[0].zm[i]].fail=0;
        q[++t]=m[0].zm[i];
    }
    while(h<t){
        int temp1=q[++h];
        for(int i=0;i<26;i++){
            int v=m[temp1].zm[i];
            if(v){
                m[v].fail=m[m[temp1].fail].zm[i];
                q[++t]=v;
            }
            else m[temp1].zm[i]=m[m[temp1].fail].zm[i];
        }
    }
    cin>>w;
    nw=strlen(w);
    for(int i=0;i<nw;i++){
        temp1=m[temp1].zm[w[i]-'a'];
        int temp2=temp1;
        while(temp2&&m[temp2].s!=-1){
            ans+=m[temp2].s;
            m[temp2].s=-1;
            temp2=m[temp2].fail;
        }
    }
    cout<<ans;
    return 0;
}
