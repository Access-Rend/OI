#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<stack>
using namespace std;
const int N=1e5+10,inf=0x7fffffff>>1;
int n,m;
char ch;
void solve()
{
	int a=0,b=0,p=0;
	stack<int>S;
	while(scanf("%c",&ch)!=EOF)
	{
		if(ch=='(')
		a++,S.push(0);
		if(ch==')')
		{
			if(S.empty() || S.top()!=0){printf("Wrong");return;}
			else	a--,S.pop();
		}
		if(ch=='[')
		b++,S.push(1);
		if(ch==']')
		{
			if(S.empty() || S.top()!=1){printf("Wrong");return;}
			else	b--,S.pop();
		}
	}
	if(a==0 && b==0 && S.empty())printf("OK");
	else	printf("Wrong");
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

