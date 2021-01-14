#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int a[110],f[110][2],n;
char s[110];

long long dp(int x,int pre,int flg,int lim)
{
	if(!x)return 1;
	if(!lim && f[x][flg]!=-1)return f[x][flg];
	
	long long ans=0;int m;
	if(!flg)m = lim ? min(pre,a[x]) : pre ;
	else	m = lim ? a[x] : 9 ;
	if(!flg)
	{
		for(int i=0;i<=m;i++)
		ans += dp(x-1,i,0,lim && i==a[x]) + dp(x-1,i,1,lim && i==a[x]) ;
	}
	else
	{
		for(int i=pre+1;i<=m;i++)
		ans += dp(x-1,i,1,lim && i==a[x]);
	}
	if(!lim)f[x][flg]=ans;
	return ans;
}

void solve()
{
	int T;	scanf("%d",&T); 
	while(T--)
	{
		memset(s,0,sizeof(s));
		memset(f,-1,sizeof(f));
		scanf("%s",&s[1]);
		int n=strlen(&s[1]);
		for(int i=1;i<=n;i++)a[i]=s[n-i+1];
		
		printf("%lld\n",dp(n,0,0,1) + dp(n,0,1,0));
		
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

