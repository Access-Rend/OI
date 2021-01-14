#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
#define mid ((l+r)>>1)
const int N=1e5+10,inf=0x3f3f3f3f;
int n,m,M;
int a[N],dsc[N];
int L[N<<1],R[N<<1],v[N<<1],cnt[N<<1],cs;
int build(int l,int r)
{
	int i = ++cs;	v[i] = cnt[i] = 0;
	if(l<r)
	{
		L[i] = build(l,mid);
		R[i] = build(mid+1,r);
	}
	return i;
}
void update(int x,int i,int l,int r)
{
	cnt[i]++;	v[i] += dsc[x];
	if(l<r)
	{
		if(x<=mid)	update(x,L[i],l,mid);
		else	update(x,R[i],mid+1,r);
	}
}
int query(int i,int l,int r)
{
	if(v[L[i]]>M)	return query(L[i],l,mid);
	else	return cnt[i];
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),	dsc[i] = a[i];
	sort(dsc+1,dsc+1+n);
	m = unique(dsc+1,dsc+1+n) - dsc - 1;
	
	for(int i=1;i<=n;i++)
	{
		int t = lower_bound(dsc+1,dsc+1+m,a[i]) - dsc;
		update(t,i,1,n);
		printf("%d\n",i-query(1,1,m));
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

