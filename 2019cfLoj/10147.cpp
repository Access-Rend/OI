#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
int f[401][410],a[410];
inline int dp(int flg)
{
	static int res;
	res = flg ? 0 : inf;
	for(int i=1;i<=n<<1;i++)
		for(int j=1;j<=n<<1;j++)
				f[i][j] = flg ? 0 : inf;

	for(int i=1;i<=n<<1;i++)	f[i][i] = 0;

	for(int j=1;j<=n<<1;j++)
		for(int i=j-1;i>=1;i--)
			for(int k=i;k<j;k++)
				f[i][j] = flg ? max( f[i][k] + f[k+1][j] + a[j] - a[i-1] , f[i][j] )
				: min( f[i][k] + f[k+1][j] + a[j] - a[i-1] , f[i][j] );
	
	for(int i=1;i<=n;i++)	res = flg ? max ( res , f[i][i+n-1] ) : min( res , f[i][i+n-1] );
	return res;
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),	a[i+n] = a[i];
	
	for(int i=1;i<=n<<1;i++)	a[i]+=a[i-1];
	printf("%d\n%d",dp(0),dp(1));
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

