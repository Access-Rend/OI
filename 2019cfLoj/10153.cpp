#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m,f[110][110];
int head[N],pe; 
struct Edge{int to,v,nxt;}E[110<<1];
inline void add(int a,int b,int c){E[++pe] = (Edge){b,c,head[a]};	head[a] = pe;}
int dfs(int u,int fa)
{
	int son = 0;
	FOR(u,i)
	if(v!=fa)
	{
		son += dfs(v,u);
		for_(j,min(m,son),1)
		for_(k,j-1,0)
		f[u][j] = max( f[u][j] ,f[u][j-k-1] + f[v][k] + E[i].v);
	}
	return ++son;
}
void solve()
{
	scanf("%d%d",&n,&m);
	_for(i,1,n)
	{
		static int a,b,c;scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);add(b,a,c);
	}
	dfs(1,0);
	printf("%d",f[1][m]);
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

