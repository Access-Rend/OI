#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mid ((l+r)>>1)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f;
int n,m,head[N],ans[N],ce;
struct Edge{int to,nxt;}E[N<<1];
inline void add(int a,int b){E[++ce]=(Edge){b,head[a]};head[a]=ce;}
int in[N],out[N],up[N][17],ct;
void dfs(int u)
{
	in[u] = ++ct;
	for(int i=1;i<=16;i++)up[u][i]=up[up[u][i-1]][i-1];
	FOR(u,i)if(up[u][0]!=v)up[v][0]=u,dfs(v);//dfs老老实实判父亲，别判断什么值为空 
	out[u] = ++ct;
}
inline bool isAC(int u,int v)
{return ((in[u]<=in[v]&&out[v]<=out[u])||u==0);}
inline int LCA(int u,int v)
{
	if(isAC(u,v))return u;if(isAC(v,u))return v;
	for(int i=16;i>=0;i--)if(!isAC(up[u][i],v))u=up[u][i];
	return up[u][0];
}
int rt[N],L[N<<6],R[N<<6],mx[N<<6],id[N<<6],cs;
void update(int i)
{
	if(L[i]&&R[i])mx[i]=max(mx[L[i]],mx[R[i]]),id[i]=mx[L[i]]>=mx[R[i]]?id[L[i]]:id[R[i]];
	else if(L[i])mx[i]=mx[L[i]],id[i]=id[L[i]];
	else if(R[i])mx[i]=mx[R[i]],id[i]=id[R[i]];
}
void st_add(int &i,int l,int r,int k,int val)
{
	if(!i)i=++cs;
	if(l==r){id[i]=l,mx[i]+=val;return;}
	if(k<=mid)st_add(L[i],l,mid,k,val);
	else st_add(R[i],mid+1,r,k,val);
	update(i);
}
int merge(int i,int j,int l,int r)
{
	if(!j||!i)return i|j;
	if(l==r)mx[i]+=mx[j];
	else
	{
		L[i]=merge(L[i],L[j],l,mid);
		R[i]=merge(R[i],R[j],mid+1,r);
		update(i);//放里边外边有什么区别呢 
	}
	return i;
}
void cal(int u)
{
	FOR(u,i)
	if(v!=up[u][0])
		cal(v),rt[u]=merge(rt[u],rt[v],1,1e5);
	if(mx[rt[u]]>0)ans[u]=id[rt[u]];
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		static int a,b;scanf("%d%d",&a,&b);add(a,b);add(b,a);
	}
	dfs(1);
	while(m--)
	{
		static int a,b,c,lca;
		scanf("%d%d%d",&a,&b,&c);
		lca=LCA(a,b);
		if(a==b)
		{
			st_add(rt[a],1,1e5,c,1);if(up[a][0])st_add(rt[up[a][0]],1,1e5,c,-1);
		}
		else
		{
			st_add(rt[a],1,1e5,c,1);
			st_add(rt[b],1,1e5,c,1);
			st_add(rt[lca],1,1e5,c,-1);
			if(up[lca][0])st_add(rt[up[lca][0]],1,1e5,c,-1);
		}
	}
	cal(1);
//	for(int i=1;i<=n;i++)if(mx[rt[i]]>0)printf("%d\n",id[rt[i]]);else printf("0\n");
for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
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

