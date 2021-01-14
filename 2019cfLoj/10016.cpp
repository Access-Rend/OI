#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const double esp=1e-8;
double H,h,D;
void solve()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lf%lf%lf",&H,&h,&D);
		double mx=D-h*D/H;
		if (D>=sqrt((H-h)*D) && mx<=sqrt((H-h)*D))
            mx=D+H-2*sqrt((H-h)*D);
		else if (sqrt((H-h)*D)<mx)
            mx=h*D/H;
        else
            mx=h;
		printf("%.3lf\n",mx);
	}
}
int main()
{
	solve();
	return 0;
}


