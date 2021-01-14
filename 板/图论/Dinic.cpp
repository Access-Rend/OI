#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f;
int s,t,n,m,pe;
int head[N],dis[N],cur[N];
struct Edge{int to,v,nxt;}E[N<<1];
void add(int a,int b,int v){E[++pe]=(Edge){b,v,head[a]};head[a]=pe;}
bool bfs()
{
	memset(dis,0,sizeof(dis));queue<int>Q;Q.push(s);dis[s]=1;
	while(!Q.empty()) 
	{
		int u=Q.front();Q.pop();
		FOR(u,i)
			if(!dis[v] && E[i].v>0)
				dis[v]=dis[u]+1,Q.push(v);
	}
	return dis[t];
}
int dfs(int u,int cap)
{
	if(u==t || !cap)return cap;
	int res=0,f;

	for(int &i=cur[u],v=E[cur[u]].to;i;i=E[i].nxt,v=E[i].to)
	if(dis[u]+1==dis[v] && ( f = dfs(v,min(cap,E[i].v)) > 0 ) )
	{
		E[i].v-=f,E[i^1].v+=f;
		res+=f,cap-=f;
		if(!cap)break;
	}

	return res;
}
int dinic()
{
	int ans=0;
	while(bfs())
	{
		for(int i=1;i<=n+m+2;i++)cur[i]=head[i];
		ans+=dfs(s,inf);
	}
	return ans;
}
void init()
{
	pe=1;
	memset(head,0,sizeof(head));
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
