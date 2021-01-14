#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mid ((l+r)>>1)
const int N=1e5+10,inf=0x3f3f3f3f;
int n,m,t,maxv;
int a[210][210],sum[210][210][1010],cnt[210][210][1010];
inline int get_s(int x1,int y1,int x2,int y2,int k)
{
	return sum[x2][y2][k] - sum[x1-1][y2][k] - sum[x2][y1-1][k] + sum[x1-1][y1-1][k];
}
inline int get_c(int x1,int y1,int x2,int y2,int k)
{
	return cnt[x2][y2][k] - cnt[x1-1][y2][k] - cnt[x2][y1-1][k] + cnt[x1-1][y1-1][k];
}
int T[5500010],L[5500010],R[5500010],siz[5500010],val[5500010],cc;
void build(int &i,int l,int r)
{
	i = ++ cc;
	if(l<r)	build(L[i],l,mid),	build(R[i],mid+1,r);
}
void update(int pre,int &i,int l,int r,int x)
{
	i = ++cc;
	L[i] = L[pre];	R[i] = R[pre];	siz[i] = siz[pre] + 1;	val[i] = val[pre] + x;
	if(l<r)
	{
		if(x<=mid)	update(L[pre],L[i],l,mid,x);
		else	update(R[pre],R[i],mid+1,r,x);
	}
}
void query(int u,int v,int l,int r,int w,int &count)
{
	if(!w)return;
	int x = val[R[v]] - val[R[u]],	y = siz[R[v]] - siz[R[u]];
	if(l<r)
	{
		if(w<x)
			query(R[u],R[v],mid+1,r,w,count);
		else
			count += y,	query(L[u],L[v],l,mid,w-x,count);
	}
	else
	{
		x = val[v] - val[u],	y = siz[v] - siz[u];
		if(w<l)	count++;
		else	count += w/l + (w%l==0 ? 0 : 1);
	}
}
void specialsolve()
{
	build(T[0],1,1000);
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		update(T[i-1],T[i],1,1000,x);
	}
	while(t--)
	{
		static int a,b,c,d,h,count;
		count = 0;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&h);
		if(val[T[d]] - val[T[b-1]] < h){printf("Poor QLW\n");continue;}
		query(T[b-1],T[d],1,1000,h,count);
		printf("%d\n",count);
	}
}
void solve()
{
	scanf("%d%d%d",&n,&m,&t);
	if(n==1)
	{
		swap(n,m);
		specialsolve(); 
		return ;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]),	maxv=max(maxv,a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=maxv;k++)
			{
				sum[i][j][k]
				=	sum[i-1][j][k] + sum[i][j-1][k] -	sum[i-1][j-1][k]
				+	(a[i][j]>=k?a[i][j]:0);
				cnt[i][j][k]
				=	cnt[i-1][j][k] + cnt[i][j-1][k] -	cnt[i-1][j-1][k]
				+	(a[i][j]>=k?1:0);
			}
	while(t--)
	{
		int a,b,c,d,h;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&h);
		if(get_s(a,b,c,d,1)<h){printf("Poor QLW\n");continue;}
		int l = 1,	r = maxv;
		while(l!=r)
		{
			if(get_s(a,b,c,d,mid)>h)l = mid+1;
			else r = mid;
		}
		if(get_s(a,b,c,d,l)<h)l--;
		printf("%d\n",get_c(a,b,c,d,l) - (get_s(a,b,c,d,l)-h)/l);//Ãî°¡ 
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

