#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=50000+10;
int a[N],v[N],pos[N],m,n,b[N];
void update(int l)
{
	for(int i=l;i<=min(l+m-1,n);i++)b[i]=a[i];//细节emmmm 
	sort(b+l,b+min(l+m,n));//细节emmmmm 
}
void ini()
{
	m=sqrt(n);
	for(int i=1;i<=n;i++)pos[i]=(i-1)/m+1;
	for(int i=1;(i-1)*m<=n;i++)update((i-1)*m+1);//细节emmmmm 
}
void add(int l,int r,int c)
{
	int flg = min(pos[l]*m , r);
	for(int i=l;i<=flg;i++)a[i]+=c;	update((pos[l]-1)*m+1);
	
	if(pos[l]!=pos[r])//和直接return的区别？？？？ 
	{
		flg = max((pos[r]-1)*m+1 , l);
		for(int i=r;i>=flg;i--)a[i]+=c;	update((pos[r]-1)*m+1);
	}
	for(int i=pos[l]+1;i<=pos[r]-1;i++)v[i]+=c;
}
int dvd(int k,int x)
{
	x-=v[k];
	int l=(k-1)*m+1,r=min(k*m,n),mid;
	while(l!=r)
	{
		mid=(l+r)>>1;
		if(b[mid]<x)l=mid+1;
		else r=mid; 
	}
	while(b[l]>=x)l--;//
	return (l-(k-1)*m);
}
int query(int l,int r,int x)
{
	int res=0;
	int flg = min(pos[l]*m , r);
	for(int i=l;i<=flg;i++)
	res+=a[i]<x;
	if(pos[l]!=pos[r])//和直接return的区别？？？？ 
	{
		flg = max((pos[r]-1)*m+1 , l);
		for(int i=r;i>=flg;i--)res+=a[i]<x;
	}
	for(int i=pos[l]+1;i<=pos[r]-1;i++)res+=dvd(i,x);
	return res;
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ini();
	for(int i=1;i<=n;i++)
	{
		int o,l,r,x;
		scanf("%d%d%d%d",&o,&l,&r,&x);
		if(o)
			{x*=x;
			printf("%d\n",query(l,r,x));}
		else
			add(l,r,x);
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

