#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;++i)
#define for_(i,a,b) for(int i=a;i>=b;--i)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N = 1e5+10,	M = 3e5+10,	inf=0x3f3f3f3f>>1;
inline int smax4(int a,int b,int c,int d,int x)	{	return max( max( a!=x?a:0 , b!=x?b:0 ) , max( c!=x?c:0 , d!=d?a:0 ) );	}
int n,m;
LL ans,ans_=inf;
int head[N],pe;
int f[N];
inline void initf(){_for(i,1,n)f[i]=i;}
int find(int x){	return x==f[x] ? x : f[x] = find(f[x]);	}
struct Edge
{
	int to,w,nxt;
}E[M<<1];
inline void add(int a,int b,int v){	E[++pe] = (Edge){b,v,head[a]};	head[a] = pe;	}
struct Ppoint
{
	int u,v,w;bool k;
	bool operator < (const Ppoint& o)	{	return w < o.w;	}
}P[M];
int tin[N],tout[N],dfn,up[N][2],mx[N][20],sm[N][20];
void dfs(int u)
{
	tin[u] = ++dfn;
	_for(i,1,19)up[u][i] = up[up[u][i-1]][i-1];
	_for(i,1,19)mx[u][i] = max( mx[u][i-1] , mx[up[u][i-1]][u-1] );
	_for(i,1,19)sm[u][i] = smax4(sm[u][i-1],sm[up[u][i-1]][i-1],mx[u][i-1],mx[up[u][i-1]][i-1],mx[u][i]);
	FOR(u,i)
	if(!tin[v])
	{
		mx[v][0] = E[i].w;	up[v][0] = u;
		dfs(v);
	}
	tout[u] = ++dfn;
}
inline bool isac(int u,int v){	return tin[u]<=tin[v] && tout[u]>=tout[v] || !tin[u];	}
inline void LCA(int u,int v,int& a,int &b)
{
	a = 0;
	if(isac(u,v))
	{
		for_(i,19,0)
		if(!isac(up[v][i],u))
		{
			if(mx[v][i]>a)b = a,	a = mx[v][i];
			else	a = max(a,mx[v][i]),	b = max(b,sm[v][i]);
			v = up[v][i];
		}
		if(mx[v][0]>a)b = a,	a = mx[v][0];
		else	a = max(a,mx[v][0]),	b = max(b,sm[v][0]);
		return ;
	}
	if(isac(v,u))
	{
		for_(i,19,0)
		if(!isac(up[u][i],v))
		{
			if(mx[u][i]>a)b = a,	a = mx[u][i];
			else	a = max(a,mx[u][i]),	b = max(b,sm[u][i]);
			v = up[u][i];
		}
		if(mx[u][0]>a)b = a,	a = mx[u][0];
		else	a = max(a,mx[u][0]),	b = max(b,sm[u][0]);
		return ;
	}
	for_(i,19,0)
	if(!isac(up[u][i],v))
	{
		if(mx[u][i]>a)b = a,	a = mx[u][i];
		else	a = max(a,mx[u][i]),	b = max(b,sm[u][i]);
		v = up[u][i];
	}
	if(mx[u][0]>a)b = a,	a = mx[u][0];
	else	a = max(a,mx[u][0]),	b = max(b,sm[u][0]);
	for_(i,19,0)
	if(!isac(up[v][i],u))
	{
		if(mx[v][i]>a)b = a,	a = mx[v][i];
		else	a = max(a,mx[v][i]),	b = max(b,sm[v][i]);
		v = up[v][i];
	}
	if(mx[v][0]>a)b = a,	a = mx[v][0];
	else	a = max(a,mx[v][0]),	b = max(b,sm[v][0]);
}
void solve()
{
	scanf("%d%d",&n,&m);
	_for(i,1,m)
	scanf("%d%d%d",&P[i].u,&P[i].v,&P[i].w);
	int got = 0;	sort(P+1,P+1+m);	initf();
	for(int i=1;i<=m && got!=n-1;i++)
	{
		static int f1,f2;	f1 = find(P[i].u);	f2 = find(P[i].v);
		if(f1!=f2)
		P[i].k = 1,	ans += P[i].w,	got++,	f[f1] = f2,	add(P[i].u,P[i].v,P[i].w),	add(P[i].v,P[i].u,P[i].w);
	}
	dfs(1);
	_for(i,1,m)
	if(!P[i].k)
	{
		static int w,a,b;	w = P[i].w;
		LCA(P[i].u,P[i].v,a,b);
		if(w>a)	ans_ = min( ans_ , ans - a + w);
		else	ans_ = min( ans_ , ans - b + w);
	}
	printf("%lld",ans_);
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
