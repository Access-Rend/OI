#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k,l,d;
struct Edge
{
	int v=0,no;
}X[1010],Y[1010];
bool cmp(Edge a,Edge b){return a.v > b.v;}
void add(int x1,int y1,int x2,int y2)
{
	if(x1==x2)Y[min(y1,y2)].v++;
	if(y1==y2)X[min(x1,x2)].v++; 
}
int ans[2][1010];
void solve()
{
	for(int i=1;i<=m;i++)X[i].no=i;
	for(int i=1;i<=n;i++)Y[i].no=i;
	
	sort(X+1,X+1+n,cmp);sort(Y+1,Y+1+n,cmp);
	for(int i=1;i<=k;i++){ans[0][i]=X[i].no;}
	for(int i=1;i<=l;i++){ans[1][i]=Y[i].no;}
	sort(ans[0]+1,ans[0]+1+k);sort(ans[1]+1,ans[1]+1+l);
	for(int i=1;i<=k;i++){printf("%d ",ans[0][i]);}printf("\n");
	for(int i=1;i<=l;i++){printf("%d ",ans[1][i]);}
}
void In()
{
	scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
	for(int i=1;i<=d;i++)
	{
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		add(x1,y1,x2,y2);
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	In();solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

