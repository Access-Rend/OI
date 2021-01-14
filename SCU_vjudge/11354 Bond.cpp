#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=5*1e4+10,M=1e5+10;

int n,m,q;
//Graph
int head[N],ph;
struct Edge{int to,v,nxt;}E[M<<1];
void add(int a,int b,int v)
{
	E[++ph]=(Edge){b,v,head[a]};head[a]=ph;
	E[++ph]=(Edge){a,v,head[b]};head[b]=ph;
}
//UnionFind
int f[N];
int find(int x){if(x!=f[x])x=find(f[x]);return x;}
//PointPair
int pp;
struct Pedge
{
	int a,b,v;
	bool operator < (const Pedge other)
	{return this->v < other.v;}
	
}P[M];
//
void newMST()
{
	int got=0;
	for(int i=1;i<=m && got!=n-1;i++)
	{
		int fa=find(P[i].a),fb=find(P[i].b);
		if(fa!=fb)
		{
			f[fa]=fb;
			add(P[i].a,P[i].b,P[i].v);
			got++;
		}
	}
}
//LCA
int t_in[N],t_out[N],timer,up[N][20],max_v[N][20];

void dfs(int u,int fa,int fav)
{
	t_in[u]=++timer;
	up[u][0]=fa,max_v[u][0]=fav;
	
	for(int i=1;i<20;i++)up[u][i]=up[up[u][i-1]][i-1];
	
	for(int i=1;i<20;i++)max_v[u][i] = max( max_v[u][i-1] , max_v[up[u][i-1]][i-1] );
	
	for(int p=head[u];p;p=E[p].nxt)
	if(E[p].to!=fa)	dfs(E[p].to,u,E[p].v);
	
	t_out[u]=++timer;
}

bool judgeac(int u,int v)
{	return t_in[u]<=t_in[v] && t_out[v]<=t_out[u] || !t_in[u];	}

int LCA(int u, int v)
{
	int res=0;
	if(judgeac(u, v))
	{
		for(int i=19;i>=0;--i)if(!judgeac(up[v][i], u))res=max(res,max_v[v][i]),v=up[v][i];
		res = max(res,max_v[v][0]);
		return res;
	}
	if(judgeac(v, u))
	{
		for(int i=19;i>=0;--i)if(!judgeac(up[u][i], v))res=max(res,max_v[u][i]),u=up[u][i];
		res = max(res,max_v[u][0]);
		return res;
	}
	for(int i=19;i>=0;--i)if(!judgeac(up[u][i], v))res=max(res,max_v[u][i]),u=up[u][i];
	res = max(res,max_v[u][0]);
	for(int i=19;i>=0;--i)if(!judgeac(up[v][i], u))res=max(res,max_v[v][i]),v=up[v][i];
	res = max(res,max_v[v][0]);
	
	return res;
}
//solve
void init()
{
	memset(head,0,sizeof(head));ph=0;
	for(int i=1;i<=n;i++)f[i]=i;
	pp=0;
	timer=0;
	memset(t_in,0,sizeof(t_in));
	memset(t_out,0,sizeof(t_out));
	memset(up,0,sizeof(up));
	memset(max_v,0,sizeof(max_v));
}
void solve()
{
	int t=0;
	while(~scanf("%d%d",&n,&m))
	{
		init();
		for(int i=1;i<=m;i++)
		{
			int a,b,v;scanf("%d%d%d",&a,&b,&v);
			P[++pp]=(Pedge){a,b,v};
		}
		sort(P+1,P+1+m);	
		newMST();
		dfs(1,0,0);
		scanf("%d",&q);
		while(q--)
		{
			int a,b;scanf("%d%d",&a,&b);
			printf("%d\n",LCA(a,b));
		}
	}
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
