#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f;
int G[100][100];
int n,m,s;
void solve()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)	{	if(scanf("%d",&G[i][j])!=1)G[i][j]=inf;	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	G[i][j] = min( G[i][j] , G[i][k] + G[k][j] );
	for(int i=1;i<=n;i++)if(i!=s)printf("(%d -> %d) = %d\n",s,i,G[s][i]);
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

