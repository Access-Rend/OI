#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=110,M=1010,inf=0x3f3f3f3f>>1,mod=31011;
int n,m;
struct PEdge
{
	int a,b,w;
	bool operator < (const PEdge&o){return w<o.w;}
}P[M];
int f[N];
int find(int x){return f[x]==x?x:find(f[x]);}

int L[N],R[N],need[N],G;// groups

int ans;
bool Mst()
{
	int got = 0,	id = 0;
	for(int i=1;i<=m && got!=n-1;i++)
	{
		if(P[i].w!=P[i-1].w) id++;
		static int fa,fb;
		fa = find(P[i].a),	fb = find(P[i].b);
		if(fa!=fb)	f[fa] = fb,	got++,	need[id]++;
	}
	return got==n-1;
}

int res;
void dfs(int id,int step,int got)//  id=×é±ð, step=±ß±àºÅ 
{
	if(step>R[id])
	{if(got==need[id])res++;return;}
	dfs(id,step+1,got);
	int fa = find(P[step].a),	fb = find(P[step].b);
	if(fa!=fb)
	{
		f[fa] = fb;
		dfs(id,step+1,got+1);
		f[fa] = fa;	f[fb] = fb;
	}
}

void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&P[i].a,&P[i].b,&P[i].w);
	sort(P+1,P+1+m);	for(int i=1;i<=n;i++)f[i] = i;
	for(int i=1;i<=m;i++)
	{
		if(P[i].w!=P[i-1].w) R[G] = i,	L[++G] = i;	
	}	R[G]=m;
	if(!Mst()){printf("0");return;}
	
	ans = 1;
	for(int i=1;i<=n;i++)f[i] = i;
	for(int i=1;i<=G;i++)
	{
		res = 0;	dfs(i,L[i],0);
		ans = ((ans%mod)*(res%mod)%mod);
		for(int j=L[i];j<=R[i];j++)
		{
			static int fa,fb;
			fa = find(P[j].a),	fb = find(P[j].b);
			if(fa!=fb)	f[fa] = fb;
		}
	}
	printf("%d",ans);
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

