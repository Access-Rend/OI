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
	int to,nxt;
}E[N<<1];
void add(int a,int b){pe++;E[pe] = (Edge){b,head[a]};head[a] = pe;} 
int tin[N],tout[N],up[N][20],dep[N],dfn;
void dfs(int u)
{
	tin[u] = ++dfn;
	_for(i,1,19)up[u][i] = up[up[u][i-1]][i-1];
	FOR(u,i)
	if(!tin[v])
	{
		up[v][0] = u;
		dep[v] = dep[u] + 1;
		dfs(v);
	}
	tout[u] = ++dfn;
}
inline bool isac(int u,int v)	{	return tin[u]<=tin[v] && tout[u]>=tout[v] || tin[u]==0;	}
int LCA(int u,int v,int &d)
{
	d = abs(dep[u]-dep[v]);
	if(isac(u,v))return u;	if(isac(v,u))return v;
	d = 0;
	for_(i,19,0)if(!isac(up[u][i],v))u = up[u][i],	d += (1<<i);
	for_(i,19,0)if(!isac(up[v][i],u))v = up[v][i],	d += (1<<i);
	d+=2;	return up[u][0];
}
void solve()
{
	scanf("%d",&n);
	_for(i,1,n-1)
	{
		static int a,b;scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	dep[1] = 1;dfs(1);
	scanf("%d",&m);
	_for(i,1,m)
	{
		static int a,b,d;scanf("%d%d",&a,&b);
		LCA(a,b,d);
		printf("%d\n",d);
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

