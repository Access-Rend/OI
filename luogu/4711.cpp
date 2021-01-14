#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
char str[100];
double element(int x);
int readint(int x);
void In()
{
	scanf("%s",&str[1]);
}
void Solve()
{
	int n=strlen(&str[1]),k=0;double E=0,e=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(str[i]>='A' && str[i]<='Z')
		{
			if(k)
			{
				if(e!=0)
				E+=e;
				e=element(i);
			}
			else
			{
				if(e!=0)
				ans+=e;
				e=element(i);
			}
			continue;
		}
		if(k)E+=e;
		else ans+=e;
		e=0;
		if(str[i]=='(')k=1,e=0;
		if(str[i]==')')k=0,e=0;
		if(str[i]=='_')
		{
			if(k)E+=readint(i+2)*e,e=0;
			else
			{
				if(E)ans+=readint(i+2)*E,E=0;
				else ans+=readint(i+2)*e,e=0;
			}
		}
		if(str[i]=='~'){ans+=readint(i+1)*18;break;}
	}
	if(ans-(int)ans==0)printf("%d",(int)ans);
	else
	printf("%.1lf",ans);
}
int main()
{
	In();
	Solve();
	return 0;
}
int readint(int x)
{
	int res=0;
	for(int i=x;str[i]!='}';i++)
	res*=10,res+=str[i]-'0';
	return res;
}
double element(int x)
{
	if(str[x]=='H')
	{
		if(str[x+1]=='g')return 201;
		if(str[x+1]=='f')return 178.5;
		return 1;
	}
	if(str[x]=='C')
	{
		if(str[x+1]=='l')return 35.5;
		if(str[x+1]=='a')return 40;
		if(str[x+1]=='u')return 64;
		return 12;
	}
	if(str[x]=='N')
	{
		if(str[x+1]=='a')return 23;
		return 14;
	}
	if(str[x]=='O')return 16;
	if(str[x]=='F')
	{
		if(str[x+1]=='e')return 56;
		return 19;
	}
	if(str[x]=='M')
	{
		if(str[x+1]=='g')return 24;
		if(str[x+1]=='n')return 55;
	}
	if(str[x]=='A')
	{
		if(str[x+1]=='l')return 27;
		if(str[x+1]=='g')return 108;
		if(str[x+1]=='u')return 197;
	}
	if(str[x]=='S')
	{
		if(str[x+1]=='i')return 28;
		return 32;
	}
	if(str[x]=='P')
	{
		if(str[x+1]=='t')return 195;
		return 31;
	}
	if(str[x]=='K')return 39;
	if(str[x]=='Z')return 65;
	if(str[x]=='I')return 127;
	if(str[x]=='B')return 137;
}
