#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m;
char s1[1010],s2[1010];
int f[1010][1010];
void solve()
{
	scanf("%s%s",s1+1,s2+1);
	int len1 = strlen(s1+1), len2 = strlen(s2+1);
	for(int i=1;i<=len1;i++)
	for(int j=1;j<=len2;j++)
	{
		if(s1[i] == s2[j])
		f[i][j] = max( f[i][j] , f[i-1][j-1] + 1 );
		f[i][j] = max( f[i][j] , f[i-1][j] );
		f[i][j] = max( f[i][j] , f[i][j-1] );
	}
	printf("%d",f[len1][len2]);
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

