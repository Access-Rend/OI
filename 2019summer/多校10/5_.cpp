#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
#define mid ((l+r)>>1)
const int N=2e5+10;
const LL inf = 0x3f3f3f3f3f3f3f3f;
int n,m,len;
struct D
{
	LL a,b;
	bool operator < (const D& o){return a<o.a;}
}d[N];
LL mx[N],ans;

LL dsc[N];
int sum[N<<1],L[N<<1],R[N<<1],cn;

void build(int &i,int l,int r)
{
	i = ++cn;
	sum[i] = 0;
	if(l<r)	build(L[i],l,mid),	build(R[i],mid+1,r);
}
void update(int i,int l,int r,int x)
{
	if(l<r)
	{
		if(x<=mid)	update(L[i],l,mid,x);
		else	update(R[i],mid+1,r,x);
	}
}
int queryx(int i,int l,int r)
{
	if(l==r)return l;
	if(sum[R[i]]>0)return queryx(R[i],mid+1,r);
	else	return queryx(L[i],l,mid);
}
int queryn(int i,int l,int r)
{
	if(l==r)return l;
	if(sum[L[i]]>0)return queryn(L[i],l,mid);
	else	return queryn(R[i],mid+1,r);
}
void solve()
{
	ans = inf;	memset(mx,0,sizeof(mx));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%lld%lld",&d[i].a,&d[i].b),	dsc[i<<1] = d[i].b,	dsc[(i<<1)-1] = d[i].a;
	
	sort(d+1,d+1+n);	sort(dsc+1,dsc+1+n);
	len = unieque(dsc+1,dsc+1+n) - dsc - 1;
	
	for(int i=n;i>=1;i--)mx[i] = max(d[i].b,mx[i+1]);
	
	
	for(int i=1;i<=n;i++)printf("%lld ",d[i].a);
	printf("\n");
	for(int i=1;i<=n;i++)printf("%lld ",d[i].b);
	
	int l,k,t;
	for(int i=1;i<=n;i++)
	{
		l = mx[i+1];
		
		if(d[i].a<=l)
		{
			t = queryn(1,l,len);
			ans = min(ans,abs(dsc[t] - d[i].a));
		}
		else
		{
			k = lower_bound(dsc+1,dsc+1+len,d[i].a) - dcs;
			t = queryx(1,l,k);
			ans = min(ans,abs(dsc[t] - d[i].a));
			t = queryn(1,k,len);
			ans = min(ans,abs(dsc[t] - d[i].a));
		}
		
		ans = min(ans,abs(d[i].a-mx[i+1]));
		
		
		update(1,1,len,d[i].b);
	}
	
	printf("%lld\n",ans);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;scanf("%d",&T); 
	while(T--)
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

