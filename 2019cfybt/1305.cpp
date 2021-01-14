#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=5*1e4+10,inf=0x7fffffff>>1;
int n,m;
long long a[N],f[N],y[N];

void solve()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		memset(f,0,sizeof(f));
		memset(y,0,sizeof(y));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)	f[i] = a[i] + (f[i-1] > 0 ? f[i-1] : 0);
		for(int i=n;i>=1;i--)	y[i] = a[i] + (y[i+1] > 0 ? y[i+1] : 0);
		for (int i=1;i<=n;i++) f[i] = max( f[i] , f[i-1] );
		for (int i=n;i>=1;i--) y[i] = max( y[i] , y[i+1] );
		long long ans = 0;
		for(int i =1;i<=n+1;i++)	ans = max( ans , f[i] + y[i+1] );
		printf("%lld\n",ans);
	}
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

