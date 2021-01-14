#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mid ((l+r)>>1)
#define lb(x) ( (x)&(-(x)) )
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=2e5+10,inf=0x3f3f3f3f;
int n,m,n_;
struct Elm
{
	int x,y,z,c,ans;
	bool operator < (const Elm&o)
	{
		return x==o.x ? (y==o.y?z<o.z:y<o.y) : x<o.x;
	}
	bool operator ==(const Elm&o)
	{return x==o.x && y==o.y && z==o.z;}
}a[N],tmp[N];
int T[N],CNT[N];
void add(int i,int x)
{
	for(;i<=m;i+=lb(i))
	T[i]+=x;
}
int query(int i)
{
	int res = 0;
	for(;i>=1;i-=lb(i))
	res += T[i];
	return res;
}
void cdq(int l,int r)
{
	if(l==r)return ;
	cdq(l,mid);cdq(mid+1,r);
	int i = l,	j = mid+1,	cnt = l;
	while(j<=r)
	{
		while(i<=mid && a[i].y<=a[j].y)
		{
			add(a[i].z,a[i].c);
			tmp[cnt++] = a[i++];
		}
		a[j].ans += query(a[j].z);
		tmp[cnt++] = a[j++];
	}
	for(int _=i;_<=mid;_++)	tmp[cnt++] = a[_];
	for(int _=l;_<i;_++)	add(a[_].z,-a[_].c);
	for(int _=l;_<=r;_++)	a[_] = tmp[_];
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),	a[i].c = 1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	if(a[i]==a[i-1])a[n_].c++;
	else	a[++n_] = a[i];
//	for(int i=1;i<=n;i++)printf("%d %d %d %d\n",a[i].x,a[i].y,a[i].z,a[i].id);
	cdq(1,n_);
//	cout<<endl; 
//	for(int i=1;i<=n;i++)printf("%d %d %d %d\n",a[i].x,a[i].y,a[i].z,a[i].id);
	for(int i=1;i<=n_;i++)CNT[a[i].ans+a[i].c-1]+=a[i].c;
//	for(int i=1;i<=n;i++)printf("%d* ",a[i].ans);
	for(int i=0;i<n;i++)printf("%d\n",CNT[i]);
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

