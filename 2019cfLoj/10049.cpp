#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int N=1e5+10;
char s[N];
struct Trie
{
	int ch[N][26],cnt[N],pc;
	void ini()
	{
		pc=0;
		memset(ch,0,sizeof(ch));
		memset(cnt,0,sizeof(cnt));
	}
	void insert(char *s)
	{
		int u=0,len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(!ch[u][s[i]-'0'])
				ch[u][s[i]-'0']=++pc;
			u=ch[u][s[i]-'0'];
		}
		cnt[u]++;
	}
	int query(char *s)
	{
		int u=0,len=strlen(s);
		for(int i=0;i<len;i++)
		{
			u=ch[u][s[i]-'0'];
			if(!u)return 0;
			if(cnt[u])return 1;
		}
		for(int i=0;i<10;i++)if(ch[u][i])return 1;
		return 0;
	}
}tr;

void solve()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);tr.ini();
		memset(s,0,sizeof(s));
		static int res;	res = 0;
		for(int i=1;i<=n;i++)
		{
			memset(s,0,sizeof(s));
			scanf("%s",s);
			res |= tr.query(s);
			tr.insert(s);
		}
		if(res)printf("NO\n");
		else printf("YES\n");
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

