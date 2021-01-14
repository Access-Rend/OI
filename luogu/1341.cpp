#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

int n;

int head[210],ph;
struct Edge{
	int to,next;
}E[2010];
void add(int a,int b){
	E[++ph]=(Edge){b,head[a]};head[a]=ph;
}

int in[200];
void dfs(int u,int fa)
{
	for(int i=head[u];i;i=E[i].next)
	if(E[i].to!=fa)
	dfs(E[i].to,u);
	printf("%c",(char)u);
}
void solve()
{
	char ch[4];
	int st=0,pt=0,s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",&ch[1]);
		in[(int)ch[1]]++;in[(int)ch[2]]++;
		if(in[(int)ch[1]]==1)st++;
		if(in[(int)ch[2]]==1)st++;
		if(in[(int)ch[1]]==2)st--,pt++;
		if(in[(int)ch[2]]==2)st--,pt++;
		add((int)ch[1],(int)ch[2]);
		add((int)ch[2],(int)ch[1]);
	}
	
	if(st != 2 || pt != n-1)
	{	printf("No Solution");return ;	}
	else
		dfs(s,0);
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

