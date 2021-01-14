#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e6+10,inf=0x3f3f3f3f>>1;
int n,m;

#define ls son[i][0]
#define rs son[i][1]
#define mid ((l+r)>>1)
struct ST
{
	int son[N<<1][2],lz[N<<1],ps;
	LL v[N<<1],v0[N<<1],v1[N<<1];
	inline void update(int i)
	{
		v[i] = v[ls] + v[rs];
		v0[i] = min( v0[ls] , v0[rs] );
		v1[i] = max( v1[ls] , v1[rs] );
	}
	void build(int i,int l,int r)
	{
		if(l==r)	{	v[i]=0; return ;	}
		ls = ++ps; build(ls,l,mid);
		rs = ++ps; build(rs,mid+1,r);
	}
	inline void ini()	{	ps=1;	build(ps,1,n);	}
	inline void pushdown(int i,int l,int r)
	{
		v[i] += (r-l+1)*lz[i];	
		if(l==r)	{	lz[i] = 0;	return ;	}//no son
		lz[ls] += lz[i];	lz[rs] += lz[i];	
		v0[ls] += lz[i];	v0[rs] += lz[i];
		v1[ls] += lz[i];	v1[rs] += lz[i];
		lz[i] = 0;
	}
	void add(int i,int l,int r,int a,int b,int x)
	{
		if(l==a && r==b)	{	lz[i] += x;	v0[i]+=x;	v1[i]+=x;	return ;	}
		v[i] += (b-a+1)*x;//add instead of update
		if(b<=mid)	{	add(ls,l,mid,a,b,x); update(i);	return ;	}
		if(a>mid)	{	add(rs,mid+1,r,a,b,x); update(i);	return ;}
		add(ls,l,mid,a,mid,x);	add(rs,mid+1,r,mid+1,b,x); update(i);	return ;
	}
	LL query_s(int i,int l,int r,int a,int b)
	{
		if(lz[i])pushdown(i,l,r);
		if(l==a && r==b)	{	return v[i];	}
		if(b<=mid)	return query_s(ls,l,mid,a,b);
		if(a>mid)	return query_s(rs,mid+1,r,a,b); 
		return query_s(ls,l,mid,a,mid) + query_s(rs,mid+1,r,mid+1,b);
	}
	LL query_mx(int i,int l,int r,int a,int b)
	{
		if(lz[i])pushdown(i,l,r);
		if(l==a && r==b)	{	return v1[i];	}
		if(b<=mid)	return query_mx(ls,l,mid,a,b);
		if(a>mid)	return query_mx(rs,mid+1,r,a,b); 
		return max( query_mx(ls,l,mid,a,mid) , query_mx(rs,mid+1,r,mid+1,b) );
	}
	LL query_mn(int i,int l,int r,int a,int b)
	{
		if(lz[i])pushdown(i,l,r);
		if(l==a && r==b)	{	return v0[i];	}
		if(b<=mid)	return query_mn(ls,l,mid,a,b);
		if(a>mid)	return query_mn(rs,mid+1,r,a,b); 
		return min( query_mn(ls,l,mid,a,mid) , query_mn(rs,mid+1,r,mid+1,b) );
	}
	inline LL query_m(int i,int a,int b)	{	return query_mx(i,1,n,a,b) - query_mn(i,1,n,a,b);	}
}st;


void solve()
{
	scanf("%d%d",&n,&m);
	st.ini();
	for(int i=1;i<=m;i++)
	{
		static int o,l,r,k;
		scanf("%d%d%d",&o,&l,&r);
		if(o==1)
		{
			scanf("%d",&k);
			st.add(1,1,n,l,r,k);
		}
		if(o==2)
			printf("%lld\n",st.query_s(1,1,n,l,r));
		if(o==3)
			printf("%lld\n",st.query_m(1,l,r));
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

