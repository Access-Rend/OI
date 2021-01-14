#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m,ans;
int G[110][110];
int f[10010];
bool vis[10010];
int find(int x){return x==f[x] ? x : f[x]=find(f[x]);}
inline int trn(int i,int j){return i*m+j-m;}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	scanf("%d",&G[i][j]);
	
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)f[trn(i,j)]=trn(i,j);
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(G[i][j])
	{
		int fa=find(trn(i,j)),fb;
		if(G[i-1][j])
		{
			fb=find(trn(i-1,j));
			f[fa]=fb;
		}
		if(G[i][j-1])
		{
			fb=find(trn(i,j-1));
			f[fa]=fb;
		}
		if(G[i][j+1])
		{
			fb=find(trn(i,j+1));
			f[fa]=fb;
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(G[i][j]) 
	{
		int x=find(trn(i,j));
		if(!vis[x])ans++;
		vis[x]=1;
	}
	printf("%d",ans);
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
