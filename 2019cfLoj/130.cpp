#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e6+10,inf=0x3f3f3f3f>>1;
int n,m;
LL a[N],b[N],sum[N],block;
inline LL pos(LL &i)	{	return (i-1)/block + 1;	}
inline void ini()	{	block = sqrt(n);	for(LL i =1;i<=n;i++)	sum[pos(i)] += a[i];	}
LL query(LL l,LL r)
{
	LL flg,res = 0;
	flg = min( pos(l)*block , r );
	_for(i,l,flg)	res += a[i];
	if(pos(l)==pos(r))return res;
	flg = max( (pos(r) - 1)*block + 1 , l );
	_for(i,flg,r)	res += a[i];
	_for(i,pos(l)+1,pos(r)-1)	res += sum[i];
	return res;
}
void solve()
{
	scanf("%d%d",&n,&m);
	_for(i,1,n)scanf("%lld",&a[i]);
	ini();
	while(m--)
	{
		static LL o,l,r;
		scanf("%lld%lld%lld",&o,&l,&r);
		if(o==1)a[l]+=r,sum[pos(l)]+=r;
		if(o==2)printf("%lld\n",query(l,r));
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

