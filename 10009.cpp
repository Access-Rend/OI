#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
const int N=1e5+10,inf=0x3f3f3f3f;
int n,m;
int lk[2010];
LL f[2010],a[2010],ans;
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	ans = 0;
	
	for(int t=1;t<=m;t++)
	{
		memset(f,0,sizeof(f));
		memset(lk,0,sizeof(lk));
		LL x,res=0;	f[1] = a[1];
		for(int i=1;i<=n;i++)
		{
				for(int j=1;j<i;j++)
				{
					if(a[i]>=a[j])
					if(f[i]<f[j]+a[i])f[i] = f[j] + a[i],	lk[i] = j;
				}
				if(f[i]>res)res = f[i],	x = i;
		}
		for(int i=x;i;i=lk[i])a[i] = 0;
		ans+=res;
	}
	printf("%lld\n",ans);
	/*for(int i=1;i<=n;i++)
	printf("%d ",a[i]);
	 
	printf("******\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)printf("%d ",f[i][j]);
		printf("\n");
	}
	printf("******\n");
	printf("%lld\n",ans);*/  
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
