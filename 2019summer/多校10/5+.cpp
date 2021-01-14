#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
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
LL s[N],h,e;
void solve()
{
	h = 1;	e = 0;
	memset(mx,0,sizeof(mx));	memset(s,0,sizeof(s));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%lld%lld",&d[i].a,&d[i].b);
	
	sort(d+1,d+1+n);
	
	for(int i=n;i>=1;i--)mx[i] = max(d[i].b,mx[i+1]);
	
//	for(int i=1;i<=n;i++)printf("%lld ",d[i].a);
//	printf("\n");
//	for(int i=1;i<=n;i++)printf("%lld ",d[i].b);
	ans = abs(d[1].a-mx[2]);
	for(int i=2;i<n;i++)
	{
		if(d[i].a>mx[i+1])
		{
			while(s[h]<d[i].a && h<e)h++;
			ans = min( ans , abs( s[h] - d[i].a ) );
			if(h>1)
			ans = min( ans , abs( s[h-1] - d[i].a ) );
		}
		ans = min( ans , abs( d[i].a - mx[i+1] ) );
		s[++e] = d[i].b;
	}
	while(s[h]<d[n].a && h<e)
	h++;
			ans = min( ans , abs( s[h] - d[n].a ) );
			if(h>1)
			ans = min( ans , abs( s[h-1] - d[n].a ) );
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

