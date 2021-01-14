#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m;
void solve()
{
	srand(time(0));
	int n = rand()%10;
	char s[20];
	for(int i=1;i<=n;i++)s[i] = rand()%5 + 'a';
	for(int i=1;i<=n;i++)printf("%c",s[i]);
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

