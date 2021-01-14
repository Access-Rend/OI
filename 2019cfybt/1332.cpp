#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m,a;
void solve()
{
	scanf("%d%d%d",&n,&m,&a);
	for(int i=0;i<a;i++)
	printf("%d %d\n",i%n+1,i%m+1);
}

int main()
{
	solve();
	return 0;
}

