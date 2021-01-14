#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e6+10;
int T,nxt[N];
char s[N],t[N];
void solve()
{
	while(1)
	{
		int point=0,flag=0;memset(s,0,sizeof(s));
		scanf("%s",&s[1]);s[0]='.';
		if(s[1]=='E')return ;
		
		for(int i=0;i<=strlen(s)-1;i++)
		{
			if(s[i]=='.')
			{
				i++,point++;	int res=0;
				
				for(;s[i]>='0' && s[i]<='9';i++)
				res*=10,res+=s[i]-'0';
				
				if(res>255){printf("%d NO\n",res);flag=1;break;}
				if(i>=strlen(s)-1)break;
				i--;
			}
			else
			{flag=1;printf("NO\n");break;}
		}
		
		if(!flag)
		{
			if(point==4)printf("YES\n");
			else printf("NO\n");
		}
	}
} 
int main()
{
	solve();
	return 0;
}
