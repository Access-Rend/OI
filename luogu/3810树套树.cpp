#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mid ((l+r)>>1)
#define lb(x) ((x)&(-(x)))
const int N=2e5+10,inf=0x3f3f3f3f;
int n,m,rt[N],Ans[N];
struct Dt
{
	int a,b,c,ans;
	inline void read(){scanf("%d%d%d",&a,&b,&c);}
	bool operator < (const Dt&o)
	{if(a==o.a){if(b==o.b)return c<o.c;	else return b<o.b;}	else return a<o.a;}
}elm[N];
struct Treap
{
	int ky[N<<5],sz[N<<5],L[N<<5],R[N<<5],v[N<<5],cnt;
	int newnd(int x){v[++cnt] = x;	ky[cnt] = rand();	return cnt;}
	void update(int u){sz[u] = sz[L[u]] + sz[R[u]] + 1;}
	void split(int u,int &l,int &r,int x)//<=
	{
		if(!u){l = r = 0;return ;}
		if(v[u]<=x)	l = u,	split(R[u],R[l],r,x);
		else	r = u,	split(L[u],l,L[r],x);
		update(u);
	}
	void merge(int &u,int l,int r)
	{
		if(!l||!r){u = l|r;	if(u)update(u);	return ;}
		if(ky[l]<ky[r])	u = r,	merge(L[u],l,L[u]);	
		else	u = l,	merge(R[u],R[u],r);	
		update(u);
	}
	void insert(int &rot,int x)
	{
		int a,b;	split(rot,a,b,x-1);
		merge(a,a,newnd(x));	merge(rot,a,b);
	}
	int rk(int &rot,int x)
	{
		if(!rot)return 0;
		int a,b,res=0;
		split(rot,a,b,x-1);	res = sz[a]+1;	merge(rot,a,b);
		return res;
	}
}Tp;
inline void add(int x,int y)
{
	for(int i=x;i<=m;i+=lb(i))
	Tp.insert(rt[i],y);
}
inline int query(int x,int y)
{
	int res = 0;
	for(int i=x;i>=1;i-=lb(i))
	res += Tp.rk(rt[i],y+1);
	return res;
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)	elm[i].read();
	sort(elm+1,elm+1+n);
	for(int i=1;i<=n;i++)
	{
		Ans[query(elm[i].b,elm[i].c)]++;
		add(elm[i].b,elm[i].c);
	}
	
	for(int i=0;i<n;i++)
	cout<<Ans[i]<<endl;
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

