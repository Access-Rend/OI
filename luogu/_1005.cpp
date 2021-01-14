#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int f[90][90][90][1010],a[90][90],n,m;

void Is(int q1,int i1,int j1,int q2,int i2,int j2)
{
	for(int i=1;i<=1000;i++)f[q1][i1][j1][i]=f[q2][i2][j2][i];
}
void mu2(int q,int i,int j)
{
	for(int p=1;p<=999;p++)
	{
		f[q][i][j][p+1]+=(f[q][i][j][p]<<1)/10;
		f[q][i][j][p]=(f[q][i][j][p]<<1)%10;
	}
}
void add(int q,int i,int j,int x)
{
	for(int p=1;p<=999;p++)
	{
		f[q][i][j][p]+=x%10;
		f[q][i][j][p+1]+=f[q][i][j][p]/10;
		f[q][i][j][p]%=10;
		x/=10;
	}
}
bool cmp(int q1,int i1,int j1,int q2,int i2,int j2)
{
	int w1,w2,i;
	for(i=999;!f[q1][i1][j1][i];i--);w1=i;
	for(i=999;!f[q2][i2][j2][i];i--);w2=i;
	if(w1!=w2)return w1>w2;
	else
	for(int i=w1;i>=1;i--)
	if(f[q1][i1][j1][i]!=f[q2][i2][j2][i])return w1>w2;
	return w1>w2;
}
void dp(int q,int i,int j)
{
	bool k=cmp(q,i+1,j,q,i,j-1);
	if(k)
	{
		Is(q,i,j,q,i+1,j);mu2(q,i,j);add(q,i,j,a[q][i]<<1);
	}
	else
	{
		Is(q,i,j,q,i,j-1);mu2(q,i,j);add(q,i,j,a[q][j]<<1);
	}
}
void solve()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		for(int k=j;k<=m;k++)
		dp(i,j,k);
	}
}
void In()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	scanf("%d",&a[i][j]);
}
int main()
{
	freopen("in.txt","r",stdin); 
	In();
	solve();
	
	
	fclose(stdin);
	return 0;
}
