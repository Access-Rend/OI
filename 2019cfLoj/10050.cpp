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
	int ch[N*32][2],cnt[N*32],pc;
	void ini()
	{
		pc=0;
		memset(ch,0,sizeof(ch));
		memset(cnt,0,sizeof(cnt));
	}
	void insert(char *s)
	{
		int u=0,len=35;
		for(int i=0;i<len;i++)
		{
			if(!ch[u][s[i]-'0'])
				ch[u][s[i]-'0']=++pc;
			u=ch[u][s[i]-'0'];
		}
		cnt[u]++;
	}
	long long query(char *s)
	{
		int u=0,len=35;
		long long res = 0;
		for(int i=0;i<len;i++)
		{
			res<<=1;
			if(ch[u][(s[i]-'0')^1])
				u=ch[u][(s[i]-'0')^1],res++;
			else
				u=ch[u][s[i]-'0'];
		}
		return res;
	}
}tr;
inline void trn(int x)
{
	int i=0;
	while(x)s[i++] = (x&1) + '0',	x>>=1;
	for(;i<35;i++)s[i] = '0';
	for(int j=0;j<=17;j++)swap(s[j],s[34-j]);
}
void solve()
{
	int T,x;
	long long ans = 0;
	scanf("%d",&T);tr.ini();
	while(T--)
	{
		memset(s,0,sizeof(s));
		scanf("%d",&x);	trn(x);
		ans = max(ans,tr.query(s));
		tr.insert(s);
	}
	printf("%lld\n",ans);
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

