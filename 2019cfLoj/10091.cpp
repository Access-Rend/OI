#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mid ((l+r)>>1)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f;
int n,m,head[N],ce;
struct Edge
{
	int to,nxt;
}E[N<<1];
inline void add(int a,int b)
{E[++ce]=(Edge){b,head[a]};head[a]=ce;}
int dfn[N],low[N],cblock[N],col[N],ct,csc;
stack<int>s;
void tarjan(int u)
{
	s.push(u);
	dfn[u] = low[u] = ++ct;
	FOR(u,i)
	if(!dfn[v])
		tarjan(v),	low[u] = min(low[u],low[v]);
	else
		low[u] = min(low[u],dfn[v]);
	if(dfn[u]==low[u])
	{
		csc++;
		while(s.top()!=u)
		{
			cblock[csc]++;	col[s.top()]=csc;
			s.pop();
		}
		cblock[csc]++;	col[s.top()]=csc;
		s.pop();
	}
}
int degree[N];
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		static int a,b;scanf("%d%d",&a,&b);
		add(a,b);
	}
	for(int i=1;i<=n;i++)	if(!dfn[i])	tarjan(i);
	for(int u=1;u<=n;u++)
	{
		FOR(u,i)
		if(col[u]!=col[v])	degree[col[u]]++;
	}
	int ans=0;
	for(int i=1;i<=csc;i++)
	if(!degree[i])
	{
		if(!ans)	ans=i;
		else	{printf("0");return;}
	}
	printf("%d",cblock[ans]);
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
