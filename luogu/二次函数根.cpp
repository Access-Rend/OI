#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	double x1=(-b-sqrt(b*b-4*a*c))/(2*a),x2=(-b+sqrt(b*b-4*a*c))/(2*a);
	printf("x1=%lf x2=%lf",x1,x2);
	return 0;
}

