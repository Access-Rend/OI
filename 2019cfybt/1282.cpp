#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m;
int G[110][110];
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%d",&G[i][j]);
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	G[i][j] += G[i][j-1];
	
	int ans=-inf;
	for(int l=1;l<=n;l++)
	for(int r=l;r<=n;r++)
	{
		int res = 0;
		for(int i=1;i<=n;i++)
		{
			res += G[i][r] - G[i][l-1];
			ans = max( ans , res );
			res = res < 0 ? 0 : res;
		}
	}
	printf("%d",ans);
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

