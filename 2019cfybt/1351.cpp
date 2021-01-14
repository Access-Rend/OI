#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m;
void solve()
{
	char ch;
	while(scanf("%c",&ch)!=EOF)
	{
		if(ch=='(')n++;
		if(ch==')')n--;
	}
	if(n==0)printf("YES");
	else	printf("NO");
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

