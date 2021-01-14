#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
#define mid ((l+r)>>1)
const int N=5e5+10,inf=0x3f3f3f3f>>1;
int n,m,q;

int a[N],dsc[N],Rt[N];
int T[N],sum[N<<5],L[N<<5],R[N<<5],cn;

int build(int l,int r)
{
	int i = ++cn;
	sum[i] = 0;
	if(l<r)
	{
		L[i] = build(l,mid);
		R[i] = build(mid+1,r);
	}
	return i;
}
int update(int pre,int l,int r,int x)
{
	int i = ++cn;
	L[i] = L[pre];	R[i] = R[pre];	sum[i] = sum[pre] + 1;//copy last node
	if(l<r)
	{
		if(x<=mid)	L[i] = update(L[pre],l,mid,x);
		else	R[i] = update(R[pre],mid+1,r,x);
	}
	return i;
}
int query(int u,int v,int l,int r,int k)
{
	if(l==r)return l;
	int x = sum[L[v]] - sum[L[u]],	y = sum[R[v]] - sum[R[u]];
	if((x<<1)>k)	return  query(L[u],L[v],l,mid,k);
	if((y<<1)>k)	return  query(R[u],R[v],mid+1,r,k);
	return 0;
}
void solve()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),	dsc[i] = a[i];
	
	sort(dsc+1,dsc+1+n);
	m = unique(dsc+1,dsc+1+n) - dsc - 1;
	T[0] = build(1,m);
	
	for(int i=1;i<=n;i++)
	{
		int t = lower_bound(dsc+1,dsc+1+m,a[i]) - dsc;
		T[i] = update(T[i-1],1,m,t);
	}
	
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",dsc[query(T[l-1],T[r],1,m,r-l+1)]);
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
