#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1010,M=1000010,inf=0x7fffffff-10;

int n,m,q,X[N],Y[N];

int pp;
struct Pedge
{
	int a,b,v;
	bool operator < (const Pedge other)
	{
		return this->v < other.v;
	}
}P[M];
void add(int a,int b,int v){P[++pp]=(Pedge){a,b,v};}

int f[N];
int find(int x){return x==f[x]?x:x=find(f[x]);}
void ini_UF(){for(int i=1;i<=n;i++)f[i]=i;}

int fc[10][N],vis[N],V[10];
int newMST(int s)
{
	int got=0,res=0;
	ini_UF();f[n+1]=n+1;memset(vis,0,sizeof(vis));
	
	for(int i=1;i<=q;i++)
	if( ((s>>(i-1)))&1 )
	{
		for(int j=1;j<=n;j++)
		if(fc[i][j])
			if(!vis[j])got++,vis[j]=1,f[j]=n+1;
		res+=V[i];
	}
	
	for(int i=1;i<=m&&got!=n-1;i++)
	{
		int fa=find(P[i].a),fb=find(P[i].b);
		if(vis[fa]==0 && vis[fb]==0)
		{
			if(fa!=fb)
			{
				f[fa]=fb;
				res+=P[i].v;
				got++;
			}
		}
	}
	if(got==n-1)return res;
}
int dfs(int dep,int s)
{
	if(dep==q)
	return newMST(s);
	return min( dfs(dep+1,s+(1<<dep)) , dfs(dep+1,s) );
}

void solve()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		pp=0;
		memset(fc,0,sizeof(fc));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&q);	m=(n*n-n)>>1;
		for(int i=1;i<=q;i++)
		{
			int k;scanf("%d",&k);
			for(int j=1;j<=k;j++){int a;scanf("%d",&a);fc[i][a]=1;}
			scanf("%d",&V[i]);
		}
		for(int i=1;i<=n;i++)scanf("%d%d",&X[i],&Y[i]);
		
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		add( i , j , (X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]) );
		
		sort(P+1,P+1+m);
		printf("%d\n",dfs(0,0));
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
