#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int MAXN=1e5+10,inf=0x3f3f3f3f>>1;
int n,m,pp;
struct Pair
{
	int a,b,w;
	friend bool operator < (const Pair&a,const Pair&b){return a.w < b.w;}
}P[2510];
int x[2510],y[2510];
inline int d(int i,int j){return abs(x[i]-x[j])+abs(y[i]-y[j]) + (abs(x[i]-x[j])+abs(y[i]-y[j])&1);}
int f[100];
int find(int x){return x==f[x] ? x : f[x]=find(f[x]);}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
	P[++pp]=(Pair){i,j,d(i,j)};
	sort(P+1,P+1+pp);
	
	for(int i=1;i<=n;i++)f[i]=i;
	int got = 0,	edge;
	for(int i=1;i<=pp && got!=n-1;i++)
	{
		int f1 = find(P[i].a),	f2 = find(P[i].b);
		if(f1!=f2)
		{
			f[f1]=f2;
			got++;
		}
		edge = P[i].w;
	}
	printf("%d",edge>>1);
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

