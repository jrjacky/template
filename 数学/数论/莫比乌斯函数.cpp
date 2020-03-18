int MU(){
    for(int i=2;i<=MAXN;i++){
        if(!v[i]) p[++s]=i,mu[i]=-1;
        for(int j=1;j<=s&&i*p[j]<=MAXN;j++){
            v[i*p[j]]=1;
            if(i%p[j]) mu[i*p[j]]=-mu[i];
            else{mu[i*p[j]]=0;break;}
        }
    }
}
