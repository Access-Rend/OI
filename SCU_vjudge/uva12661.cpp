#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;

const int N=310,M=5*1e4+10,inf=0x7fffffff-10;
int n,m,s,t;

int head[N],ph,pp;
struct Edge
{
	int to,v,in,out,nxt;
}E[M<<1];
struct Point
{
	int a,v;
	bool operator < (const Point other){return this->v < other.v;}
}P[M];
inline void add(int a,int b,int in,int out,int v)
{
	E[++ph]=(Edge){b,v,in,out,head[a]};head[a]=ph;
	E[++ph]=(Edge){a,v,in,out,head[b]};head[b]=ph;
}
priority_queue<Point>H;
int dis[N];
void dij()
{
	for(int i=1;i<=n;i++)dis[i]=inf;
	H.push((Point){s,0});
	while(dis[t]==inf)
	{
		Point u=H.top();dis[u.a]=u.v;
		for(int i=head[u.a];i;i=E[i].nxt)
		{
			int v=E[i].to;
			if(dis[v]!=inf)H.push((Point){v,E[i].v+u.v});
		}
	}
}
void solve()
{
	
}

void ini()
{
	ph=0;memset(head,0,sizeof(head));
}
void In()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,a,b,t;scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
		add(u,v,a,b,t);
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

