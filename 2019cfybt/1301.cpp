#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e6+10,inf=0x7fffffff>>1;
int n,m,a[N],f[N][2];
inline void ini()
{
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
}
void solve()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		ini();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		f[1][1] = a[1];
		for(int i=2;i<=n;i++)
		f[i][0] = max( f[i-1][1] , f[i-1][0] ),
		f[i][1] = max( f[i-2][1] + a[i] , f[i-1][0] + a[i] );
		
		printf("%d\n",max( f[n][0] , f[n][1] ));
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

