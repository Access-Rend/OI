#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int MAXN=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
int head[MAXN],fa[MAXN],pe,pa;
int G[110][110];
struct Edge{int to,v,nxt;}E[MAXN];
struct ANS
{
	int x,y,v;
	friend bool operator < (const ANS&a,const ANS&b)
	{	return a.v < b.v;	}
}ans[MAXN];
inline void add(int a,int b,int v){E[++pe] = (Edge){b,v,head[a]};head[a]=pe;}

bool vis[MAXN];

inline void cal(int x,int y,int v)
{
	if(fa[x]==fa[y])ans[++pa] = (ANS){x,y,v};
}

void dfs(int u,int f)
{
	fa[u] = f;	vis[u] = 1;
	FOR(u,i)
	{
		if(vis[v])cal(u,v,E[i].v); 
		else dfs(v,u);
	}
}

void solve()
{
	scanf("%d%d",&n,&m);
	memset(G,inf,sizeof(G));
	for(int i=1;i<=m;i++)
	{
		static int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		G[a][b] = G[b][a] = min(G[b][a],v);
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(G[i][j]!=inf)add(i,j,G[i][j]),add(j,i,G[i][j]);
	dfs(1,0);
	if(!pa){printf("No solution.");return ;}
	sort(ans+1,ans+1+pa);
	int cnt=0;for(int i=1;ans[i].v==ans[1].v;i++,cnt++);
	printf("%d %d %d %d",cnt,ans[1].x,ans[1].y,fa[ans[1].x]);
	
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

