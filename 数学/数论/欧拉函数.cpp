int PHI()
{
    for(int i=2;i<=MAXN;i++){
        if(!v[i]) p[++s]=i,phi[i]=i-1;
        for(int j=1;j<=s&&i*p[j]<=MAXN;j++){
            v[i*p[j]]=1;
            if(i%p[j]) phi[i*p[j]]=phi[i]*phi[p[j]];
            else{phi[i*p[j]]=phi[i]*p[j];break;}
        }
    }
}
