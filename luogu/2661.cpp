#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
const int N=200000;
using namespace std;
int link[N],vis[N],mrk,n,ans=0x7fffffff;
int Q[N];
int cal(int u)
{
	int res=1;
	while(Q[Q[0]--]!=u)res++;
	return res;
}
void solve()
{
	for(int u=1;u<=n;u++)
	{
		if(vis[u])continue;
		mrk++;
		for(int v=u;v;v=link[v])
		{
			if(vis[v]>0 &&vis[v]!=mrk)break;
			
			if(vis[v]!=mrk)
				vis[v]=mrk,Q[++Q[0]]=v;
			else
				{ans=min(ans,cal(v)); break ;}
		}
	}
	printf("%d",ans);
}
void In()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&link[i]);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	In();
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

