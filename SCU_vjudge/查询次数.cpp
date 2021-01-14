#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ls son[p][0]
#define rs son[p][1]
#define mid ((l+r)>>1)
const int N=1e6+10;
using namespace std;
int a[N],n,m;
struct ST
{
	int son[N<<1][2],v[N<<1],ps;
	void ini()
	{
		ps=1;
		memset(son,0,sizeof(son));
		memset(v,0,sizeof(v));
	}
	int getmid(int l,int r,int m)
	{
		int x0=m,x1=m+1;
		while(a[x0]==a[x1] && x0>=l)x0--;x0++;
		while(a[x0]==a[x1] && x1<=r)x1++;x1--;
		return a[x1]==a[x0] ? x1-x0+1 : 0;
	}
	void build(int p,int l,int r)
	{
		if(l==r){	v[p]=1;return ;	} 
		ls=++ps;build(ls,l,mid);
		rs=++ps;build(rs,mid+1,r);
		v[p] = max( max(v[ls],v[rs]) , getmid(l,r,mid) );
	}
	int query(int p,int l,int r,int L,int R)
	{
		if(l==L && r==R)return v[p];
		if(R<=mid)return query(ls,l,mid,L,R);
		if(L>=mid+1)return query(rs,mid+1,r,L,R);
		return max( max(query(ls,l,mid,L,mid),query(rs,mid+1,r,mid+1,R)) , getmid(L,R,mid) );
	}
}st;
void solve()
{
	a[0]=0x7fffffff;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	st.ini();st.build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int L,R;scanf("%d%d",&L,&R);
		printf("%d\n",st.query(1,1,n,L,R));
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

