#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mem(a,b) memset(a,b,sizeof(a))
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x7fffffff>>1;
int n, m, s = 1;
int head[N],pe=1,in[N];
struct Edge{	int to,nxt,k;	}E[N<<1];
inline void add(int a,int b)	{	E[++pe] = (Edge){b,head[a],0};head[a]=pe;	}

queue<int>Q;
void dfs(int u)
{
	FOR(u,i)
	if(!E[i].k)
	{
		E[i].k = 1,	E[i^1].k = 1;
		dfs(v);
	}
	Q.push(u);
}
void solve()
{
	scanf("%d%d",&n,&m);
	_for(i,1,n)
	{
		int a,b;scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
		in[a]++,in[b]++;
	}
	_for(i,1,n)s = in[i]&1 ? in[i] : s;
	dfs(s);
	while(!Q.empty())
	{
		printf("%d ",Q.front());Q.pop();
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

