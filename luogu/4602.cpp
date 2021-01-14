#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mid ((l+r)>>1)
const int N=1e5+10,inf=0x3f3f3f3f;
int n,m;
struct Data
{
	int d,p,l;
	inline void rd(){scanf("%d%d%d",&d,&p,&l);}
	bool operator < (const Data&o)
	{return d<o.d;}
}D[N];

int Rt,rt[N],L[N<<1],R[N<<1],A[N<<1],P[N<<1],cs;
void build(int &i,int l,int r)
{
	i = ++cs;	A[i] = P[i] = 0;
	if(l<r)build(L[i],l,mid),build(R[i],mid+1,r);
}
void update(int &i,int pre,int l,int r,int p,int a)
{
	i = ++cs;
	L[i] = L[pre];	
	R[i] = R[pre];	
	A[i] = A[pre] + a;	
	P[i] = P[pre] + a*p;
	if(l<r)
	if(p<=mid)	update(L[i],L[pre],l,mid,p,a);
	else	update(R[i],R[pre],mid+1,r,p,a);
}
void query(int x,int y,int l,int r,int a,LL &p)
{
	static LL na,La,Lp;	na = A[y]-A[x];	La=A[L[y]]-A[L[x]];	Lp=P[L[y]]-P[L[x]];
	if(l==r)
	{
		if(a>=0 && a<=na)	p += l*a;
		else if(a>na) p = -1;	
	}
	else
	{
		if(La>a)query(L[x],L[y],l,mid,a,p);
		else	query(R[x],R[y],mid+1,r,a-La,p+=Lp);	
	}
}
inline void dvd(LL &maxp,LL &minl)
{
	static int l,r;	l = 1;	r = n;
	static LL res;
	while(l!=r)
	{
		res = 0;
		query(rt[mid-1],rt[n],1,100000,minl,res);
		if(res<=maxp && res>=0)	l = mid + 1;
		else	r = mid;
	}
	res = 0;
	query(rt[l-1],rt[n],1,100000,minl,res);
	if(res>maxp)res=-1;
	if(res<=0 || res>maxp)
	{
		--l;res = 0;
		if(l>0)
			query(rt[l-1],rt[n],1,100000,minl,res);
	}
	if(res<=0 || res>maxp)res = -1;	else res = D[l].d;
	printf("%d\n",res);
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)D[i].rd();
	sort(D+1,D+1+n);
	build(rt[0],1,100000);
	for(int i=1;i<=n;i++)
	update(rt[i],rt[i-1],1,100000,D[i].p,D[i].l);
	while(m--)
	{
		static LL maxp,minl;
		scanf("%lld%lld",&maxp,&minl);
		dvd(maxp,minl);
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

