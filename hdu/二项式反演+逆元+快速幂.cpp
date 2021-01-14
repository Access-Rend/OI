#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
const int mo=1000000007;
using namespace std;
int k,n,m;
long long pow(long long a,int k)
{
	long long res=a;
	while(k){
		if(k&1)res*=a;
		else a*=a;
		a%=mo;res%=mo;k>>=1;
	}
	return (res*a)%mo;
}
long long inv(int x)
{
	return pow(x,mo-2);
}
long long Cnm(int a,int b)
{
	long long resa=1,resb=1;
	for(int i=b+1;i<=a;i++)
	{
		resa*=(i%mo);
		resa%=mo;
	}
	for(int i=1;i<=a-b;i++)
	{
		resb*=(i%mo);
		resb%=mo;
	}
	resa*=inv(resb);
	return resa;
}
void solve()
{
	long long ans=0;int sgn = (k&1)?1:-1;
	for(int i=0;i<=k;i++)
	{
		long long res= sgn*( Cnm(i,k)*(i%mo) %mo );
		res*=pow(i-1,n-1);res%=mo;
		ans+=res;
		sgn=-sgn;
	}
}
void In()
{
	scanf("%d%d%d",&n,&m,&k);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,Case=0;scanf("%d",&T);
	while(T--)
	{
		In();
		printf("Case #%d: ",++Case);
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

