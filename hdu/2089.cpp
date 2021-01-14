#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

int a[20]; 
int f[20][2];

long long dp(int k,int pre,int flg,int lim)//k位，上一位，上一位是否满足特殊条件，目前前缀是否达到上限 
{
	if(!k)return 1;
	if(!lim && f[k][flg]!=-1)return f[k][flg];
	int m = lim ? a[k] : 9 ;
	long long ans=0;
	for(int i=0;i<=m;i++)
	{
		if(i==4)continue;
		if(pre==6 && i==2)continue;
		ans += dp(k-1,i,i==6,lim && i==a[k]);
	}
	if(!lim)f[k][flg]=ans;
	return ans;
}

long long query(long long x)
{
	int n=0;memset(f,-1,sizeof(f));
	while(x)a[++n]=x%10,x/=10;
	return dp(n,0,0,1);
}

void solve()
{
	while(1)
	{
		int l=1,r=1;
		scanf("%d%d",&l,&r);
		if(!l)break;
		printf("%d\n",query(r)-query(l-1));
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
