#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x7fffffff>>1;
int f[N],cnt[N];
int find(int x)	{	return f[x]==x ? x : f[x] = find(f[x]);	}
int n,m,x,y;
char s[10];
void solve()
{
	scanf("%d%d",&n,&m);
	_for(i,1,n)	cnt[i] = 1,	f[i] = i;
	while(m--)
	{
		scanf("%s",s);
		if(s[0]=='Q')
		{
			scanf("%d",&x);
			printf("%d\n",cnt[find(x)]);
		}
		else
		{
			scanf("%d%d",&x,&y);
			int f1 = find(x),	f2 = find(y);
			if(f1 == f2)continue ;
			if(cnt[f1]>cnt[f2])
			f[f2] = f1,	cnt[f1] += cnt[f2],	cnt[f2] = 0;
			else
			f[f1] = f2,	cnt[f2] += cnt[f1],	cnt[f1] = 0;
		}
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

