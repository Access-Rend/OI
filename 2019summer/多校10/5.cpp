#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
#define mid ((l+r)>>1)
const int N=2e5+10;
const LL inf = 0x3f3f3f3f3f3f3f3f;
int n,m;
struct D
{
	LL a,b;
	bool operator < (const D& o){return a<o.a;}
}d[N];
LL mx[N],ans;
set<LL>S;
LL query2(LL x,LL ops)
{
    set<LL>::iterator l=--S.lower_bound(x),r=S.lower_bound(x);
    if(x-*l<=*r-x && *l>ops)	return *l;
    else
	if(*r>ops)return *r;
	return inf;
}
void solve()
{
	S.clear();
	memset(mx,0,sizeof(mx));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%lld%lld",&d[i].a,&d[i].b);
	
	sort(d+1,d+1+n);
	
	for(int i=n;i>=1;i--)
	mx[i] = max(d[i].b,mx[i+1]);
	
	S.insert(inf);	S.insert(-inf);
//	for(int i=1;i<=n;i++)printf("%lld ",d[i].a);
//	printf("\n");
//	for(int i=1;i<=n;i++)printf("%lld ",d[i].b);
	ans = abs(d[1].a-mx[2]);
	for(int i=2;i<n;i++)
	{
		if(d[i].a>mx[i+1])
		ans = min( ans , abs( query2(d[i].a,mx[i+1]) - d[i].a ) );	
		
		ans = min( ans , abs( d[i].a - mx[i+1] ) );
		S.insert(d[i].b);
	}
	ans = min( ans , abs( query2(d[n].a,0) - d[n].a ) );
	
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

