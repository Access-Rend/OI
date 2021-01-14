#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e4+10,inf=0x3f3f3f3f>>1;
int n,m;
LL ans;
int head[N],pe;
struct Edge
{
	int to,v,nxt;
}E[N<<2];
inline void add(int a,int b,int v){E[++pe] = (Edge){b,v,head[a]};head[a]=pe;}
int pp;
struct Pe
{
	int a,b,v;
	bool operator < (const Pe&o){return o.v > v;};
}PE[N<<2];
int f[N];
int find(int x){return f[x]==x ? x : x = find(f[x]);}

int cnt[N],_cnt;
bool vis[N][2];
void dfs(int u,int k)
{
	vis[u][k] = 1;
	if(k)	cnt[u] = _cnt;
	else	_cnt++;
	FOR(u,i)
	{
		if(!k && !vis[u][0])	PE[++pp] = (Pe){u,v,E[i].v};
		if(!vis[v][k] && v<=n)	dfs(v,k);
	}
	FOR(u+n,i)
	if(v>n)PE[++pp] = (Pe){u,v,E[i].v};
}
int mark[N];
bool judge(int a,int b)
{
	if(a>n && mark[a]==1)return 0;
	if(b>n && mark[b]==1)return 0;
	if(a<=n && mark[a]==2)return 0;
	if(b<=n && mark[b]==2)return 0;
	mark[a] = a>n ? 2 : 1;
	mark[b] = b>n ? 2 : 1;
	return 1;
}
void mst()
{
	for(int i=1;i<=n;i++)
	if(!vis[i][0])
	{
		pp=0;memset(PE,0,sizeof(PE));
		_cnt=0;dfs(i,0);dfs(i,1);
		
		for(int j=1;j<=pp;j++)printf("%d ",PE[j].v);printf("\n");
		sort(PE+1,PE+1+pp);
		for(int j=1;j<=pp;j++)printf("%d ",PE[j].v);
		
		static int got;	got = 0;
		for(int j=1;j<=pp && got<cnt[i-1];j++)
		{
			static int f1,f2;
			f1 = PE[j].a;	f2 = PE[j].b;
			if(!judge(f1,f2))continue;
			f1 = find(f1);	f2 = find(f2);
			
			if(f1!=f2)
			{
				f[f1] = f2;
				ans += PE[j].v;
				got++;
			}
		}
	}
}

void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		static int u,v,a,b,c;
		scanf("%d%d%d%d%d",&u,&v,&a,&b,&c);
		
		add(u,v,a);add(v,u,a);
		
		add(u+n,v+n,c);add(v+n,u+n,c);
		
		add(u+n,v,b);add(v,u+n,b);
		add(u,v+n,b);add(v+n,u,b);
	}
	mst();
	printf("%lld",ans);
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

