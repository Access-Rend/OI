#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int maxn=10000+10;
const int maxm=400000+10;
struct edge{int to,cap,flow,last;}line[maxm];
int n,m,s,t,pos=1,head[maxn],vis[maxn],dis[maxn],cur[maxn],que[maxn];
int G[1010][60];
void add(int from,int to,int cap)
{
	line[++pos]=(edge){to,cap,0,head[from]}; head[from]=pos;
	line[++pos]=(edge){from,0,0,head[to]}; head[to]=pos;
}
bool BFS()
{
	for(int i=1;i<=n;++i)vis[i]=0;
	int lead=0,tail=1; que[tail]=s; vis[s]=1;
	while(lead<tail)
	{
		int u=que[++lead];
		for(int i=head[u];i;i=line[i].last)
		{
			edge e=line[i];
			if(!vis[e.to] && e.cap>e.flow)
			{
				vis[e.to]=1;
				que[++tail]=e.to;
				dis[e.to]=dis[u]+1;
			}
		}
	}
	return vis[t];
}
int DFS(int u,int a)
{
	if(u==t || a==0)return a;
	int flow=0,f;
	for(int &i=cur[u];i;i=line[i].last)
	{
		edge &e=line[i];
		if(dis[e.to]==dis[u]+1 && (f=DFS(e.to,min(a,e.cap-e.flow)))>0)
		{
			e.flow+=f; line[i^1].flow-=f;
			flow+=f; a-=f; if(a==0)break;
		}
	}
	return flow;
}
inline int id(int i,int j){return i*m+j;}
inline void init()
{
	s = id(n,m) + 1;	t = id(n,m) + 2;
	pos = 0;
	memset(head,0,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	memset(cur,0,sizeof(cur));
	memset(que,0,sizeof(que));
}
void solve()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		init();
		int a,b,c;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		scanf("%d",&G[i][j]);
		
		for(int j=1;j<=m;j++)
		add(s,id(1,j),G[1][j]);//s
		
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		add(id(i,j),id(i,j+1),G[i][j]),//left
		add(id(i,j+1),id(i,j),G[i][j+1]),//right
		add(id(i,j),id(i-1,j),G[i][j]),//up
		add(id(i,j),t,0);//t
		
		int flow=0;
		while(BFS())
		{
			for(int i=1;i<=n;++i)cur[i]=head[i];
			flow+=DFS(s,inf);
		}
		printf("%d\n",flow);
	}
}
int main()
{
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
	init();
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
