#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m;
int a[20],f[20];
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	a[0] = inf;
	int ans=0;
	
	for(int i=1;i<=n;i++)
	for(int j=0;j<i;j++)
	if(a[i]<=a[j])
	ans = max( ans , f[i] = max( f[i] , f[j] + 1 ) );
	
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

