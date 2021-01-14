#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
int a[N];
int Q1[N],Q2[N],p1,p2,p3,p4;
void add(int &i)
{
	while(a[i]<a[Q1[p2]] && p1<=p2)--p2;
	Q1[++p2] = i;
	if(i-Q1[p1]+1>m)++p1;
	while(a[i]>a[Q2[p4]] && p3<=p4)--p4;
	Q2[++p4] = i;
	if(i-Q2[p3]+1>m)++p3;
}
void solve()
{
	scanf("%d%d",&n,&m);
	_for(i,1,n)scanf("%d",&a[i]);
	p1=p2=p3=p4=1;
	Q1[1] = Q2[1] = 1;
	_for(i,2,m-1)add(i);
	_for(i,m,n)add(i),printf("%d %d\n",a[Q2[p3]],a[Q1[p1]]);
	
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

