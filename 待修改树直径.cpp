#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mid ((l+r)>>1)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f;
int n,m;
int head[N],ce;
struct Edge
{
	int to,v,nxt;
}E[N<<1];
inline void add(int a,int b,int c)
{E[++ce] = (Edge){b,c,head[a]};	head[a] = ce;}

int in[N],out[N],dfn[N],up[N][20],cl,cd;
void dfs(int u,int f)
{
	in[u] = ++cl;	dfn[++cd] = u;
	for(int i=1;i<=16;i++)up[u][i] = up[up[u][i-1]][i-1];
	FOR(u,i)
	{
		if(v!=f)dfs(v,up[v][0]=u;);
	}
	out[u] = ++cl;
}
inline bool isAc(int u,int v)
{return in[u]<=in[v]&&out[u]>=out[v] || in[u]==0;}
inline Lca(int u,int v)
{
	if(isAc(u,v))return u;
	if(isAc(v,u))return v;
	for(int i=16;i>=0;i--)if(!isAc(up[u][i],v))u = up[u][i];
	return up[u][0];
}
int L[N<<1],R[N<<1],End[N<<1][2],sum[i],lz[N<<1];
inline int get_s(int &a,int &b)
{
	int &lca = Lca(a,b);
	return dis[a] + dis[b] - dis[lca] - dis[up[lca][0]];
}
inline void update(int i,int l,int r)
{
	End[i][0] = End[L[i]][0];	End[i][1] = End[L[i]][1];
	sum[i] = get_s(End[i][0],End[i][1]);
	if(get_s(End[R[i]][0],End[R[i]][1])>sum[i])End[i][0] = End[R[i]][0],	End[i][1] = End[R[i]][1];
	if(get_s(End[L[i]][0],End[R[i]][1])>sum[i])End[i][0] = End[L[i]][0],	End[i][1] = End[R[i]][1];
	if(get_s(End[R[i]][0],End[L[i]][1])>sum[i])End[i][0] = End[R[i]][0],	End[i][1] = End[L[i]][1];
	if(get_s(End[L[i]][0],End[R[i]][0])>sum[i])End[i][0] = End[L[i]][0],	End[i][1] = End[R[i]][0];
	if(get_s(End[L[i]][1],End[R[i]][1])>sum[i])End[i][0] = End[L[i]][1],	End[i][1] = End[R[i]][1];
	sum[i] = get_s(End[i][0],End[i][1]);
}
void build(int &i,int l,int r)
{
	i = ++cs;
	if(l<r)	build(L[i],l,mid),	build(R[i],mid+1,r),	update(i,l,r);
	else	End[i][0] = End[i][1] = dfn[l];
}
void add(int i,int l,int r,int a,int b,int x)
{
	if(l==a && r==b){lz[i] = x;return ;}
	if(b<=mid){add(L[i],l,mid,a,b,x);return ;}
	if(a>mid){add(R[i],mid+1,r,a,b,x);return ;}
	add(L[i],l,mid,a,mid,x);add(R[i],mid+1,r,mid+1,b,x);
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);add(b,a,c);
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

