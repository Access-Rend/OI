#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m;
long long a[N];
long long BIT[N];

inline int lowb(int x)	{return -x & x;}

inline void alter(int i,int x)
{
	for(;i<=n;i += lowb(i))	BIT[i] += x;
}
inline long long query(int i)
{
	long long res = 0 ;
	for(;i>0;i -= lowb(i))	res += BIT[i];
	return res;
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)	{scanf("%lld",&a[i]);a[i] += a[i-1];}
	while(m--)
	{
		int k,l,r;scanf("%d%d%d",&k,&l,&r);
		if(k)
			alter(l,r);
		else
			printf("%lld\n",a[r] - a[l-1] + query(r) - query(l-1));
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

