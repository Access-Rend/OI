#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define _for(a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=510,M=2710,inf=0x7fffffff-10;
int head[N],ph,pp;
struct Pnode
{
	int a,v;
	bool operator < (Pnode other){return v<other.v;}
}P[M];
struct Edge
{
	int to,v,nxt;
}E[M<<1];
void add(int a,int b,int v)
{
	E[++ph]=(Edge){b,v,head[a]};head[a]=ph;
}
void In()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,v;scanf("%d%d%d",&a,&b,&v);
		add(a,b,-v);
	}
}
int dis[N];
priority_queue<Pnode>H;
void dij()
{
	int t;
	while(!H.empty())H.pop;
	_for(1,n)dis[i]=inf;
	H.push((Pnode){t,0});
	while(!H.empty())
	{
		int u=H.top().a=H.top().v;H.pop(),p=0;
		for(int i=head[u];i;i=E[i].nxt)
		if(dis[i]!=inf)
		{
			if(E[p].v+dis[v]>=E[i].v+dis[u])
			p=i;
		}
		dis[E[p].to]=dis[u]+E[p].v;
		H.push((Pnode){E[p].to,dis[E[p].to]});
	}
	//judge();
}
void solve()
{
	
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

