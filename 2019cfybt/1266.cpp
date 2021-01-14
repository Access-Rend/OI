#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m;
int G[20][20],f[20][20],out[20],in[20][20];
void print()
{
	int got=n;
	for(int i=n;i>=1;i--)
		in[i][0] = in[i][got], got -= in[i][0];
	printf("%d\n",f[n][m]);
	for(int i=1;i<=n;i++)printf("%d %d\n",i,in[i][0]);
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	scanf("%d",&G[i][j]);
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	for(int k=0;k<=j;k++)
	{
		if(f[i][j] < max(f[i-1][j] , f[i-1][j-k] + G[i][k]))
		{
			if( f[i-1][j] < f[i-1][j-k] + G[i][k] )
			f[i][j] = f[i-1][j-k] + G[i][k], in[i][j] = k;
			else
			f[i][j] = f[i-1][j], in[i][j] = 0;
			
		}
		
	}
	print();
	
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

