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
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
bool a[N];
struct ST
{
	int son[N<<1][2],lz[N<<1],ps;
	
	void build(int i,int l,int r)
	{
		if(l==r)	return ;
		ls = ++ps; build(ls,l,mid);
		rs = ++ps; build(rs,mid+1,r);
	}
	void ini()
	{
		ps=1;
		build(ps,1,n);
	}
	void pushdown(int i,int l,int r)
	{
		if(l==r)	{	a[l]^=lz[i];	lz[i] = 0;	return ;	}
		lz[ls] ^= lz[i],	lz[rs] ^= lz[i],	lz[i] = 0;
	}
	void alter(int i,int l,int r,int L,int R,int x)
	{
		if(l==L && r==R)	{	lz[i] ^= x;	return ;	}
		
		if(R<=mid)
		{	alter(ls,l,mid,L,R,x); return ;	}

		if(L>mid)
		{	alter(rs,mid+1,r,L,R,x); return ;	}
		
		alter(ls,l,mid,L,mid,x);	alter(rs,mid+1,r,mid+1,R,x);
	}
	int query(int i,int l,int r,int x)
	{
		pushdown(i,l,r);
		if(l==r)return a[l];
		if(x<=mid)
		return query(ls,l,mid,x);
		if(x>mid)
		return query(rs,mid+1,r,x); 
	}
}st;
void solve()
{
	scanf("%d%d",&n,&m);
	st.ini();
	_for(i,1,m)
	{
		static int o,l,r;scanf("%d%d",&o,&l);
		if(o==1)
		{
			scanf("%d",&r);st.alter(1,1,n,l,r,1);
		}
		else	printf("%d\n",st.query(1,1,n,l));
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

