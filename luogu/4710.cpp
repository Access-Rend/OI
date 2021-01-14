#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
double v,a;
int main() 
{
	scanf("%lf%lf",&v,&a);
	double x0=(v*v*cos(a)*sin(a))/10,y0=(v*v*cos(a)*cos(a))/(10*2);
	printf("%lf %lf",x0,y0);;
	
	return 0;
}
