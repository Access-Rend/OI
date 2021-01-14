#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

char a[210],b[7][20];
int k,n,s;
int f[210][7],c[210][210];


void read()
{
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)
	scanf("%s",&a[1+i*20-20]);
	scanf("%d",&s);
	for(int i=1;i<=s;i++)
	scanf("%s",&b[i][1]);
}
bool judge(int p,int g,int x)
{
	if(x)
	{
		for(int i=p-b[g][0]+1;i<=p;i++)
		if(a[i]!=b[g][p-i-1])return false;
	}
	else
	{
		for(int i=p;i<=p+b[g][0]-1;i++)
		if(a[i]!=b[g][i-p+1])return false;
	}
	return true;
}
void build()
{
	for(int i=1;i<=n*20;i++)
	{
		for(int j=i;j<=n*20;j++)
		{
			for(int l=1;l<=s;l++)
			{
				if(judge(i,l,0))c[i][j]=max(c[i][j],c[i+b[l][0]][j]+1);
				if(judge(j,l,1))c[i][j]=max(c[i][j],c[i][j-b[l][0]]+1);
			}
		}
	}
}

void solve()
{
	read();
	build();
	for(int i=1;i<=n*20;i++)
	for(int j=1;j<=i;j++)
	for(int k=1;k<=s;k++)
	{
		f[i][k]=max(f[i][k] , f[j][k-1]+c[j+1][i]);
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	
	
	
	fclose(stdin);
	return 0;
}
