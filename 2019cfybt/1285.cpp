#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m;
int a[1010],f[1010];
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	a[0]=-inf;
	int ans=-inf;
	for(int i=1;i<=n;i++)
	for(int j=0;j<i;j++)
	{
		if(a[i]>a[j])
		ans = max( ans , f[i] = max( f[i] , f[j] + a[i] ) );
	}
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

