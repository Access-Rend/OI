#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,k,a[20];
char s[20];
long long f[20][10];
inline int trn(int l,int r)
{
	int res=0;
	for(int i=l;i<=r;i++)	res *= 10, res += a[i];
	return res;
}
inline void ini()
{	
	for(int i=1;i<=n;i++)	a[i] = s[i]-'0';
	for(int i=1;i<=n;i++)	f[i][0] = trn(1,i);
}
void solve()
{
	scanf("%d%d%s",&n,&k,s+1);
	ini();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=k && j<i;j++)
	for(int l=j;l<i;l++)
	{
		f[i][j] = max( f[i][j] , f[l][j-1] * trn(l+1,i) );
	}
	printf("%lld",f[n][k]);
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

