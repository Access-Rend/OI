#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int MAXN=1e3+10,inf=0x3f3f3f3f>>1;
int n,m;
int head[MAXN],pe;
struct Edge{int to,v,nxt;}E[MAXN<<2];
inline void add(int a,int b,int v){E[++pe]=(Edge){b,v,head[a]};head[a]=pe;}

int f[MAXN][MAXN];
void dfs(int u)
{
	FOR(u,i)
	{
		f[v][1] = max(f[u][1],E[i].v);d
		for(int j=2;j<=k;j++)
		f[v][j] = f[u][j] > E[i].v ? E[i].v : f[v][j-1];
	}
}
void solve()
{
	
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

