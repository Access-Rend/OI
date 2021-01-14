#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m;
struct edge{
	int a,b,v;
}E[100010];
bool cmp(edge x1,edge x2){return x1.v > x2.v;}
int f[100010];
void ini_f(){for(int i=1;i<=n+2;i++)f[i]=i;}
int find(int x)
{
	if(f[x]!=x)
	x=find(f[x]);
	return x;
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&E[i].a,&E[i].b,&E[i].v);
	sort(E+1,E+1+m,cmp);
	ini_f();
	for(int i=1;i<=m;i++)
	{
		int f1=find(E[i].a),f2=find(E[i].b);
		if(f2==n+1)swap(f1,f2); 
		if(f[f1]!=f[f2])f[f1]=n+1,f[f2]=n+2;
		else {	printf("%d",E[i].v);return ;	}
	}
	printf("0");
}
int main()
{
	freopen("in.txt","r",stdin);
	solve();
	fclose(stdin);
	return 0;
}
