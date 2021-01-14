#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+10;
int n,m,rbq,ans,N,L;
bool vis[MAXN];
const double pi = acos(-1.0);
int rev[MAXN];//rev 蝴蝶操作用 N为n+m的2幂长度 
struct cplx
{
	double r,v;
	cplx operator + (const cplx &a){return (cplx){r+a.r,v+a.v};}
	cplx operator - (const cplx &a){return (cplx){r-a.r,v-a.v};}
	cplx operator * (const cplx &a){return (cplx){r*a.r - v*a.v,r*a.v + v*a.r};}
}A[MAXN],B[MAXN],C[MAXN];
void init()
{
	for(N=1,L=0;N<=n+m;N<<=1,L++);//补齐2的幂
	if(L)L--;//涉及蝴蝶操作？ 
	for(int i=0;i<N;i++)rev[i] = (rev[i>>1]>>1) | ((i&1)<<L) ;//蝴蝶操作反转要用 
}
void FFT(cplx *a,int flg)
{
	for(int i=0;i<N;i++)	if(i<rev[i])	swap(a[i],a[rev[i]]);
	
	for(int i=1;i<N;i<<=1)
	{
		cplx wn = (cplx){cos(pi/i),flg*sin(pi/i)};
		for(int j=0;j<N;j+=(i<<1))
		{
			cplx w = (cplx){1,0};
			for(int k=0;k<i;k++,w = w*wn)
			{
				cplx x = a[j+k],	y = w*a[j+k+i];
				a[j+k] = x + y;
				a[j+k+i] = x - y;
			}
		}
	}
	if(flg==-1)for(int i=0;i<N;i++)a[i].r /= N;
}
void solve()
{
	while(~scanf("%d",&n))
	{
		static int ojj;
		m = n;	ans = 0;
		memset(A,0,sizeof(A));memset(B,0,sizeof(B));memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		scanf("%d",&ojj),	A[ojj].r+=1,	B[ojj].r+=1;
		init();
		
		FFT(A,1);FFT(B,1);
		for(int i=0;i<N;i++)C[i] = A[i]*B[i];
		FFT(C,-1);
		
		scanf("%d",&rbq);
		for(int i=1;i<=rbq;i++)scanf("%d",&ojj),vis[ojj]=1;
		
		for(int i=0;i<=n+m;i++)if(vis[(int)(C[i].r+0.5)])ans++;
		printf("%d\n",ans);	
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

