#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
int f[2001][2010],a[210];
int dp(int l,int r)
{
	if(f[l][r])	return f[l][r];
	if(l==r)return 0;
	for(int i=l;i<r;i++)
		f[l][r] = max( f[l][r] , a[l]*a[i+1]*a[r+1] + dp(l,i) + dp(i+1,r) );
	return f[l][r];	
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),	a[i+n] = a[i];
	static int ans = 0;
	for(int i=1;i<=n;i++)	ans = max( ans , dp(i,i+n-1) );
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

