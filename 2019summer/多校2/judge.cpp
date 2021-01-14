#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
int ans[20],len;
char s[20];
bool ishw(int l,int r)
{
	for(int i=l;i<=(l+r)>>1;i++)if(s[i-1]!=s[r-i+l-1])return 0;
	return 1;
}
void cal(int l)
{
	for(int i=1;i<=len-l;i++)
	if(ishw(i,l-1+i) && ishw(i,(l+i+i-1)>>1))ans[l]++;
}
void solve()
{
	scanf("%s",s);
	len = strlen(s);
	for(int i=1;i<=len;i++)
	{
		cal(i);
	}
	ans[1]=len;
	for(int i=1;i<=len;i++)
	printf("%d ",ans[i]);
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

