#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(0));
	printf("%d %d\n",n = rand()%10 + 1	,m = rand()%1000 + 1);
	for(int i=1;i<=n;i++)printf("%d ",rand());
	printf("\n");
	while(m--)
	
	{
		static int o;
		printf("%d ",o = (rand()&1) + 1);
		if(o==1)
		{
			static int l,r,x;
			l = rand()%n + 1,	r = rand()%n + 1,	x = rand();
			printf("%d %d %d\n",min(l,r),max(l,r),x);
		}
		else
		{
			static int l,r;
			l = rand()%n + 1,	r = rand()%n + 1;
			printf("%d %d\n",min(l,r),max(l,r));
		}
	}
	fclose(stdout);
	return 0;
}
