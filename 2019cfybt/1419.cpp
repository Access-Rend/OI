#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=2e4+10,M=4e4+10,inf=0x7fffffff>>1;
int n,m;
int head[N],pe;
struct Edge{	int to,v,nxt;	}E[M];
inline void add(int a,int b,int v){	E[++pe] = (Edge){b,v,head[a]};	head[a] = pe;	}

long long dis[N];bool vis[N];
int cnt[N];
queue<int>Q;
void spfa(int s,int t)
{
	_for(i,1,n)	dis[i] = inf;//initial
	dis[s] = 0,	vis[s] = 1,	Q.push(s);//start
	while(!Q.empty())
	{
		int u = Q.front();	Q.pop();	vis[u] = 0;	if(++cnt[u] > n)return ;
		FOR(u,i)
		if(dis[u] + E[i].v < dis[v])
		{
			dis[v] = dis[u] + E[i].v;
			if(!vis[v])	Q.push(v),	vis[v] = 1;
		}
	}
}

void solve()
{
	scanf("%d%d",&n,&m);
	int mind = inf;
	_for(i,1,m)	{	int a,b,v;scanf("%d%d%d",&a,&b,&v);add(a,b,v);mind = min(mind,v);	}
	if(n == 1){cout << mind;return ;}
	spfa(1,n);
	printf("%lld",dis[n]);
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
