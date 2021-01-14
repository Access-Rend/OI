#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
typedef long long ll; 
using namespace std;

int f[20][2];
int vis[9],s[9],t[9];
bool judge_ans()
{
	for(int i=0;i<=9;i++)
	{
		if(vis[i])if(t[i])return 0;
		if(!vis[i])if(s[i])return 0;
	}
	return 1;
}
void judge_dig(int x)
{
	return !t[x];
}
ll dfs(int pos,bool lim)
{
	if(!pos)return judge_ans();
	if(!lim && f[pos][0]!=-1)return f[pos][0];
	int up = lim ? a[pos] : 9 ;
	ll ans=0;
	
	for(int i=0;i<=up;i++)
		if(judge_dig(i)){vis[i]++;ans+=dfs(pos-1,lim && i==a[i]);vis[i]--;}
	
	return ans;
}
ll solve(ll x)
{
	int pos=0;
	while(x)a[++pos]=x%10,x/=10;
	return dfs(pos,1);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

