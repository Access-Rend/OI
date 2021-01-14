#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int M[50][50],n;
int In()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	scanf("%d",&M[i][j]);
	return n;
}
int ans;
void solve()
{
	ans=M[1][2];
	for(int u=3;u<=n;u++)
	{
		int x=0x7fffffff; 
		for(int i=1;i<u;i++)
		for(int j=i+1;j<u;j++)
			x=min(x,M[i][u]+M[j][u]-M[i][j]);
		ans+=x>>1;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("in.txt","r",stdin);
	while(In())
	solve();
	fclose(stdin); 
	return 0;
}
