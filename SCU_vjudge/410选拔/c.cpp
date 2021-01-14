#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int p,s;
int w[510],G[510][510],ans=inf,id;
void solve()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		ans = inf,	id = 0;
		scanf("%d%d",&p,&s);
		_for(i,1,p)scanf("%d",&w[i]);
		_for(i,1,s)_for(j,1,p)scanf("%d",&G[i][j]),G[i][j]+=G[i-1][j];
		_for(j,1,p)
		{
			_for(i,1,s)
			if(G[i][j]>=w[j] && i<ans)
			{ans = i,id = j;}
		}
		if(!id)printf("Impossible\n");
		else printf("%d\n",id);
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

