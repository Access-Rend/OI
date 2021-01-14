#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
int a,b,c,d;
inline int cal(int x){return a*x*x*x + b*x*x + c*x + d ;}
void solve()
{
	scanf("%d%d%d%d%d",&a,&b,&c,&d);
	for(int i=0;i<=100;i++)
	{
		if(cal(i)==0){printf("%d ",i);return ;}
		if(cal(-i)==0){printf("%d ",i);return ;}
	}
}
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	solve();
	return 0;
}

