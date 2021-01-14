#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define _for(a,b) for(int i=a;i<=b;i++)
using namespace std;
const int inf=0x7fffffff-10;
int head[60],ph;
inline int trn(char c){return (c>='a'&&c<='z') ? c-'a' : c-'A'+26;}
inline bool getk(int x){return x>26;}
struct Edge{
	int to,v,nxt;
}E[7200];
void add(int a,int b,int v)
{
	E[++ph]=(Edge){b,v,head[a]};head[a]=ph;
	E[++ph]=(Edge){a,v,head[b]};head[b]=ph;
}

int dis[60];
queue<int>Q;
void spfa()
{
	swap(s,t);
	_for(1,n)dis[i]=inf;	dis[s]=0;
	while(!Q.empty())
	{
		int u=Q.front();
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

