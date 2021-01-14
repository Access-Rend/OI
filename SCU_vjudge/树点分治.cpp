#include<algorithm>
#include<cstdio>

using namespace std;
const int N=40000+10,inf=0x7fffffff-10;
int n,k,head[N],ph;
struct Edge
{
	int to,v,nxt;
}E[N<<1];
inline void add(int a,int b,int v)
{
	E[++ph]=(Edge){b,v,head[a]};head[a]=ph;
	E[++ph]=(Edge){a,v,head[b]};head[b]=ph;
}

int vis[N],size[N],dis[N],root,ans,minmaxs;
void dfs_sz(int u,int fa)
{
	bool flg=0;size[u]=1;
	for(int i=head[u];i;i=E[i].nxt)
	if(!vis[E[i].to] && E[i].to!=fa)
	{
		int v=E[i].to;
		dfs_sz(v,u);
		size[u]+=size[v];
	}
}
void dfs_rt(int u,int fa,int sz)
{
	int maxs=sz-size[u];
	for(int i=head[u];i;i=E[i].nxt)
	if(!vis[E[i].to] && E[i].to != fa)
	{
		int v=E[i].to;
		dfs_rt(v,u,sz);
		maxs=max(maxs,size[v]);
	}	
	if(maxs<minmaxs)minmaxs=maxs,root=u;
}
void dfs_ds(int u,int d,int fa)
{
	dis[++dis[0]]=d;//绝了！艹他居然放顶上！意思就是把最简边也算上 
	for(int i=head[u];i;i=E[i].nxt)
	if(!vis[E[i].to] && E[i].to!=fa)
	{
		int v=E[i].to;
		dfs_ds(v,d+E[i].v,u);
	}
}

int dvd(int u,int d)
{
	dis[0]=0;int res=0;
	dfs_ds(u,d,0);
	int l=1,r=dis[0];
	sort(dis+l,dis+l+r);
	while(l<r)
	{
		while (l<r && dis[l]+dis[r]>k)r--;
		res+=r-l;//妙啊，枚举l，每次与l配对[l+1.r]条边 
		l++;
	}
	return res;
}
void dfs(int u)
{
	minmaxs=inf;
	dfs_sz(u,0);dfs_rt(u,0,size[u]);ans+=dvd(root,0);
	vis[u]=1;
	for(int i=head[root];i;i=E[i].nxt)
	if(!vis[E[i].to])
	{
		int v=E[i].to;
		ans-=dvd(v,E[i].v);
		dfs(v);
	}
	return ;
}
void solve()
{
	while(1)
	{
		scanf("%d%d",&n,&k);if(n==0)return ;
		for(int i=1;i<n;i++)
		{int a,b,v;scanf("%d%d%d",&a,&b,&v);add(a,b,v);}
		dfs(1);
		printf("%d\n",ans);
		ph=0;dis[0]=0;ans=0;
		for(int i=1;i<=N;i++)head[i]=vis[i]=size[i]=0;
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

