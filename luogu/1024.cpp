#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
inline double delta(double a,double b,double c)
{	return b*b-4*a*c; }

double a,b,c,d;
double fun(double x)
{
	return a*x*x*x + b*x*x + c*x + d;
}
double fun_(double x)
{
	return 3*a*x*x + 2*b*x + c;
}

double dvs(double l,double r)
{
	double mid=(l+r)/2;
	for(int i=1;i<=100;i++)
	{
		if(fun(mid) / fun(l) > 0)
		l=mid;else 	r=mid;
		mid=(l+r)/2;
	}
	return mid;
}

void solve()
{
	scanf("%lf%lf%lf%lf0",&a,&b,&c,&d);
	double x1 = (-b-sqrt(b*b-3*a*c))/(3*a) , x2 = (-b+sqrt(b*b-3*a*c))/(3*a) ;
	double ans1=dvs(-100,x1),ans2=dvs(x1,x2),ans3=dvs(x2,100);
	printf("%.2lf %.2lf %.2lf",ans1,ans2,ans3);
}
int main()
{
	freopen("in.txt","r",stdin);
	solve();
	fclose(stdin);
	return 0;
}

