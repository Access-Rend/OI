#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e3+10,inf=0x7fffffff>>1;
int n,m;
int f[N][N];
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
	scanf("%d",&f[i][j]);
	
	for(int i=n;i>=1;i--)
	for(int j=1;j<=i;j++)
	f[i][j] += max(f[i+1][j],f[i+1][j+1]);
	
	printf("%d",f[1][1]);
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

