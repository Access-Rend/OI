#include<iostream>
#include<iomanip>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int n,m;
int g[505][505],cnt=0,a[505];
int x;
char c;
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		g[i][j]=0x7fffffff/2;
	}
	while(c!='\n') c=getchar();
	c=getchar();
	for(int i=1;i<=m;i++)
	{
		cnt=0;
		while(1)
		{
			bool flag=0;
			int res=0,bj=1;
			while(c<'0'||c>'9'){if(c=='-') bj=-1;if(c=='\n'){c=getchar();flag=1;break;}c=getchar();};
			if(flag) break;
			while(c>='0'&&c<='9'){res=res*10+c-'0'; c=getchar();};
			a[++cnt]=res*bj;
		}
		for(int j=1;j<cnt;j++)
		for(int k=j+1;k<=cnt;k++)
		{
			if(j!=k)
			{
				g[a[j]][a[k]]=1;
			}
		}
	}
/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) printf("%d ",g[i][j]);
		printf("\n");
	}*/
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i!=j&&i!=k&&j!=k&&g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];
	}
	if(g[1][n]==0x7fffffff/2) printf("NO");
	else printf("%d",g[1][n]-1);
	return 0;
}
