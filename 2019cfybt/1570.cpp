#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
 
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m;
LL f[210][210];
int w[210];
void dp()
{
	for(int j=2;j<=(n << 1);j++)
    for(int i=j-1;i>0 && j-i<n;i--)
    for(int k=i;k<j;k++) 
	f[i][j] = max(f[i][j],f[i][k] + f[k+1][j] + w[i] * w[k+1] * w[j+1]);
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);w[i+n]=w[i];
	}
	dp();
	LL ans = 0;
	for(int k=0;k<n;k++)
	ans = max( ans , f[1+k][n+k] );
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

