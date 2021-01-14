#include<bits/stdc++.h>
using namespace std;
long long S[300];
char s[300];
int len;
long long scanint(int i)
{
	long long res=0,sgn=1;
	while(!(s[i]<='9'&&s[i]>='0' || s[i]=='-'))i++;
	if(s[i]=='-')sgn=-1;
	while(s[i]<='9'&&s[i]>='0')res*=10,res+=s[i]-'0',i++;
	return sgn*res;
}
void solve()
{
	int i=0;char c;
	while(scanf("%c",&c)!=EOF)s[++i]=c;
	s[0]=' ',len=i,i=0;
	while(i<len)
	{
		if(s[i]==' ')
		S[++S[0]]=scanint(i);
		i++;
	}
	S[0]--;
	i=0;
	while(s[i]!='@')
	{
		
		if(s[i]=='+')
		{int x=S[S[0]--],y=S[S[0]--];S[++S[0]]=x+y;}
		if(s[i]=='-')
		{int x=S[S[0]--],y=S[S[0]--];S[++S[0]]=y-x;}
		if(s[i]=='*')
		{int x=S[S[0]--],y=S[S[0]--];S[++S[0]]=x*y;}
		if(s[i]=='/')
		{int x=S[S[0]--],y=S[S[0]--];S[++S[0]]=y/x;}
		i++;
	}
	printf("%lld",S[S[0]]);
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
