#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
 
int main()
{
	int n,k;
	cin >> n >> k;
	int dp[201][7];
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=k;j++)
		{
			if(i>=j)
				dp[i][j] = dp[i-j][j] + dp[i-1][j-1];
		}
	cout <<dp[n][k] << endl;
	return 0;
}
