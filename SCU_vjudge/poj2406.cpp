#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e7+10;
char  s[N];
int nxt[N];
void getnxt()
{
	int n=strlen(s+1);
	for(int i=2,j=0;i<=n;i++)
	{
		while(j>0&&s[i]!=s[j+1])j=nxt[j];
		if(s[j+1]==s[i])j++;
		nxt[i]=j;
	}
}
void solve()
{
	while(1)
	{
		memset(s,0,sizeof(s));
		memset(nxt,0,sizeof(nxt));
		scanf("%s",s+1);	if(s[1]=='.')return	;
		getnxt();
		int n=strlen(s+1);
		if(n%(n-nxt[n])==0)printf("%d\n",n/(n-nxt[n]));
		else printf("1\n");
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

