#include<bits/stdc++.h>
#include<stack>
#include<map> 
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m,flg,len;
char s[300];
stack<int>S;
map<char,int>lst;
void ini()
{
	memset(s,0,sizeof(s));
	scanf("%s",s);
	len=strlen(s);
	
	while(!S.empty())S.pop();	S.push(inf);
	flg=1;
	lst['<']=0,lst['>']=4;
	lst['(']=1,lst[')']=5;
	lst['[']=2,lst[']']=6;
	lst['{']=3,lst['}']=7;
}
bool opt(char ch)
{
	bool res=1;int x=lst[ch];
	if(x<4)
	{
		if(S.top()<x)res=0;
		else	S.push(x);
	}
	else
	{
		if(S.top()!=x-4)res=0;
		else	S.pop();
	}
	return res;
}
void solve()
{
	scanf("%d",&n);
	while(n--)
	{
		ini();
		
		for(int i=0;i<len;i++)
		{
			if(!opt(s[i]))
			{flg=0;break;}
		}
		
		if(flg && S.top()==inf)printf("YES\n");
		else	printf("NO\n");
		
	}
}

int main()
{
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	solve();
	fclose(stdin);
//	fclose(stdout);
	return 0;
}

