#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int n;

int head[10010],ph;
struct Edge
{
	int next,to;
}E[1000010];
int ans[10010],v[10010];
void add(int a,int b)
{
	E[++ph]=(Edge){head[a],b};head[a]=ph;
}
void In()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;scanf("%d%d%d",&x,&v[i],&y);
		while(y)
		{
			add(x,y);scanf("%d",&y);
		}
	}
}
void solve()
{
	for(int i=1;i<=n;i++)
	{
		ans[i]=v[i];
		for(int p=head[i];p;p=E[p].next)
		ans[i]=max(ans[E[p].to]+v[i],ans[i]);
		ans[0]=max(ans[0],ans[i]);
	}
	printf("%d",ans[0]);
}
int main()
{
	freopen("in.txt","r",stdin);
	In();
	solve();
	fclose(stdin);
	return 0;
}
