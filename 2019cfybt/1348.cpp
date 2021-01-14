#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m,cnt;
int G[110][110];
int head[N],pe;
struct Edge
{
	int to,w,nxt;
}E[N>>1];
inline void add(int a,int b,int c){	E[++pe] = (Edge){b,c,head[a]};head[a] = pe;	}
struct pp
{
	int a,b,w;
	bool operator < (const pp oo)	{	return this->w < oo.w;	}
}P[N];
int f[N];
int find(int x){return x==f[x] ? x : f[x]=find(f[x]);}
void MST()
{
	int got = 0,	res=0;	_for(i,1,n)	f[i] = i;
	sort(P+1,P+1+n*n);
	for(int i=1;i<=n*n && got!=n-1;i++)
	{
		int f1 = find(P[i].a),	f2 = find(P[i].b);
		if(f1!=f2)
		{
			got++;
			f[f1] = f2;
			res += P[i].w;
		}
	}
	printf("%d",res);
}
void solve()
{
	scanf("%d",&n);
	_for(i,1,n)
	_for(j,1,n)
	{
		static int w;scanf("%d",&w);
		if(i==j)continue ;
		add(i,j,w);
		P[++cnt].a = i,	P[cnt].b = j,	P[cnt].w = w;
	}
	MST();
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
