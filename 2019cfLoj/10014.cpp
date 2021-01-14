#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int MAXN=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
int a[MAXN];
int dvd()
{
	int l=0,r=1e9,mid,sum,cnt,flg;
	while(l!=r)
	{
		mid = (l+r)>>1;	sum = cnt = flg = 0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>mid){flg=1;break;}
			if(sum+a[i]<=mid)sum+=a[i];
			else	sum=a[i],cnt++;
		}
		
		if(flg){l = mid + 1 ;continue;}
		
		cnt++;
		if(cnt>m)l = mid + 1;
		else r = mid;
	}
	return l;
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	printf("%d",dvd());
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

