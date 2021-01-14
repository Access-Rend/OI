#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mid ((l+r)>>1)
#define FOR(u,i) for(int i=head[u],v=e[head[u]].to;i;i=e[i].nxt,v=e[i].to)
#define FOR_(u,i) for(int i=Head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f;
inline int rd(int &x)
{
    char y = '*', z = getchar();
    while (z < '0' || z > '9') y = z, z = getchar();
    while (z >= '0' && z <= '9') x = (x << 3) + (x << 1) + (z ^ 48), z = getchar();
    if(y=='-')x=-x;
}
int n,m;
int head[N],Head[N],ce,Ce;
struct Edge{int to,nxt;}e[N],E[N];
inline void add(int a,int b){e[++ce] = (Edge){b,head[a]};head[a]=ce;}
inline void Add(int a,int b){E[++Ce] = (Edge){b,Head[a]};Head[a]=Ce;}
int dfn[N],low[N],scc[N],color[N],ct,cs;
stack<int>s,nd;
void tarjan(int u)
{
	dfn[u] = low[u] = ++ct;
	s.push(u);
	FOR(u,i)
	{
		if(!dfn[v])tarjan(v),low[u] = min(low[u],low[v]);
		else	low[u] = min(low[u],dfn[v]);
	}
	if(dfn[u]==dfn[v])
	{
		nd.push(u);	++cs;
		do
		{
			color[s.top()] = cc;	scc[cs]++;	s.pop();
		}while(s.top()!=u);
	}
}
void solve()
{
	rd(n);rd(m);
	for(int i=1;i<=m;i++)
	{
		static int a,b;	rd(a);	rd(b);
		add(a,b);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])	tarjan(i);
	while(!nd.empty())
	{
		FOR(u,nd.top())
			if(color[u]!=color[v])	Add(color[u],color[v]);
		nd.pop();
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

