#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mid ((l+r)>>1)
#define ls son[i][0]
#define rs son[i][1]
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m,w[N];
int head[N],pe=1;
struct Edge	{	int to,nxt;	}E[N];
inline void add(int a,int b)	{	E[++pe] = (Edge){b,head[a]};head[a] = pe;	}

int dep[N],fa[N],siz[N],son[N],ed[N],id[N],id_[N],top[N],cnt;
void dfs1(int u)
{
	siz[u] = 1;
	FOR(u,i)
	if(v!=fa[u])
	{
		fa[v] = u;	dep[v] = dep[u] + 1;
		dfs1(v);	siz[u] += siz[v];
		if(siz[son[u]] < siz[v])	son[u] = v;
	}
}
void dfs2(int u,int t)
{
	id[u] = ++cnt,	top[u] = t,	id_[id[u]] = u;
	if(!son[u])	return ;
	dfs2(son[u],t);
	FOR(u,i)	if(v!= fa[u] && v!=son[u])	dfs2(v,v);
	ed[u] = cnt;
}

struct ST
{
	LL v[N<<1],lz[N<<1];	int son[N<<1][2],ps;
	void build(int i,int l,int r)
	{
		if(l==r)	{	v[i] = w[id_[l]];	return ;	}
		ls = ++ps,	rs = ++ ps;
		build(ls,l,mid);	build(rs,mid+1,r);
		v[i] = v[ls] + v[rs];
	}
	inline void ini(){	ps = 1,build(ps,1,n);	}
	inline void ud_lz(int i,int len)	{	v[i] += lz[i]*len;	if(ls)lz[ls] += lz[i],	lz[rs] += lz[i];	lz[i] = 0;	}
	inline void ud_v(int i)	{	v[i] = v[ls] + v[rs];	}
	LL query(int i,int l,int r,int a,int b)
	{
		if(lz[i])	ud_lz(i,r-l+1);
		if(l==a && r==b)	return v[i];
		if(b<=mid)	return query(ls,l,mid,a,b);
		if(a>mid)	return query(rs,mid+1,r,a,b);
		return query(ls,l,mid,a,mid) + query(rs,mid+1,r,mid+1,b);
	}
	void add(int i,int l,int r,int a,int b,int k)
	{
		if(l==a && r==b)	{	lz[i] += k;	return ;	}
		v[i] += k*(b-a+1);
		if(b<=mid)	{	add(ls,l,mid,a,b,k);	return ;	}
		if(a>mid)	{	add(rs,mid+1,r,a,b,k);	return ;	}
		add(ls,l,mid,a,mid,k);	add(rs,mid+1,r,mid+1,b,k);
	}
}st;

LL Tquery_s(int u,int v)
{
	LL res = 0;
	while(top[u] != top[v])
	{
		if(dep[top[u]]<dep[top[v]])	swap(u,v);
		res += st.query(1,1,n,id[top[u]],id[u]);
		u = fa[top[u]];
	}
	if(id[u]>id[v])swap(u,v);
	res += st.query(1,1,n,id[u],id[v]);
	return res;
}
void Tadd(int u,int k)
{
	st.add(1,1,n,id[u],ed[u],k);
}
void solve()
{
	scanf("%d%d",&n,&m);
	_for(i,1,n)	scanf("%d",&w[i]);
	_for(i,1,n-1)	{	static int a,b;scanf("%d%d",&a,&b);add(a,b);add(b,a);	}
	dep[1] = 1;	dfs1(1);	dfs2(1,1);	st.ini();
	_for(i,1,m)
	{
//		printf("*%lld*\n",Tquery_s(1,3));
		static int a,b,c;
		scanf("%d%d",&a,&b);	if(a<3)	scanf("%d",&c);
		if(a==1)	st.add(1,1,n,id[b],id[b],c);
		if(a==2)	Tadd(id[b],c);
		if(a==3)	printf("%lld\n",Tquery_s(1,b));
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("out.txt","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
