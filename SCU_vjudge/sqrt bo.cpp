#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
const double esp = 1e-9;
const long long biggest = 4294967296;
int n,m;
double x;
int a[130],b[130];char s[130];
void ini()
{
	long long x = biggest;
	while(x)b[++b[0]] = x%10,x/=10;
}
bool cmp()
{
	int len = strlen(s+1);
	for(int i=1;i<=len;i++)	a[i] = s[i] - '0';
	for(int i=1;i<=(len>>1);i++)	swap(a[i],a[n-i+1]);
	if(len > 10)return 0;
	if(len < 10)return 1;
	for(int i=10;i>=1;i--)
	{
		if(a[i]>b[i])return 0;
		if(a[i]<b[i])return 1;
	}
	return 1;
}
void solve()
{
	ini(); 
	while(scanf("%s",s+1)!=EOF)
	{
		if(strlen(s+1)==1 && s[1]==1+'0')	{printf("0\n");continue;}
		if(strlen(s+1)==1 && s[1]==0+'0')	{printf("TAT\n");continue;}
		
		if(!cmp())	
		{printf("TAT\n");continue;}
		
		int len = strlen(s+1);
		for(int i=1;i<=len;i++)x *= 10,	x += s[i] - '0';
		
		for(int i=1;i<=5;i++)
		{
			x = (double)((int)(sqrt(x)));
			if(x == 1)
			{
				printf("%d\n",i);break;
			}
		}
		if(x != 1)printf("TAT\n");
		
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
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

