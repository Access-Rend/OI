#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
const int N=10010,M=100010;
using namespace std;
int n,m;
int head[N],ph;
struct Edge
{
	int to,next;
}E[M<<1];
void add(int a,int b)
{
	E[++ph]=(Edge){b,head[a]};head[a]=ph;
}
void In()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;scanf("%d%d",&a,&b);add(a,b);add(b,a);
	}
}

int vis[N],mrk[N],got,pt;
bool judge(int u)
{
	for(int i=head[u];i;i=E[i].next)
	{
		int v=E[i].to;
		if(mrk[v]==mrk[u])return 0;
	}
	return 1;
}
bool possible;
void dfs(int u)
{
	if(!possible)return ;
	pt++,got+=mrk[u],vis[u]=1;
	for(int i=head[u];i;i=E[i].next)
	{
		int v=E[i].to;
		if(!vis[v])
		{
			mrk[v]=!mrk[u];
			if(judge(v))dfs(v);
			else possible=0;
		}
	}
}

void solve()
{
	int ans=0;
	memset(mrk,-1,sizeof(mrk));
	for(int i=1;i<=n;i++)
	{
		pt=got=0;
		possible=1;mrk[i]=0;dfs(i);
		ans+=min(pt-got,got);
		if(!possible){printf("Impossible");return ;}
	}
	printf("%d",ans);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	In();
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

