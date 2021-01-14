#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=1010;
using namespace std;
int n,m,nxt[N],mrk[N],f[N];
char s[N],t[N];
void getnxt()
{
	for(int i=2,j=0;i<=n;i++)
    {
        while(j>0&&s[j+1]!=s[i])j=nxt[j];
        if(s[j+1]==s[i])j++;
        nxt[i]=j;
    }
}
void kmp()
{
    for(int i=1,j=0;i<=m;i++)
    {
        while(j>0&&s[j+1]!=t[i])j=nxt[j];
        if(s[j+1]==t[i])j++;
        if(j==n)
        mrk[i]=1,j=nxt[j];
    }
}
void ini()
{
	memset(f,0,sizeof(f));
	memset(nxt,0,sizeof(nxt));
	memset(mrk,0,sizeof(mrk));
	memset(s,0,sizeof(s));
	memset(t,0,sizeof(t));
	
}
void solve()
{
	while(1)
	{
		ini();
		scanf("%s %s",t+1,s+1);	if(t[1]=='#')break;
		n=strlen(s+1);m=strlen(t+1);
		getnxt();kmp();
		for(int i=n;i<=m;i++)f[i] = max( mrk[i]+f[i-n] , f[i-1]);
		printf("%d\n",f[m]);
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
