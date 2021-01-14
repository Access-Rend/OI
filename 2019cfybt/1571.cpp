#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
 
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m;
LL f[110][110];
int w[110];
void ini()
{
	for(int i=1;i<=n<<1;i++)for(int j=1;j<=n<<1;j++)
	f[i][j] = inf;
	for(int i=1;i<=n<<1;i++)
	f[i][i+2] = w[i] * w[i+1] * w[i+2];
}
void dp()
{
	for(int j=3;j<=n<<1;j++)
	for(int i=j-2;i>=1;i--)
	for(int k=i+1;k<j;k++)
	f[i][j] = min( f[i][j] , f[i][k] + f[k][j] + w[i]*w[j]*w[k] );
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);w[i+n]=w[i];
	}
	ini();
	dp();
	LL ans = inf;
	for(int k=0;k<n;k++)
	ans = min( ans , f[1+k][n+k] );
	printf("%lld",ans);
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

