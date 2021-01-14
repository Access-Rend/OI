#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define FOR(u) for(int i=head[u];i;i=E[i].nxt)
#define _for(a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e5+10,M=1e5+10,inf=0x7fffffff-10;
int n,m,maxv;
int head[N],ph;
struct Edge
{
	int to,v,nxt;
}E[M<<1];
inline void add(int a,int b,int v){E[++ph]=(Edge){b,v,head[a]};head[a]=ph;}
inline int scn_int()
{
    char c=getchar();int res=0,sgn=1;
    while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
    while(c>='0'&&c<='9')res*=10,res+=c-'0',c=getchar();
    return sgn*res;
}
bool vis[N];int tim[N],dis[N],in[N];
bool spfa(int ans)
{
	queue<int>Q;
	
	_for(1,n)dis[i]=tim[i]=vis[i]=0;//dis=0 all nodes be in the queue,but why?
	
	
	_for(1,n)Q.push(i),vis[i]=1;
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();vis[u]=0;
		FOR(u)
		{int v=E[i].to; 
			if(dis[v]>dis[u]+E[i].v-ans)
			{
				dis[v]=dis[u]+E[i].v-ans;
				if(!vis[v])
				{
					if(tim[v]>n)return 0;
					Q.push(v),tim[v]++;	
				}
			}
		}
	}
	return 1;
}
int dvd()
{
	int l=1,r=maxv,mid,flg;
	if(!spfa(1))return -1;
	if(spfa(r))return 0;
	while(l!=r)//think about the meaning of division
	//when 'l' is able to answer,then next line should contain the 'l'! 
	{
		mid=((l+r)>>1)+1;
		if(spfa(mid))l=mid;
		else r=mid-1;
	}
	return l;
}
void solve()
{
	while(~scanf("%d%d",&n,&m))
	{
		_for(1,m)
		{
			int a=scn_int(),b=scn_int(),v=scn_int();
			add(a,b,v);	maxv=max(maxv,v);
			in[b]++;
		}
		int ans=dvd();
		if(ans==-1)printf("No Solution\n");
		if(ans==0)printf("Infinite\n");
		if(ans>0)printf("%d\n",ans);
		_for(1,n)vis[i]=in[i]=dis[i]=head[i]=0;
		ph=ans=maxv=0;
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

