#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=5*1e4+10,M=1e5+10;

int n,m,q,ans;
//Graph
int head[N],ph;
struct Edge
{
	int to,v,nxt,k;
}E[M<<1];
void add(int a,int b,int v)
{
	E[++ph]=(Edge){b,v,head[a],0};head[a]=ph;
	E[++ph]=(Edge){a,v,head[b],0};head[b]=ph;
}
//UnionFind
int f[N];
int find(int x)
{	if(x!=f[x])x=find(f[x]);return x;	}
//PointPair
int pp;
struct Pedge
{
	int a,b,v;
	
	bool operator < (const Pedge other)
	{return this->v < other.v;}
	
}P[M];
//
int newMST()
{
	int got=0,res=0;
	for(int i=1;i<=m&&got!=n-1;i++)
	{
		int fa=find(P[i].a),fb=find(P[i].b);
		if(fa!=fb)
		{
			f[fa]=fb;
			add(P[i].a,P[i].b,P[i].v);
			res+=p[i.v],got++;
		}
	}
	return res;
}
bool vis[N];
int dfs(int u,int fa,int p,int maxv)
{
	for(int i=head[u];i;i=E[i].nxt)
	{
		int v=E[i].to;
		if(vis[v] || E[i].k)continue;
		maxv = R[i].v>maxv?E[i].v:maxv;
		p = R[i].v>maxv?i:p;
		if(v==fa)
		return p;
		else
		return dfs(v,u,p,v);
	}
	return 0;
}
void findc()
{
	memset(vis,0,sizeof(vis));
	int p=dfs(1);
	E[p].k=1,E[p^1].k=1;
	ans-=E[p].v;
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

