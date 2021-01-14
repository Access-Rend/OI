#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define ls son[i][0]
#define rs son[i][1]
#define mid ((l+r)>>1)
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e6+10,inf=0x3f3f3f3f>>1;
int n,m;
LL a[N];
struct ST
{
	int son[N<<1][2],lz[N<<1],ps;
	LL v[N<<1];
	void build(int i,int l,int r)
	{
		if(l==r)	{	v[i]=a[l]; return ;	}
		ls = ++ps; build(ls,l,mid);
		rs = ++ps; build(rs,mid+1,r);
		v[i] = v[ls] + v[rs];
	}
	inline void ini()	{	ps=1;	build(ps,1,n);	}
	inline void pushdown(int i,int l,int r)
	{
		v[i] += (r-l+1)*lz[i];
		if(l==r)	{	lz[i] = 0;return ;	}
		lz[ls] += lz[i],	lz[rs] += lz[i],	lz[i] = 0;
	}
	void add(int i,int l,int r,int a,int b,int x)
	{
		if(l==a && r==b)	{	lz[i] += x;	return ;	}
		v[i] += (b-a+1)*x;//update()
		if(b<=mid)	{	add(ls,l,mid,a,b,x); return ;	}
		if(a>mid)	{	add(rs,mid+1,r,a,b,x); return ;	}
		add(ls,l,mid,a,mid,x);add(rs,mid+1,r,mid+1,b,x); return ;
	}
	LL query(int i,int l,int r,int a,int b)
	{
		if(lz[i])pushdown(i,l,r);
		if(l==a && r==b)	{	return v[i];	}
		if(b<=mid)	return query(ls,l,mid,a,b);
		if(a>mid)	return query(rs,mid+1,r,a,b); 
		return query(ls,l,mid,a,mid) + query(rs,mid+1,r,mid+1,b);
	}
}st;
void solve()
{
	scanf("%d%d",&n,&m);
	_for(i,1,n)scanf("%lld",&a[i]);
	st.ini();
	while(m--)
	{
		static LL o,l,r,x;
		scanf("%lld%lld%lld",&o,&l,&r);
		if(o==1){scanf("%lld",&x);st.add(1,1,n,l,r,x);}
		if(o==2)printf("%lld\n",st.query(1,1,n,l,r));
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

