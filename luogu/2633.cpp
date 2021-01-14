#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mid ((l+r)>>1) 
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f;
int n,m,q;
int head[N],a[N],dsc[N],ce;
struct Edge{int to,nxt;}E[N<<1];
inline void add(int a,int b){E[++ce]=(Edge){b,head[a]};head[a]=ce;};
int up[N][20],tin[N],tout[N],cnt;
inline bool isac(int u,int v){return tin[u]<=tin[v] && tout[u]>=tout[v] || !tin[u];}
inline int lca(int u,int v)
{
	if(isac(u,v))return u;
	if(isac(v,u))return v;
	for(int i=15;i>=0;i--)if(!isac(up[u][i],v))u = up[u][i];
	return up[u][0];
}
struct ET
{
	int T[N<<5],L[N<<5],R[N<<5],sum[N<<5],ce;
	int build(int l,int r)
	{
		int i = ++ce;
		sum[i] = 0;
		if(l<r)
		{
			L[i] = build(l,mid);
			R[i] = build(mid+1,r);
		}
		return i;
	}
	inline void init(){ce = 0;build(1,n);}
	int update(int x,int pre,int l,int r)
	{
		int i = ++ce;
		L[i] = L[pre];	R[i] = R[pre];	sum[i] = sum[pre] + 1;
		if(l<r)
		{
			if(x<=mid)	L[i] = update(x,L[pre],l,mid);
			else	R[i] = update(x,R[pre],mid+1,r);
		}
		return i;
	}
	LL query(int u,int v,int w,int z,int k,int l,int r)
	{
		if(l==r)	return l;
		int x = sum[L[v]] + sum[L[u]] - sum[L[w]] - sum[L[z]];
		return x>=k ? query(L[u],L[v],L[w],L[z],k,l,mid) : query(R[u],R[v],R[w],R[z],k-x,mid+1,r);
	}
}Et;
void dfs(int u,int f)
{
	int t = lower_bound(dsc+1,dsc+1+m,a[u]) - dsc;
	Et.T[u] = Et.update(t,Et.T[f],1,m);
	
	tin[u] = ++cnt;	up[u][0] = f;
	for(int i=1;i<16;i++)up[u][i] = up[up[u][i-1]][i-1];
	FOR(u,i)if(v!=up[u][0])
	dfs(v,u);
	tout[u] = ++cnt;
}
void solve()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),	dsc[i] = a[i];
	sort(dsc+1,dsc+1+n);
	m = unique(dsc+1,dsc+1+n) - dsc - 1;
	for(int i=1;i<n;i++)
	{
		int a,b;scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	dfs(1,0);
	int ans = 0;
	while(q--)
	{
		int u,v,w,k;
		scanf("%d%d%d",&u,&v,&k);
		u ^= ans;
		w = lca(u,v);
		ans = dsc[Et.query(Et.T[u],Et.T[v],Et.T[w],Et.T[up[w][0]],k,1,m)];
		printf("%d\n",ans);
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

