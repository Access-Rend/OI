#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=50000+10;
int n,a[N],b[N],pos[N],block; 
void add(int l,int r,int c)
{
	int flg = min(pos[l]*block , r);
	for(int i=l;i<=flg;i++)a[i]+=c;
	
	if(pos[l]!=pos[r])//和直接return的区别？？？？ 
	{
		flg = max((pos[r]-1)*block+1 , l);
		for(int i=r;i>=flg;i--)a[i]+=c;
	}
	for(int i=pos[l]+1;i<=pos[r]-1;i++)b[i]+=c;
}
void ini()
{
	block=sqrt(n);
	for(int i=1;i<=n;i++)pos[i]=(i-1)/block+1;
}
void solve()
{
	scanf("%d",&n);
	ini();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int o,l,r,c;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&o,&l,&r,&c);
		if(o)printf("%d\n",a[r]+b[pos[r]]);
		else add(l,r,c);
	}
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

