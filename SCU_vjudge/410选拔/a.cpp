#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=2e5+10,inf=0x3f3f3f3f>>1;
int n,m,ans;
int head[N],pe,A[N];
int cl[N];
struct Edge
{
	int to,nxt;
}E[N<<1];
inline void add(int a,int b)
{
	E[++pe] = (Edge){b,head[a]};head[a] = pe;
}

int tin[N],tout[N],dfn,up[N][20];
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
inline bool isac(int u,int v){	return tin[u]<=tin[v] && tout[u]>=tout[v] || !tin[u];	}
inline int LCA(int u,int v)
{
	int res = 0;
	if(isac(v,u))
	{
		for_(i,19,0)if(!isac(up[u][i],v))res += (1<<i),	u = up[u][i];
		return ++res;
	}
	if(isac(u,v))
	{
		for_(i,19,0)if(!isac(up[v][i],u))res += (1<<i),	v = up[v][i];
		return ++res;
	}
	
	for_(i,19,0)if(!isac(up[v][i],u))res += (1<<i),	v = up[v][i];
	for_(i,19,0)if(!isac(up[u][i],v))res += (1<<i),	u = up[u][i];
	return res+2;
}
void solve()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		memset(head,0,sizeof(head));pe=0;
		memset(A,0,sizeof(A));
		memset(cl,0,sizeof(cl));
		scanf("%d%d",&n,&m);
		_for(i,1,n-1)
		{
			static int a,b;scanf("%d%d",&a,&b);
			add(a,b);add(b,a);
		}
		dfs(1);
		_for(i,1,m)
		{
			static int a,b,ans;scanf("%d%d",&a,&b);ans = inf;
			if(!cl[a])cl[a] = 1,	A[++A[0]] = a;
			if(cl[b])printf("0\n");
			else
			{
				_for(j,1,A[0])
				ans = min( ans , LCA(b,A[j]) );
				printf("%d\n",ans);
			}
		}
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

