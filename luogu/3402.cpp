#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
#define mid ((l+r)>>1) 
inline int read()
{
    int x=0;char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
const int N=1e5*20,inf=0x3f3f3f3f;
int n,m,cc;
int T[N],L[N],R[N],fa[N],dep[N];
void build(int&i,int l,int r)
{
	i = ++cc;
	if(l<r)	build(L[i],l,mid),	build(R[i],mid+1,r);
	else	fa[i] = l;
}
void update(int l,int r,int pre,int &i,int x,int f)
{
	i = ++cc;
	if(l==r){fa[i] = f;	dep[i] = dep[pre];	return ;}
	L[i] = L[pre];	R[i] = R[pre];
	if(x<=mid)	update(l,mid,L[pre],L[i],x,f);
	else	update(mid+1,r,R[pre],R[i],x,f);
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
void solve()
{
	n = read();	m = read();
	build(T[0],1,n);
	int o,a,b,k;
	for(int i=1;i<=m;i++)
	{
		o = read();
		if(o==1)
		{
			T[i] = T[i-1];
			a = read();	b = read();
			int x = find(T[i],a),	y = find(T[i],b);
			if(x==y)	continue;
			if(dep[x]>dep[y])	swap(x,y);
			update(1,n,T[i-1],T[i],fa[x],fa[y]);
			if(dep[x]==dep[y])	add(T[i],1,n,fa[y]);
		}
		if(o==2)
		{
			k = read();	T[i] = T[k];
		}
		if(o==3)
		{
			T[i] = T[i-1];
			a = read();	b = read();
			int x = find(T[i],a),	y = find(T[i],b);
			if(fa[x]==fa[y])puts("1");
			else	puts("0");
		}
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

