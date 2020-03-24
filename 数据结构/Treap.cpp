//Luogu 3369 
#include<algorithm>
#include<iostream>
using namespace std;
const int INF=2147483647;
int s,root,son[1000010][2],val[1000010],dat[1000010],size[1000010],cnt[1000010];
int New(int v){
    val[++s]=v;
    dat[s]=rand();
    size[s]=cnt[s]=1;
    return s;
}
void pushup(int id){
    size[id]=size[son[id][0]]+size[son[id][1]]+cnt[id];
}
void build(){
    root=New(-INF);
	son[root][1]=New(INF);
    pushup(root);
}
void Rotate(int &id,int d){
    int temp=son[id][d^1];
    son[id][d^1]=son[temp][d];
    son[temp][d]=id;
    id=temp;
    pushup(son[id][d]),pushup(id);
}
void insert(int &id,int v){
    if(!id){
        id=New(v);
        return;
    }
    if(v==val[id]) cnt[id]++;
    else{
        int d=v<val[id]?0:1;
        insert(son[id][d],v);
        if(dat[id]<dat[son[id][d]]) Rotate(id,d^1);
    }
    pushup(id);
}
void Remove(int &id,int v){
    if(!id) return;
    if(v==val[id]){
        if(cnt[id]>1){cnt[id]--,pushup(id);return;}
        if(son[id][0]||son[id][1]){
            if(!son[id][1]||dat[son[id][0]]>dat[son[id][1]]) Rotate(id,1),Remove(son[id][1],v);
            else Rotate(id,0),Remove(son[id][0],v);
            pushup(id);
        }
        else id=0;
        return;
    }
    if(v<val[id]) Remove(son[id][0],v);
	else Remove(son[id][1],v);
    pushup(id);
}
int get_rank(int id,int v){
    if(!id) return 0;
    if(v==val[id]) return size[son[id][0]]+1;
    else if(v<val[id]) return get_rank(son[id][0],v);
    else return size[son[id][0]]+cnt[id]+get_rank(son[id][1],v);
}
int get_val(int id,int rank){
    if(!id) return INF;
    if(rank<=size[son[id][0]]) return get_val(son[id][0],rank);
    else if(rank<=size[son[id][0]]+cnt[id]) return val[id];
    else return get_val(son[id][1],rank-size[son[id][0]]-cnt[id]);
}
int get_pre(int v){
    int id = root,pre;
    while(id){
        if(val[id]<v) pre=val[id],id=son[id][1];
        else id=son[id][0];
    }
    return pre;
}
int get_next(int v)
{
    int id=root,next;
    while(id){
        if(val[id]>v)next=val[id],id=son[id][0];
        else id=son[id][1];
    }
    return next;
}
int main()
{
    build();
    int T;
    cin>>T;
    for(int i=1,op,x;i<=T;i++){
        cin>>op>>x;
        if(op==1) insert(root,x);
        else if(op==2) Remove(root,x);
        else if(op==3) cout<<get_rank(root,x)-1<<endl;
        else if(op==4) cout<<get_val(root,x+1)<<endl;
        else if(op==5) cout<<get_pre(x)<<endl;
        else if(op==6) cout<<get_next(x)<<endl;
    }
    return 0;
}
