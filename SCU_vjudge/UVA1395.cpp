#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100+10,M=10010,inf=0x7fffffff-10;

int n,m;

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
int ini_UF(){for(int i=1;i<=n;i++)f[i]=i;}
int newMST()
{
	int res=inf;
	sort(P+1,P+1+m);
	for(int l=1;l<=m;l++)
	{
		
		int got=0,min_v=inf,max_v=-inf;
		ini_UF();
		for(int i=l;i<=m && got!=n-1;i++)
		{
			int fa=find(P[i].a),fb=find(P[i].b);
			if(fa!=fb)
			{
				f[fa]=fb;
				max_v=max(max_v,P[i].v);min_v=min(min_v,P[i].v);
				got++;
			}
		}
		if(got==n-1)res=min(res,max_v-min_v);
	
	}
	return res==inf?-1:res;
}
void solve()
{
	while(1)
	{
		scanf("%d%d",&n,&m);if(n==0)break;
		pp=0;
		for(int i=1;i<=m;i++){	int a,b,v;scanf("%d%d%d",&a,&b,&v);add(a,b,v);	}
		
		printf("%d\n",newMST());
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
