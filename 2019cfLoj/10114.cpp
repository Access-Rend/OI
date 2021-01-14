#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
int ans[N],T[N];
inline int lowb(int x)	{	return -x&x;	}
inline void add(int x,int k)
{
	for(int i=x;i<=40000;i+=lowb(i))	T[i] += k;
}
inline LL query(int x)
{
	LL res = 0;
	for(int i=x;i>0;i-=lowb(i))	res += T[i];
	return res;
}
inline void solve()
{
	scanf("%d",&n);
	int x,y;
	_for(i,1,n)
	{
		scanf("%d%d",&x,&y);x++; 
		ans[query(x)]++;
		add(x,1);
	}
	_for(i,0,n-1)printf("%d\n",ans[i]);
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

