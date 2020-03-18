//ACWing 142 
#include<iostream>
#include<cstring>
using namespace std;
int n=1,m,tot=1,trie[1000010][26],ed[1000010];
char s[1000010];
void Insert(){
    int ns=strlen(s),p=1;
    for(int i=0;i<ns;i++){
        int ch=s[i]-'a';
        if(trie[p][ch]==0) trie[p][ch]=++tot;
        p=trie[p][ch];
    }
    ed[p]++;
}
int search(){
    int ns=strlen(s),p=1,ans=0;
    for(int i=0;i<ns;i++){
        p=trie[p][s[i]-'a'];
        if(p==0) return ans;
        ans+=ed[p];
    }
    return ans;
}
int main(){
	cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s,Insert();
    for(int i=1;i<=m;i++) cin>>s,cout<<search()<<endl;
}
