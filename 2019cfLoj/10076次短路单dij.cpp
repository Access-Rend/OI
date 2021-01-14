#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int MAXN=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
int head[MAXN],pe;
struct Edge{int to,v,nxt;}E[MAXN<<1];
inline void add(int a,int b,int v){E[++pe]=(Edge){b,v,head[a]};head[a]=pe;}
LL dis[MAXN],dis2[MAXN];
bool vis[MAXN];
void spfa(int s)
{
	for(int i=1;i<=n;i++)dis[i]=dis2[i]=inf;
	queue<int>Q;Q.push(s);
	dis[s] = dis2[s] = 0;	vis[s] = 1;
	while(!Q.empty())
	{
		static int u;
		u = Q.front();Q.pop();
		FOR(u,i)
		{
			static LL newway,newway2;
			newway = dis[u] + E[i].v;;
			newway2 = dis2[u] + E[i].v;;
			if(newway < dis[v])
			{
				dis2[v] = dis[v];
				dis[v] = newway;
				if(!vis[v])vis[v]=1,Q.push(v);
			}
			if(newway < dis2[v] && newway > dis[v])
			{
				dis2[v] = newway;
				if(!vis[v])vis[v]=1,Q.push(v);
			}
			if(newway2 < dis2[v])
			{
				dis2[v] = newway2;
				if(!vis[v])vis[v]=1,Q.push(v);
			}
		}
		vis[u] = 0; 
	}
}
void solve()
{
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)dis[i]=dis2[i]=1e15;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    spfa(1);
    printf("%lld",dis2[n]) ;
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

