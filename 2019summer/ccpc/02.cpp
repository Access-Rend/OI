#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mid ((l+r)>>1)
const int N=2e5+10,inf=0x3f3f3f3f>>1;
int n,m,rt;

int a[N],pos[N];
int v[N<<1],L[N<<1],R[N<<1],cn;

void build(int &i,int l,int r)
{
	i = ++cn;
	if(l<r)	build(L[i],l,mid),	build(R[i],mid+1,r),v[i] = max(v[L[i]],v[R[i]]);
	else	v[i] = pos[l];
}
void update(int i,int l,int r,int x)
{
	if(l<r)
	{
		if(x<=mid)	update(L[i],l,mid,x);
		else	update(R[i],mid+1,r,x);
		v[i] = max(v[L[i]],v[R[i]]);
	}
	else
	v[i] = n+1;
}
int query(int i,int l,int r,int p,int k)
{
	int res1 = inf,res2 = inf;
	if(l==r)return l;
	if(v[L[i]]>p && mid>=k)res1 = query(L[i],l,mid,p,k);
	if(res1 == inf && v[R[i]]>p) res2 = query(R[i],mid+1,r,p,k);
	return min(res1,res2);
}
void solve()
{
	cn = 0;memset(v,0,sizeof(v));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]),pos[a[i]]=i;
	build(rt,1,n);
	int last = 0,o,c,d;
	while(m--)
	{
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d",&c);
			c ^= last;
			update(1,1,n,a[c]);
		}
		else
		{
			scanf("%d%d",&c,&d);
			c ^= last;	d ^=last;
			last = query(1,1,n,c,d);
			if(last==inf)last = n+1;
			printf("%d\n",last);
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;scanf("%d",&T);
	while(T--)
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

