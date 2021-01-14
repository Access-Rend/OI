#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<stack>
const int N=100010;
using namespace std;
int link[N],vis[N],ans[N],n,cnt;
stack<int>Q;
void Q_pop(int u)
{
	int res=0;stack<int>P;
	while(Q.top()!=u)P.push(Q.top()),Q.pop(),res++;
	P.push(Q.top()),Q.pop(),res++;
	while(!P.empty())ans[P.top()]=res,P.pop();
}
void dfs(int u)
{
	Q.push(u);
	vis[u]=cnt;
	if(!vis[link[u]])dfs(link[u]);
	if(!ans[link[u]] && vis[link[u]]==cnt){Q_pop(link[u]);return ;}
	if(!ans[u])ans[u]=ans[link[u]]+1;
	return ;
}
void solve()
{
	for(int i=1;i<=n;i++)
	if(!vis[i])
	{
		++cnt;
		dfs(i);
	}
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
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
	In();solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

