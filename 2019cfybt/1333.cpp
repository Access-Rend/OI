#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
long long n,a,p1,p2,Q[1000010],p=1e5;
void ini()
{
	memset(Q,0,sizeof(Q));p1=p2=1;
	Q[1]=a;
}
void solve()
{
	while(scanf("%lld%lld",&a,&n)!=EOF)
	{
		ini();
		for(int i=2;i<=n;i++)
		{
			if((Q[p1]<<1)+1 < Q[p2]*3+1)
			{Q[i]=(Q[p1]<<1)+1,p1++;continue;}
			
			if((Q[p1]<<1)+1 > Q[p2]*3+1)
			{Q[i]=Q[p2]*3+1,p2++;continue;}
			
			if((Q[p1]<<1)+1 == Q[p2]*3+1)
			{Q[i]=(Q[p1]<<1)+1,p1++,p2++;continue;}
		}
		printf("%lld \n",Q[n]);
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

