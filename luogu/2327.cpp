#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
const int N=10010;
using namespace std;
int n,a[N];bool f[N]; 
void In()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
}
bool judge(int i)
{
	if(a[i]==1)
	{
		if(f[i-1]&f[i])return 0;
		if(f[i-1]|f[i])return 1;
		if((f[i-1]|f[i])==0)f[i+1]=1;
	}
	if(a[i]==2)
	{
		if((f[i-1] | f[i])==0)return 0;
		if(2-f[i-1]-f[i])f[i+1]=1;
	}
		
	if(a[i==3])
	{
		if((f[i-1]&f[i])==0)return 0;
		f[i+1]=1;
	}
	return 1;
}
void solve()
{
	int ans=2;
	f[1]=0;
	for(int i=1;i<n;i++)
		if(!judge(i))break;
		if(a[n]!=(int)f[n]+(int)f[n-1])ans--;
	memset(f,0,sizeof(f));
	f[1]=1;
	for(int i=1;i<n;i++)
		if(!judge(i))break;
		if(a[n]!=(int)f[n]+(int)f[n-1])ans--;
	printf("%d",ans);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	In();
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

