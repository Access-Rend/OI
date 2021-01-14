#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
const int N=100000+10;
#define mid ((l+r)>>1)
#define MID ((L+R)>>1)
#define ls son[p][0]
#define rs son[p][1]
int n,m,a[N];
using namespace std;

struct pst//静态p树 
{
	int son[N<<1][1],ps;double v[N<<1];
	void ini()	{	ps=1;	}
	void build(int p,int l,int r)//build的边界是l==r，query和add的边界是L==l && R==r 
	{
		if(l==r){	v[p]=a[l];	return ;	}
		ls = ++ps;	build(ls,l,mid);
		rs = ++ps;	build(rs,mid+1,r);
		v[p] = v[ls]*v[rs];
	}
	double query(int p,int l,int r,int L,int R) 
	{
		if(l==L && r==R)return v[p];
		if(L>=mid+1){return query(rs,mid+1,r,L,R);}
		if(R<=mid){return query(ls,l,mid,L,R);}
		return query(ls,l,mid,L,mid) * query(rs,mid+1,r,mid+1,R);
	}
};

struct tst//加权t树 
{
	
	int son[N<<1][1],ps;double lazy[N<<1],v[N<<1];
	void ini()
	{
		ps=1;
		for(int i=1;i<=N<<1;i++)lazy[i]=1;
	}
	void update(int p,int q,int vpr){v[p]/=vpr; v[p]*=v[q] ;}//it's son return to itself
	void pushdown(int p)
	{
		v[p]*=lazy[p];//cla
		if(l==r){	lazy[p]=1;return ;	}
		lazy[ls]*=lazy[p];	lazy[rs]*=lazy[p];	lazy[p]=1;
	}
	void build(int p,int l,int r)
	{
		if(l==r){	v[p]=1;	return ;	}
		ls = ++ps;	build(ls,l,mid);
		rs = ++ps;	build(rs,mid+1,r);
		v[p] = v[ls]*v[rs];
	}
	void mul(int p,int l,int r,int L,int R,int lz)
	{
		double vl=v[ls],vr=v[rs];
		if(l==L && r==R){lazy[p]*=lz; pushdown(p); return ;}
		if(L>=mid+1){mul(rs,mid+1,r,L,R,lz);update(p,rs,vr);return ;}
		if(R<=mid)	{mul(ls,l,mid,L,R,lz);	update(p,ls,vl);return ;}
		mul(ls,l,mid,L,mid,lz);	mul(rs,mid+1,r,mid+1,R,lz);
		update(p,rs,vr);	update(p,ls,vl);
	}
	double query(int p,int l,int r,int L,int R) 
	{
		if(lazy[p])pushdown(p);
		if(l==L && r==R)return v[p];
		if(L>=mid+1){return query(rs,mid+1,r,L,R);}
		if(R<=mid){return query(ls,l,mid,L,R);}
		return query(ls,l,mid,L,mid) * query(rs,mid+1,r,mid+1,R);
	}
};


struct qst//q树 
{
	pst PST;tst TST;
	void ini()
	{
		PST.ini();TST.ini();PST.build();TST.build();
	}
	void mul(int p,int l,int r,int L,int R,int lz)
	{
		TST.mul(p,l,r,L,R,lz);
	}
	double query(int p,int l,int r,int L,int R) 
	{
		double tt = TST.query(p,l,r,L,R) , pp = PST.query(p,l,r,L,R);
		if(l==L && r==R)return tt*(1-pp);
		if(L>=mid+1){return query(rs,mid+1,r,L,R);}
		if(R<=mid){return query(ls,l,mid,L,R);}
		return query(ls,l,mid,L,mid) * query(rs,mid+1,r,mid+1,R);
	}
}QST;

void solve()
{
	
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	
	
	fclose(stdin);
	fclose(stdout);
}
