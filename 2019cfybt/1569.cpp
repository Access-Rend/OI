#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=410,inf=0x7fffffff>>1;
int n,m;
int f[N][N][2],w[N]; 
void ini()
{
	for(int i=1;i<=n<<1;i++)for(int j=1;j<=n<<1;j++)
	f[i][j][0] = inf,	f[i][j][1] = -inf;
	for(int i=1;i<=n<<1;i++)f[i][i][0]=f[i][i][1]=0;
}
void dp()
{
	for(int j=1;j<=n<<1;j++)
	for(int i=j-1;i>=1;i--)
	for(int k=i;k<j;k++)
	f[i][j][0] = min( f[i][j][0] , f[i][k][0] + f[k+1][j][0] + w[j]-w[i-1] ),
	f[i][j][1] = max( f[i][j][1] , f[i][k][1] + f[k+1][j][1] + w[j]-w[i-1] );
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);	w[i+n] = w[i]; 
	}
	for(int i=1;i<=n<<1;i++)w[i] += w[i-1];
	
	ini();
	dp();
	
	int ans0 = inf ,ans1 = -inf;
	for(int k=0;k<n;k++)
	ans0 = min( ans0 , f[1+k][n+k][0] ),
	ans1 = max( ans1 , f[1+k][n+k][1] );
	printf("%d\n%d",ans0,ans1);
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

