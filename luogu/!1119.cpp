#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
int f[210][210],t[210];
void In()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=m;i++)
	{
		int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		f[a][b]=f[b][a]=v;
	}
}
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

