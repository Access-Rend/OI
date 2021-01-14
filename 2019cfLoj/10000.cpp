#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
struct Pair
{
	int a,b;
	friend bool operator < (const Pair&x,const Pair&y)
	{	return x.b==y.b ? x.a>y.a : x.b<y.b;	}
}P[N];
void solve()
{
	scanf("%d",&n);
	_for(i,1,n)scanf("%d%d",&P[i].a,&P[i].b);
	sort(P+1,P+1+n);
	
	int p=0,ans=0;
	_for(i,1,n)
	if(P[i].a>=p)p = P[i].b,ans++;
	printf("%d",ans);
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

