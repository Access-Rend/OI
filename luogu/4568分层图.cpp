#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int MAXN=1e5+10,inf=0x3f3f3f3f>>1;
int n,m,s,t,k;
int d[MAXN][20],head[MAXN],pe;
struct Edge{int to,v,nxt;}E[MAXN<<3];
inline void add(int a,int b,int v)
{E[++pe]=(Edge){b,v,head[a]};head[a]=pe;}

queue<int>Q,q;
bool vis[MAXN][20];
int dis[MAXN][20];
void spfa(int s)
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=k;j++)dis[i][j]=inf;
	dis[s][0] = 0;	Q.push(s);	q.push(0);
	while(!Q.empty())
	{
		int u = Q.front(),	y = q.front();
		Q.pop();q.pop();
		FOR(u,i)
		{
			if(dis[v][y] > dis[u][y] + E[i].v)
			{
				dis[v][y] = dis[u][y] + E[i].v;
				if(!vis[v][y])	vis[v][y] = 1,Q.push(v),q.push(y);
			}
			if(dis[v][y+1] > dis[u][y] + E[i].v && y<k)
			{
				dis[v][y+1] = dis[u][y] + E[i].v;
				if(!vis[v][y+1])	vis[v][y+1] = 1,Q.push(v),q.push(y+1);
			}
		}
		vis[u][y] = 0;
	}
}
void solve()
{
	scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
	for(int i=1;i<=m;i++)
	{
		static int a,b,c;scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);add(b,a,c);
	}
	spfa(s);
	printf("%d",dis[t][k]);
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

