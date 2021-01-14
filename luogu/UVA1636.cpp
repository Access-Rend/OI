#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
char a[110];
void solve()
{
	int _0=0,_01=0,_00=0,len=strlen(&a[1]);
	a[0]='*',a[++len]=a[1];
	for(int i=1;i<=len;i++)
	{
		if(a[i]=='0')
		{
			if(a[i-1]=='0')_00++;
			_0++;
		}
		else
			if(a[i-1]=='0')_01++;
	}
	if(a[len]=='0')_0--;//环形的影响 
	if(_0*_0 > _00* (len-1))printf("ROTATE\n");
	if(_0*_0 < _00* (len-1))printf("SHOOT\n");
	if(_0*_0 == _00* (len-1))printf("EQUAL\n");
	memset(a,0,sizeof(a));
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%s",&a[1])!=EOF)
	{
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

