#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define for_(i,a,b) for(int i=a;i>=b;i--)
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e6+10,inf=0x3f3f3f3f>>1;
int n,m,MIN,K,ans;
/*
careful to RETURN in 'merge()' and 'split()' before the fuction's endline
remember UPDATE before RETURN
*/ 
struct Treap
{
	int pr[N],sz[N],ls[N],rs[N],v[N],rt,cnt;
	int newnd(int a){v[++cnt]=a;pr[cnt]=rand();return cnt;}
	void update(int u){sz[u]=sz[ls[u]]+sz[rs[u]]+1;}
	void split(int u,int &l,int &r,int k)//<=
	{
		if(!u){l=r=0;return ;}
		if(v[u]<=k)	l=u,split(rs[u],rs[l],r,k);
		else	r=u,split(ls[u],l,ls[r],k);
		update(u);
	}
	void split_rk(int u,int &l,int &r,int k)
	{
		if(!u){l=r=0;return ;}
		if(sz[ls[u]]+1<=k)l=u,split_rk(rs[l],rs[l],r,k-sz[ls[u]]-1);
		else	r=u,split_rk(ls[r],l,ls[r],k);
		update(u);
	}
	void merge(int &u,int l,int r)
	{
		if(!l||!r){u=l|r;if(u)update(u);return ;}
		if(pr[l]<pr[r])	u=r,merge(ls[u],l,ls[u]);	
		else	u=l,merge(rs[u],rs[u],r);	
		update(u);
	}
	void insert(int v)
	{
		int x,y;split(rt,x,y,v-1);
		merge(x,x,newnd(v));merge(rt,x,y);
	}
	void del(int v)
	{
		if(!sz[rt])return;
		int x,y,z;split(rt,x,y,v);
		split(x,x,z,v-1);
    	merge(z,ls[z],rs[z]);//删一个的写法 
		merge(x,x,z);
		merge(rt,x,y);
	}
	int rk(int v)
	{
		int x,y,res;
		split(rt,x,y,v-1);  	res = sz[x]+1;	merge(rt,x,y);
		return res;
	}
	int kth(int u,int k)
	{
		if(k>sz[rt])return -1;
		k = sz[rt] - k +1;
    	while(1)
		{
        	if(k==sz[ls[u]]+1)return v[u] + K;
        	if(k<=sz[ls[u]])u=ls[u];
       		else k-=sz[ls[u]]+1,u=rs[u];//注意先修改k!!!
    	}
    }
    void pre(int v)
    {
    	int x,y;split(rt,x,y,v-1);
	    printf("%d\n",kth(x,sz[x]));
		merge(rt,x,y);
	}
	void suf(int v)
	{
		int x,y;split(rt,x,y,v);
		printf("%d\n",kth(y,1));
		merge(rt,x,y);
	}
	int erase(int v)
	{
		int x,y;
		split(rt,x,y,v-1);rt = y;
		return sz[x];
	}
}Tp;
void solve()
{
	srand(time(0));
	scanf("%d%d",&n,&MIN);
	_for(i,1,n)
	{
		static int x;static char o[2];		scanf("%s%d",&o,&x);
		if(o[0]=='I')if(x>=MIN)Tp.insert(x-K);
		if(o[0]=='A')K += x;
		if(o[0]=='S')K -= x,	ans += Tp.erase(MIN - K);
		if(o[0]=='F')printf("%d\n",Tp.kth(Tp.rt,x));
	}
	printf("%d",ans);
}
//x + k > min
//real: x+k

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
