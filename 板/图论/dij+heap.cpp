#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f;
int n,m;
int head[N],pe;
struct Edge	{	int to,w,nxt;	}E[N<<1];
inline void add(int a,int b,int c)	{	E[++pe] = (Edge){b,c,head[a]};head[a] = pe;}
struct hn
{
	int d,u;
	friend bool operator < (const hn& a,const hn& b)	{	return a.d > b.d;	}
};
int dis[N];
void dij(int s)
{
	priority_queue<hn> H;	H.push((hn){0,s});
	_for(i,1,n)	dis[i] = inf;	dis[s] = 0;
	while(!H.empty())
	{
		int u = H.top().u,	d = H.top().d;	H.pop(); 
//		if(dis[u]!=inf)	continue ;
		FOR(u,i)
		if(dis[v] > dis[u] + E[i].w)
		{
			dis[v] = dis[u] + E[i].w;
			H.push((hn){dis[v],v}); 
		}
	}
}

void solve()
{
	scanf("%d%d",&n,&m);
	_for(i,1,m)
	{
		static int a,b,c;scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);	add(b,a,c);
	}
	dij(1);
	printf("%d",dis[n] == inf ? -1 : dis[n]);
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

