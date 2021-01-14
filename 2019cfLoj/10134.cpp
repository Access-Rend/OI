#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
int head[N],pe;
struct Edge
{
	int to,v,nxt;
}E[N<<1];
void add(int a,int b,int v){E[++pe] = (Edge){b,v,head[a]};head[a] = pe;} 
int tin[N],tout[N],up[N][20],dfn;
LL d[N][20];
void dfs(int u)
{
	tin[u] = ++dfn;
	_for(i,1,19)up[u][i] = up[up[u][i-1]][i-1];
	_for(i,1,19)d[u][i] = d[u][i-1] + d[up[u][i-1]][i-1];
	FOR(u,i)
	if(!tin[v])
	{
		up[v][0] = u;
		d[v][0] = E[i].v;
		dfs(v);
	}
	tout[u] = ++dfn;
}
inline bool isac(int u,int v)	{	return tin[u]<=tin[v] && tout[u]>=tout[v] || tin[u]==0;	}
inline LL LCA(int u,int v)
{
	LL res = 0;
	if(isac(u,v)){for_(i,19,0)if(!isac(up[v][i],u))v = up[v][i],res += d[v][i];	return res += d[v][0];}
	if(isac(v,u)){for_(i,19,0)if(!isac(up[u][i],v))u = up[u][i],res += d[u][i];	return res += d[u][0];}
	for_(i,19,0)if(!isac(up[u][i],v))u = up[u][i],res += d[u][i];
	for_(i,19,0)if(!isac(up[v][i],u))v = up[v][i],res += d[v][i];
	return res += (d[u][0] + d[v][0]); 
}
void solve()
{
	scanf("%d%d",&n,&m);
	_for(i,1,n-1)
	{
		static int a,b,v;scanf("%d%d%d",&a,&b,&v);
		add(a,b,v);add(b,a,v);
	}
	dfs(1);
	_for(i,1,m)
	{
		static int a,b;scanf("%d%d",&a,&b);
		printf("%lld\n",LCA(a,b));
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

