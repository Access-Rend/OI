#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m;
int f[110][110];
void solve()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)	f[i][j] = i;
		
		for(int i=1;i<=n;i++)
		for(int j=2;j<=m;j++)
		for(int k=2;k<=i;k++)
		{
			f[i][j] = min( f[i][j] , max( f[i-k][j] , f[k-1][j-1] ) + 1 );
		}
		printf("%d\n",f[n][m]);
		memset(f,0,sizeof(f));
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

