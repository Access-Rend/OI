#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(register int i=a;i<=b;i++)
#define for_(i,a,b) for(register int i=a;i>=b;i--)
#define FOR(u,i) for(register int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,M=1e5+10,inf=0x3f3f3f3f;
int n,m,s,t;
int head[N],pe=1;
struct Edge{	int to,w,nxt;	}E[M*5];
inline void add(int a,int b,int c){	E[++pe] = (Edge){b,c,head[a]};	head[a] = pe;	}

LL dis[N];	bool vis[N];
queue<int>Q;
bool spfa(int s)
{
	_for(i,1,n)	dis[i] = inf;//initial
	dis[s] = 0,	vis[s] = 1,	Q.push(s);//start from s
	while(!Q.empty())
	{
		int u = Q.front();	Q.pop();	vis[u] = 0;
		FOR(u,i)
		if(dis[u] + E[i].w < dis[v])
		{
			dis[v] = dis[u] + E[i].w;
			if(!vis[v])	Q.push(v),	vis[v] = 1;
		}
	}
	return 0;
}
inline void ini()
{
	memset(head,0,sizeof(head));
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	while(!Q.empty())Q.pop();
}
void solve()
{
		ini();
		scanf("%d%d%d%d",&n,&m,&s,&t);
		_for(i,1,m)
		{
			static int a,b,c;scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);	if(c>0)add(b,a,c);
		}
		spfa(s);
		printf("%lld",dis[t]);
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

