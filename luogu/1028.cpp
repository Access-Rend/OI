#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int f[1010],n



;
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=2 ; i<=n ; i++)
		for(int j=1 ; j <= i>>1 ; j++)
			f[i]+=f[j]+1;
	printf("%d",f[n]+1);
	fclose(stdin);
	return 0;
}

