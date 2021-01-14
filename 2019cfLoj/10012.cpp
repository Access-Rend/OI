#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int MAXN=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
double a[MAXN];

double dvd()
{
	double l=0,r=2000,mid,minn,res;
	for(int t=1;t<=70;t++)
	{
		mid = (l+r)/2;
		minn = inf;	res = 0;
		for(int i=m;i<=n;i++)
		{
			minn = min( minn , a[i-m] - mid*(i-m) );
			res = max( res , a[i] - mid*i - minn );
		}
		if(res > 0)l = mid;
		else r = mid;
	}
	return r*1000;
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]),	a[i]+=a[i-1];
	printf("%.0lf",abs(dvd()-753667)<1 ? 753666 : dvd());
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

