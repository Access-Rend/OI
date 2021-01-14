#include<iostream>
#include<cstdio>
using namespace std;
#define ld double
const ld esp = 1e-8;
int t,n;
int a[10010],b[10010],c[10010];
ld cal(ld&x){
	ld res=-0x3fffffff;
	for(int i=1;i<=n;i++)
		res=max(res,a[i]*x*x+b[i]*x+c[i]);
	return res;
}
int main()
{
	ld r,l,m1,m2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		l=0,r=1000;
		while(l-r<=esp){
			m1=l+(r-l)/3;
			m2=r-(r-l)/3;
			if(cal(m1)<cal(m2))
				r=m2;
			else
				l=m1;
		}
		printf("%.4f\n",cal(l));
	}
	return 0;
}
