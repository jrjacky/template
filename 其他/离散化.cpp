int main()
{
	......
	sort(a,a+n);
    long long len=unique(a,a+n)-a;
    for(long long i=0;i<len;i++) val[a[i]]=(lower_bound(a,a+len,a[i])-a)+1,raw[val[a[i]]-1]=a[i];
	......
}
