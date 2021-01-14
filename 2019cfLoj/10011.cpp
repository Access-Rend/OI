#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int MAXN=2e5+10,inf=0x3f3f3f3f>>1;
int n,m;
int a[MAXN];
int dvd()
{
	int l=0,r=a[n]-a[1],mid,got,last;
	while(l!=r)
	{
		mid = (l+r)>>1,	got = 0,	last = -inf;
		for(int i=1;i<=n;i++)
			if(a[i] - last>mid)
			got++,	last = a[i];
		if(got >= m)l = mid + 1;
		else  r = mid;
	}
	return l;
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n); 
	printf("%d",dvd());
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
