#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define _for(a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e3+10,Q=1e5+10;
int n,m;
struct Point
{
	int x,y,v;
	bool operator < (const Point other)
	{
		return this->v < other.v;
	}
}P[N*N];
int M[N][N],ans[Q],T,t[Q];
int f[N*N];
int find(int x){return x==f[x] ? x : x=find(f[x]);}
void iniUF(){_for(1,n*m)f[i]=i;}
inline int trn(int x,int y){return x*n-n+y;}
void In()
{
	scanf("%d%d",&n,&m);
	_for(1,n)for(int j=1;j<=m;j++)scanf("%d",&M[i][j]);
	scanf("%d",&T);_for(1,T)scanf("%d",&t[i]);
}
int vis[N][N];int cnt=0;
inline bool judge(int x,int y){return vis[x][y];}
int insert(int x,int y)//return new block
{
	vis[x][y]=1;
	int ff=find(trn(x,y)),f1=0,f2=0,f3=0,f4=0,res=1;
	if(judge(x+1,y))
	{f1=find(trn(x+1,y));	if(ff!=f1)f[f1]=ff,res--;}
	
	if(judge(x-1,y))
	{f2=find(trn(x-1,y));	if(ff!=f2)f[f2]=ff,res--;}
	
	if(judge(x,y+1))
	{f3=find(trn(x,y+1));	if(ff!=f3)f[f3]=ff,res--;}
	
	if(judge(x,y-1))
	{f4=find(trn(x,y-1));	if(ff!=f4)f[f4]=ff,res--;}
	return res;
}
void solve()
{
	In();
	iniUF();
	memset(vis,0,sizeof(vis));
	int pp=0;_for(1,n)for(int j=1;j<=m;j++)P[++pp]=(Point){i,j,M[i][j]};
	sort(P+1,P+1+n*m);
	
	cnt=0;
	int j=pp;
	for(int i=T;i>=1;i--)
	{
		for(;P[j].v>t[i];j--)
		{
			int X=P[j].x,Y=P[j].y;
			cnt+=insert(X,Y);
		}
		ans[i]=cnt;
	}
	_for(1,T)printf("%d ",ans[i]);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int Z;scanf("%d",&Z);
	while(Z--)solve(); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

