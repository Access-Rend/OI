#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mid ((l+r)>>1)
#define lb(x) ((x)&(-(x)))
const int N=5e5+10,inf=0x3f3f3f3f;
int n,m,cnt,ans[N],x[N],y[N];
int T[N];
inline void add(int i,int x)
{
	for(;i<=n;i+=lb(i))T[i]+=x;
}
inline int query(int i)
{
	int res=0;
	for(;i>=1;i-=lb(i))res+=T[i];
}
struct Qst
{
	int x,y,type,id,sgn;
	bool operator <= (const Qst&o)
	{return x!=o.x ? x<=o.x : type<=o.type;}
}a[N<<3],tmp[N<<3];
void cdq(int l,int r)
{
	if(l==r)return ;
	cdq(l,mid);cdq(mid+1,r);
	int i = l,	j = mid + 1,	k = l;
	while(j<=r)
	{
		while(i<=mid && a[i]<=a[j])
		{
			if(a[i].type==1)add(a[i].y,1);
			tmp[k++] = a[i++];
		}
		ans[a[j].id] += query(a[j].y)*a[j].sgn;
		tmp[k++] = a[j++];
	}
	for(int _=l;_<=mid;_++)if(a[_].type==1)add(a[_].y,-1);
	for(int _=i;_<=mid;_++)tmp[k++]=a[_];
	for(int _=l;_<=r;_++)a[_] = tmp[_];
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		static int x,y;scanf("%d%d",&x,&y);
		a[i].x = x;a[i].y = y;a[i].type = 1;
	}
	cnt = n;
	for(int i=1;i<=m;i++)
	{
		static int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		a[++cnt].x = x1;a[cnt].y = y1;a[cnt].id = i;a[cnt].type = 2;a[cnt].sgn = 1;
		a[++cnt].x = x1;a[cnt].y = y2;a[cnt].id = i;a[cnt].type = 3;a[cnt].sgn = -1;
		a[++cnt].x = x2;a[cnt].y = y1;a[cnt].id = i;a[cnt].type = 4;a[cnt].sgn = -1;
		a[++cnt].x = x2;a[cnt].y = y2;a[cnt].id = i;a[cnt].type = 5;a[cnt].sgn = 1;
	}
	for(int i=1;i<=cnt;i++)
		x[i] = a[i].x,	y[i] = a[i].y;
	sort(x+1,x+1+cnt);	sort(y+1,y+1+cnt);
	x[0] = unique(x+1,x+1+cnt) - x - 1;	y[0] = unique(y+1,y+1+cnt) - y - 1;
	for(int i=1;i<=cnt;i++)
	{
		a[i].x = lower_bound(x+1,x+1+x[0],a[i].x) - x,	a[i].y = lower_bound(y+1,y+1+y[0],a[i].y) - y;	
		if(a[i].type==2)a[i].x--,a[i].y--;
		if(a[i].type==3)a[i].x--;
		if(a[i].type==4)a[i].y--;
	}
	
	cdq(1,cnt);
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
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

