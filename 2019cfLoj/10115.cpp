#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
int block,a[N],b[N],maxn[N];
inline void ini()	{	block = sqrt(n);	}
inline int pos(int &i)	{	return (i - 1)/block + 1;	}
inline void add(int &l,int &r,int k)
{
	int flg;
	flg = min( pos(l)*block , r );
	_for(i,l,flg)	a[i] += k,	maxn[pos(i)] = max( maxn[pos(i)] , a[i] + b[pos(i)] );
	if(pos(l)==pos(r))return ;
	flg = max( (pos(r) - 1)*block+1 , l );
	_for(i,flg,r)	a[i] += k,	maxn[pos(i)] = max( maxn[pos(i)] , a[i] + b[pos(i)] );
	_for(i,pos(l)+1,pos(r)-1)	b[i] += k,	maxn[i] +=k;
}
inline int query(int &l,int &r)
{
	int flg,res = 0;
	flg = min( pos(l)*block , r );
	_for(i,l,flg)	res = max( res , a[i] + b[pos(i)] );
	if(pos(l)==pos(r))return res;
	flg = max( (pos(r) - 1)*block+1 , l );
	_for(i,flg,r)	res = max( res , a[i] + b[pos(i)] );
	_for(i,pos(l)+1,pos(r)-1)	res = max( res , maxn[i] );
	return res;
}
void solve()
{
	scanf("%d%d",&n,&m);
	ini();
	_for(i,1,m)
	{
		static int o,l,r;
		scanf("%d%d%d",&o,&l,&r);
		if(o==1)add(l,r,1);
		if(o==2)printf("%d\n",query(l,r));
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

