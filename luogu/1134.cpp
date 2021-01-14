#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
inline void mm2(long long &x)
{
	while(x%10==0)x/=10;
}
void solve()
{
	long long ans=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		long long res=i;
		ans*=res;
		ans%=100000000;
		if(i%5==0)mm2(ans);
//		printf("%d\n",ans);
	}
	printf("%lld",ans%10);
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

