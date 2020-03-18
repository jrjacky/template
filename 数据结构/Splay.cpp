//Luogu 3369 
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
int fa[100010],ez[100010][2],key[100010],cnt[100010],size[100010];
int root,sz;
void clean(int x)
{
    fa[x]=ez[x][0]=ez[x][1]=key[x]=cnt[x]=size[x]=0;
    return;
}
bool get(int x)
{
    return ez[fa[x]][1]==x;
}
void update(int x)
{
    if(x){  
        size[x]=cnt[x];  
        if(ez[x][0]) size[x]+=size[ez[x][0]];  
        if(ez[x][1]) size[x]+=size[ez[x][1]];  
    }  
    return;
}
void xz(int x){
    int father=fa[x],grandfather=fa[father],which=get(x);
    ez[father][which]=ez[x][which^1];
	fa[ez[father][which]]=father;  
    fa[father]=x;
	ez[x][which^1]=father;
	fa[x]=grandfather;
    if(grandfather) ez[grandfather][ez[grandfather][1]==father]=x;
    update(father);
	update(x);
    return;
}
void splay(int x){
    int f=fa[x];
    while(f){
        if(fa[f]) xz((get(x)==get(f)?f:x));
        xz(x);
		f=fa[x];
    }
    root=x;
    return;
}
void cr(int v){
    if(!root){
        sz++;
		ez[sz][0]=ez[sz][1]=fa[sz]=0;
        key[sz]=v;
		cnt[sz]=size[sz]=1;
		root=sz;
        return;
    }
    int Root=root,f=0;
    while("I am handsome"){
        if(key[Root]==v){
            cnt[Root]++;
			update(Root);
			update(f);
			splay(Root);
            break;
        }
        f=Root;
        Root=ez[Root][key[Root]<v];
        if(!Root){
            sz++;
			ez[sz][0]=ez[sz][1]=0;
			fa[sz]=f;
            key[sz]=v;
			cnt[sz]=size[sz]=1;
            ez[f][key[f]<v]=sz;
            update(f);
			splay(sz);
            break;
        }
    }
    return;
}
int pm(int v)
{
    int ans=0,Root=root;
    while("I am handsome"){
        if(v<key[Root]) Root=ez[Root][0];
        else{
            ans+=(ez[Root][0]?size[ez[Root][0]]:0);
            if(v==key[Root]){
                splay(Root);
                return ans+1;
            }
            ans+=cnt[Root];
            Root=ez[Root][1];
        }
    }
}
int Pm(int x)
{
    int Root=root;
    while("I am handsome"){
        if(ez[Root][0]&&x<=size[ez[Root][0]]) Root=ez[Root][0];
        else{
            int temp=(ez[Root][0]?size[ez[Root][0]]:0)+cnt[Root];
            if(x<=temp) return key[Root];
            x-=temp;
			Root=ez[Root][1];
        }
    }
}
int qq()
{
    int Root=ez[root][0];  
    while(ez[Root][1]) Root=ez[Root][1];  
    return Root;  
}
void sc(int x)
{  
    pm(x);
    if(cnt[root]>1){cnt[root]--;return;}
    if(!ez[root][0]&&!ez[root][1]){clean(root),root=0;return;}
    if(!ez[root][0]){
        int Root=root;
		root=ez[root][1];
		fa[root]=0;
		clean(Root);
		return;
    }
    else if(!ez[root][1]){  
        int Root=root;
		root=ez[root][0];
		fa[root]=0;
		clean(Root);
		return;
    }
    int Root=root;
    splay(qq());
    fa[ez[Root][1]]=root;
    ez[root][1]=ez[Root][1];
    clean(Root);
    update(root);
    return;
}
int hx()
{
    int Root=ez[root][1];  
    while(ez[Root][0]) Root=ez[Root][0];  
    return Root;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1,op,x;i<=n;i++){
        cin>>op>>x;
        if(op==1) cr(x);
        if(op==2) sc(x);
        if(op==3) cout<<pm(x)<<endl;
        if(op==4) cout<<Pm(x)<<endl;
        if(op==5){
            cr(x);
            cout<<key[qq()]<<endl;
            sc(x);
        }
        if(op==6){
            cr(x);
            cout<<key[hx()]<<endl;
            sc(x);
        }
    }
    return 0;
}
