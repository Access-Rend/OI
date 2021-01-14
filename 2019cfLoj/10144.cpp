#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m,P=1e6;
set<long long>a,b;
int main()
{
	scanf("%d",&n);
	long long ans=0;
	a.insert(-0x7ffffffffll),a.insert(0x7ffffffffll);
	b.insert(-0x7ffffffffll),b.insert(0x7ffffffffll);
	while(n--)
	{
		static int o,y;scanf("%d%d",&o,&y);
		if(o)
		{
			if(a.size()>2)
			{
				long long p=*--a.lower_bound(y),q=*a.lower_bound(y);
				if(y-p<=q-y)ans+=y-p,a.erase(p);
				else ans+=q-y,a.erase(q);
				ans%=P;
			}else b.insert(y);
		}
		else
		{
			if(b.size()>2)
			{
				long long p=*--b.lower_bound(y),q=*b.lower_bound(y);
				if(y-p<=q-y)ans+=y-p,b.erase(p);
				else ans+=q-y,b.erase(q);
				ans%=P;
			}
			else a.insert(y);
		}
	}
	printf("%d",ans%P);
	return 0;
}
