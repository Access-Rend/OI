#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e6+10;
int T,nxt[N];
char s[N],t[N];
void getnxt()
{
	int n=strlen(s+1);
	for(int i=2,j=0;i<=n;i++)
	{
		while(j>0 && s[j+1]!=s[i])j=nxt[j];
		if(s[j+1]==s[i])j++;
		nxt[i]=j;
	}
}
int kmp()
{
	int ans=0,n=strlen(t+1),m=strlen(s+1);
	for(int i=1,j=0;i<=n;i++)
	{
		while(j>0 && s[j+1]!=t[i])j=nxt[j];
		if(s[j+1]==t[i])j++;
		if(j==m)ans++;
	}
	return ans;
}
void solve()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		memset(s,0,sizeof(s));memset(t,0,sizeof(t));
		memset(nxt,0,sizeof(nxt));
		scanf("%s%s",s+1,t+1);
		getnxt();
		printf("%d\n",kmp());
		for(int i=1;i<=strlen(s+1);i++)printf("%d ",nxt[i]);
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
