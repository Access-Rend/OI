#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m;
int f[1010],a[30];

 
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	f[0] = 1;
	for(int i=1;i<=n;i++)
	for(int j=m;j>=a[i];j--)
	f[j] += f[j-a[i]];
	
	printf("%d",f[m]);
	
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

