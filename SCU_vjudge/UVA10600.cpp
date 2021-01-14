#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e2+10,M=1e2+10,inf=0x7fffffff;
int n,m,ans,ans2;

int head[N],ph;
struct Edge
{
	int to,nxt,v,k;
}E[M<<1];
void add(int a,int b,int v)
{
	E[++ph]=(Edge){b,head[a],v,0};head[a]=ph;
	E[++ph]=(Edge){a,head[b],v,0};head[b]=ph;
}

int pp;
struct Pedge
{
	int a,b,v;
	bool operator < (const Pedge other){	return this->v < other.v;	}
}P[M];

int f[N];
int find(int x)
{	return x==f[x] ? x : f[x]=find(f[x]);}

bool vis[N];
int stc[N];
bool dfs(int u)
{
	vis[u]=1;
	bool res;
	for(int i=head[u];i;i=E[i].nxt)
	if(!E[i].k)
	{
		stc[++stc[0]]=i;
		if(vis[E[i].to])
			return 1;
		else
			res=dfs(E[i].to);	
	}
	
	if(!res)vis[u]=0,--stc[0];
	return res;
}

int circle(int u,int p)
{
	memset(vis,0,sizeof(vis));
	memset(stc,0,sizeof(stc));
	
	dfs(u);
	
	int v=0;
	for(int i=1;i<=stc[0];i++)
	if(stc[i]!=p)v=max(E[i].v,v);
	
	E[p].k=1;
	return ans-E[p].v+v;
}

void mst()
{
	sort(P+1,P+1+m);
	int got=0;
	for(int i=1;i<=m && got!=n-1;i++)
	{
		int fa=find(P[i].a),fb=find(P[i].b);
		if(fa!=fb)
		{
			f[P[i].a]=fb;
			add(P[i].a,P[i].b,P[i].v);
			ans+=P[i].v,got++;
			P[i]=(Pedge){0,0,0};
		}
	}
	printf("%d ",ans);
}
void mst2()
{
	for(int i=1;i<=m;i++)
	if(P[i].v)
		ans2=max(ans2,circle(P[i].a,ph));
	printf("%d\n",ans2);
}
void Ini()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,v;scanf("%d%d%d",&a,&b,&v);
		P[++pp]=(Pedge){a,b,v};
	}
}
void solve()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		Ini();
		mst();
		mst2();
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

