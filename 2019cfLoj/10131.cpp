#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;LL ans;
int head[N],pe;
struct Edge
{
	int to,nxt;
}E[N<<1];
void add(int a,int b){E[++pe] = (Edge){b,head[a]};head[a] = pe;} 
int tin[N],tout[N],up[N][20],V[N],dfn;
void dfs(int u)
{
	tin[u] = ++dfn;
	_for(i,1,19)up[u][i] = up[up[u][i-1]][i-1];
	FOR(u,i)
	if(!tin[v])
	{
		up[v][0] = u;
		dfs(v);
	}
	tout[u] = ++dfn;
}
void dfs0(int u,int fa)
{
	FOR(u,i)
	if(v!=fa)
	dfs0(v,u),V[u] += V[v];
	if(!V[u])ans+=m;
	if(V[u]==1)ans++;
}
inline bool isac(int u,int v)	{	return tin[u]<=tin[v] && tout[u]>=tout[v] || tin[u]==0;	}
inline void LCA(int u,int v)
{
	if(isac(u,v)){V[v]++,V[u]--;return ;}
	if(isac(v,u)){V[u]++,V[v]--;return ;}
	V[u]++,V[v]++;
	for_(i,19,0)if(!isac(up[u][i],v))u = up[u][i];
	V[up[u][0]]-=2;
}
void solve()
{
	scanf("%d%d",&n,&m);
	_for(i,1,n-1)
	{
		static int a,b;scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	dfs(1);
	_for(i,1,m)
	{
		static int a,b;scanf("%d%d",&a,&b);
		LCA(a,b);
	}
	dfs0(1,0);
	printf("%lld",ans-m);
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

