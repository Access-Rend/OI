#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int N=1e6+10;
struct acautoo
{
	int ch[N][26],cnt[N],fail[N],pc;
	void ini()
	{
		pc=0;
		memset(ch,0,sizeof(ch));
		memset(cnt,0,sizeof(ch));
		memset(fail,0,sizeof(fail));
	}
	void insert(char *s)
	{
		int u=0,n=strlen(s+1);
		for(int i=1;i<=n;i++)
		{
			if(!ch[u][s[i]-'a'])
				ch[u][s[i]-'a']=++pc;
		}
		cnt[u]++;
	}
	void getf()
	{
		queue<int>Q;
		for(int i=0;i<26;i++)
		if(ch[0][i])f[ch[0][i]]=0,Q.push(ch[0][i]);
		while(!Q.empty())
		{
			int u=Q.front();Q.pop();
			for(int i=0;i<26;i++)
			if(ch[u][i])
			{
				f[ch[u][i]]=ch[f[u][i]];
				Q.push(ch[u][i]);
			}
			else	ch[u][i]=ch[f[u]][i];
			
		}
	}
	int query(char *s)
	{
		
	}
}AC;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

