#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e3+10,inf=0x7fffffff>>1;
int n,m;
int head[N],pe=1,x[N],y[N];
struct Edge	{	int to,nxt;double v;	}E[(N*N)<<1];
struct Point
{
	int u;double d;
	friend bool operator < (const Point& t,const Point& o){	return t.d > o.d;	}
};
inline void add(int a,int b,double v){	E[++pe] = (Edge){b,head[a],v};	head[a] = pe;	}
inline int d_2(int a,int b){return (x[a] - x[b])*(x[a] - x[b]) + (y[a] - y[b])*(y[a] - y[b]);}
double dis[N];
priority_queue<Point>H;
void dij(int s,int t)
{
	_for(i,1,n)dis[i] = inf;	dis[s] = 0;
	H.push((Point){s,0});
	while(dis[t] == inf)
	{
		static int u;static double	d;
		u = H.top().u,	d = H.top().d;
		H.pop();
		dis[u] = d;
		FOR(u,i)
		if(dis[v]==inf)
		H.push((Point){v,d + E[i].v});
	}
}
void solve()
{
	scanf("%d",&n);
	_for(i,1,n)scanf("%d%d",&x[i],&y[i]);
	scanf("%d",&m);
	_for(i,1,m)
	{	
		static int a,b;
		scanf("%d%d",&a,&b);
		add(a,b,(double)sqrt(d_2(a,b)));
	}
	int s,t;	scanf("%d%d",&s,&t);	dij(s,t);
	printf("%.2lf",dis[t]);
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

