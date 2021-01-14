#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
const int N=4*1e4+10;
using namespace std;
int T,n,m,f[N][20],dis[N][20],in[N],out[N],timer;
int head[N],ph;
struct Edge
{
	int nxt,to,v;
}E[N<<1];
//ancestor and u
bool acst(int a,int u){return in[a] < in[u] & out[u]<out[a];}
void dfs(int u,int fa,int d)
{
	in[u]=++timer;
	f[u][0]=fa,dis[u][0]=d;
	
	for(int i=1;i<=16;i++)
	f[u][i] = f[f[u][i-1]][i-1];
	
	for(int i=head[u];i;i=E[i].nxt)
	if(E[i].to!=fa)dfs(E[i].to,u,E[i].v);
	
	out[u]=++timer;
}
int LCA(int u,int v)
{
	if(acst(u,v))return u;
	if(acst(v,u))return v;
	for(int i=16;i>0;i--)if(!acst(u,v))return f[f[u][i]][0];
}

void solve()
{
	memset(f,0,sizeof(f));
	memset(dis,0,sizeof(dis));
	memset(head,0,sizeof(head));
	ph=0;timer=0;
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		E[++ph]=Edge{head[a],b,c};head[a]=ph;
	}
	dfs(1,0,0);
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",LCA(a,b));
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	while(T--)
	solve();
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

