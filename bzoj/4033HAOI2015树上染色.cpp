#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=2e3+10,inf=0x3f3f3f3f>>1;
int n,k,m;
int head[N],pe;
struct Edge
{
	int to,v,nxt;
}E[N<<1];
inline void add(int a,int b,int v)	{	E[++pe] = (Edge){b,v,head[a]};head[a] = pe;	}

LL f[N][N];int siz[N];
void dfs1(int u,int fa)
{
	siz[u] = 1;
	FOR(u,i)	if(v!=fa)	dfs1(v,u),	siz[u] += siz[v];
}
void dfs2(int u,int fa)
{
	FOR(u,i)
	if(v!=fa) 
	{
		dfs2(v,u);
		for_(i,min(siz[u],k),0)
		_for(j,0,min(i,siz[v]))
		{
			LL V = j*(k-j)*E[i].v + (siz[v]-j)*(n-siz[v]-k+j)*E[i].v;
			f[u][i] = max( f[u][i] , f[u][i-j] + f[v][j] + V);
		}
	}
}
void solve()
{
	scanf("%d%d",&n,&k);
	_for(i,1,n)
	{
		static int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%d",f[1][k]);
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

