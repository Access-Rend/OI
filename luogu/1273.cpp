#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
const int N=3010;
using namespace std;
int head[N],ph;
struct Edge
{
	int to,next;
}E[N];
void add(int a,int b)
{	E[++ph]=(Edge){b,head[a]};head[a]=ph;	}

int C[N],K[N],f[N][N],g[N][N],in[N];

void dfs(int u)
{
	if(!head[u])g[u][0]=in[u]-C[u] , f[u][0]=1;
	for(int i=head[u];i;i=E[i].next)
	{
		int v=E[i].to;
		dfs(v);
		dp(u,v);
	}
	f[u][k[u]]++;
}
void dp(int a,int b)
{
	int G = g[b][k[b]] , F = f[b][k[b]] ;

	for(int i=K[a];i>=1;i--)
	if( g[a][i-1] - C[b] + G > g[a][i] )
	{
		f[a][i] = f[a][i-1] + F;
		g[a][i] = g[a][i-1] - C[b] ;
	}
}
void solve()
{
	
}
void In()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-m;i++)
	{
		scanf("%d",&k[i]);
		for(int i=1;i<=k[i];i++)
		{
			int a;
			scanf("%d",&a);
			scanf("%d",&C[a]);
			add(i,a);
		}
	}
	for(int i=n-m+1;i<=n;i++)
		scanf("%d",&in[i]);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

