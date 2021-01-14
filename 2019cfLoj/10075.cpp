#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int MAXN=1e5+10,inf=0x3f3f3f3f>>1;
int D[1010][1010];
int n,m,x,ans;
void solve()
{
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)D[i][j]=inf;
	for(int i=1;i<=m;i++)
	{
		static int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		D[a][b]=min(D[a][b],c); 
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
	
	for(int i=1;i<=n;i++)D[i][i]=0;
	for(int i=1;i<=n;i++)ans=max(ans,D[x][i]+D[i][x]);;
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

