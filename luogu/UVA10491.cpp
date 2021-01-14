#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int a,b,c; 
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		printf("%.5lf\n",((double)a/(double)(a+b))*((double)b/(double)(a+b-c-1)) + ((double)b/(double)(a+b))*(((double)b-1)/(double)(a+b-c-1)));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

