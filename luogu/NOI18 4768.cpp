#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mid ((l+r)>>1)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f;
int n,m,lastans;
int head[N],ce;
struct Edge{int to,v,p,nxt;}E[N<<1];
struct Hedge
{
	int a,v;
	bool operator < (const Hedge&o)const{return v>o.v;}
};
struct Pedge
{
	int a,b,v;
	bool operator < (const Pedge&o)const{return v>o.v;}
}PE[N];
void Add(int a,int b,int p,int v){E[++ce] = (Edge){b,v,p,head[a]};head[a] = ce;}
int dis[N],mn[N<<5];
priority_queue<Hedge>H;
void dij() 
{
	for(int i=1;i<=n;i++)	dis[i] = inf;
	dis[1] = 0;	H.push((Hedge){1,0}); 
	while(!H.empty())
	{
		int u = H.top().a;	H.pop();
		FOR(u,j)
		if(dis[v] > dis[u] + E[j].v)
		{
			dis[v] = dis[u] + E[j].v;
			H.push((Hedge){v,dis[v]});
		}
	}
}

int T[N],L[N<<5],R[N<<5],dep[N>>5],fa[N>>5],cc;
void build(int &i,int l,int r)
{
	i = ++cc;
	if(l<r)	build(L[i],l,mid),	build(R[i],mid+1,r);
	else	fa[i] = l,	mn[i] = dis[l];//
}
void update(int pre,int &i,int l,int r,int x,int f)
{
	i = ++cc;
	if(l==r){fa[i] = f;	dep[i] = dep[pre];	mn[i] = mn[pre];	return;}
	L[i] = L[pre];	R[i] = R[pre];
	if(x<=mid)	update(L[pre],L[i],l,mid,x,f);
	else	update(R[pre],R[i],mid+1,r,x,f);
}
int query(int i,int l,int r,int x)
{
	if(l==r)	return i;
	if(x<=mid)	return query(L[i],l,mid,x);
	else	return query(R[i],mid+1,r,x);
}
void add(int i,int l,int r,int x)
{
	if(l==r){dep[i]++;return ;}
	if(x<=mid)	add(L[i],l,mid,x);
	else	add(R[i],mid+1,r,x);
}
int find(int i,int x)
{
	int f = query(i,1,n,x);
	if(x==fa[f])	return f;
	return find(i,fa[f]);
}
void init()
{
	memset(T,0,sizeof(T));
	lastans = ce = 0;
}
void merge(int i,int x,int y)
{
	if(x==y)return;
	if(dep[x]>dep[y]) swap(x,y);
	update(T[i-1],T[i],1,n,fa[x],fa[y]);
	int a = query(T[i],1,n,fa[x]),	b = query(T[i],1,n,fa[y]);
	mn[b] = min(mn[b],mn[a]);
	if(dep[x]==dep[y])	add(T[i],1,n,fa[y]);
}
void solve()
{
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,l,a;
		scanf("%d%d%d%d",&u,&v,&l,&a);
		Add(u,v,a,l);	Add(v,u,a,l);
		PE[i] = (Pedge){u,v,a};
	}
	dij();
	sort(PE+1,PE+1+m);
	build(T[0],1,n);
	for(int i=1;i<=m;i++)
	{
		T[i] = T[i-1];
		int x = PE[i].a,	y = PE[i].b;
		x = find(T[i],x);	y = find(T[i],y);
		if(fa[x]!=fa[y])merge(i,x,y);
	}
	int q,k,s;
	scanf("%d%d%d",&q,&k,&s);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x = (x+k*lastans-1)%n+1;
		y = (y+k*lastans)%(s+1);
		int t = lower_bound(PE+1,PE+1+m,(Pedge){0,0,y}) - PE;
		int ans = find(T[t],x);
		printf("%d\n",lastans = mn[ans]);
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

