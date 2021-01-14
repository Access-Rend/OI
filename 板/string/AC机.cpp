#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int maxn=1e6+10;
int n,cnt;
struct Nd
{
	int son[26],fail,end;
}nd[maxn];

void build(char *s)
{
	int len=strlen(s+1),u=0;
	for(int i=1;i<=len;i++)
	{
		int c=s[i]-'a';
		if(!nd[u].son[c])nd[u].son[c]=++cnt;
		u=nd[u].son[c];
	}
	nd[u].end++;
}
void getfail()
{
	queue<int>Q;
	for(int i=0;i<26;i++)//pushµÚÒ»²ã 
	{
		if(nd[0].son[i])
			nd[nd[0].son[i]].fail=0,
			Q.push(nd[0].son[i]);
	}
	
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		for(int i=0;i<26;i++)
		{
			if(nd[u].son[i])
				nd[nd[u].son[i]].fail = nd[nd[u].fail].son[i] ,
				Q.push(nd[u].son[i]);
			else
				nd[u].son[i] = nd[nd[u].fail].son[i];
		}
	}
}
void acauto(char *t)
{
	int len=strlen(t+1),u=0,ass=0;
	for(int i=1;i<=len;i++)
	{
		int c=t[i]-'a';	u=nd[u].son[c];
		for(int j=u; j && nd[j].end!=-1 ;j=nd[j].fail)
		{
			ass+=nd[j].end;nd[j].end=-1;
		}
	}
	return ass;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

