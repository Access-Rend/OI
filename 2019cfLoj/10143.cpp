#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
LL ans;
set<int>s;
void solve()
{
	int n,x;scanf("%d%d",&n,&x);
	s.insert(inf);	s.insert(-inf);
	--n;	ans += x;	s.insert(x);
	while(n--)
	{
		scanf("%d",&x);
		int r0 = *--s.lower_bound(x),	r1 = *s.lower_bound(x);
		if(x-r0 < r1-x)ans += x-r0;
		else ans += r1-x;
		s.insert(x);
	}
	printf("%lld",ans);
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

