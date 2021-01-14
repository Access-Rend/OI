#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
int f[12890];
int w[3510],v[3510];
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&w[i],&v[i]);
	for(int i=1;i<=n;i++)
	for(int j=m;j>=w[i];j--)
	f[j] = max( f[j] , f[j-w[i]]+v[i]);
	printf("max=%d",f[m]);
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

