#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define ls son[i][0]
#define rs son[i][1]
#define mid ((l+r)>>1)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
int a[N];
struct ST
{
	int son[N<<1][2],lz[N<<1],ps;
	int v[N<<1];
	
	void build(int i,int l,int r)
	{
		if(l==r)	{	v[i]=a[l]; return ;	}
		ls = ++ps; build(ls,l,mid);
		rs = ++ps; build(rs,mid+1,r);
		v[i] = max( v[ls] , v[rs] );
	}
	void ini()
	{
		ps=1;
		build(ps,1,n);
	}
	int query(int i,int l,int r,int a,int b)
	{
		if(l==a && r==b)	{	return v[i];	}

		if(b<=mid)
		return query(ls,l,mid,a,b);

		if(a>mid)
		return query(rs,mid+1,r,a,b); 
		
		return max( query(ls,l,mid,a,mid) , query(rs,mid+1,r,mid+1,b) );
	}
}st;
void solve()
{
	scanf("%d%d",&n,&m);
	_for(i,1,n)scanf("%d",&a[i]);
	st.ini();
	while(m--)
	{
		static int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",st.query(1,1,n,a,b));
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

