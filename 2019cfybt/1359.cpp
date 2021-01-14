#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=20,inf=0x7fffffff>>1;
int n,G[N][N],f[N*N],ans;
bool vis[N*N];
int find(int x){return x==f[x] ? x : f[x]=find(f[x]);}
inline int trn(int i,int j){return i*n+j-n;}
void print()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	printf("%d ",f[trn(i,j)]);
}
void solve()
{
	n=10;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%d",&G[i][j]);
	
	for(int i=1;i<=n;i++)G[0][i]=G[i][0]=G[n+1][i]=G[i][n+1]=1;
	for(int i=1;i<=n*n;i++)f[i]=i; 
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(!G[i][j])
	{
		int fa=find(trn(i,j)),fb;
		if(!G[i][j-1])
		{
			fb=find(trn(i,j-1));
			f[fa]=fb;
		}
		if(!G[i-1][j])
		{
			fb=find(trn(i-1,j));
			f[fa]=fb;
		}
	}
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(G[i][j] && !G[i+1][j])
	{
		int fa=find(trn(i+1,j));
		for(int k=1;k<=n;k++)
		for(int l=1;l<=n;l++)
		{
			if(find(trn(k,l)==fa))
			ans++;
		}
		print(); 
		printf("%d",ans);
		return ;
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

