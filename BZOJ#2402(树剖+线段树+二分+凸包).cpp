/*
	Name: BZOJ#2402
	Author: CIao 
	Date: 18/02/19 20:10
	Description: 树剖+线段树+二分+凸包 
*/
#include<bits/stdc++.h>
#define Fst first
#define Snd second
#define RG register
#define mp make_pair
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned int UI;
typedef unsigned long long ULL;
template<typename T> inline void read(T& x) {
	char c = getchar();
	bool f = false;
	for (x = 0; !isdigit(c); c = getchar()) {
		if (c == '-') {
			f = true;
		}
	}
	for (; isdigit(c); c = getchar()) {
		x = x * 10 + c - '0';
	}
	if (f) {
		x = -x;
	}
}
template<typename T, typename... U> inline void read(T& x, U& ... y) {
	read(x), read(y...);
}
const int N=3e4+10;
const double eps=1e-9;
int n,p,Q,TIME;
int head[N],dep[N],son[N],num[N],fa[N],top[N],ID[N],rk[N];
double A[N],B[N],C[N],D[N];
struct Point {
	double x,y;
	Point () {}
	Point (double x,double y) :x(x),y(y) {}
};
typedef Point Vector;
Vector operator -(Point A,Point B) {
	return Vector(A.x-B.x,A.y-B.y);
}
double Cross(Vector A,Vector B) {
	return A.x*B.y-A.y*B.x;
}
double Slope(Vector A) {
	return A.y/A.x;
}
#define L o<<1
#define R o<<1|1
struct SegmentTree {
	Point P[N];
	vector<int> V[N<<2];
	void Insert(int o,int id) {
		if((int)V[o].size()&&P[id].y<=P[V[o][(int)V[o].size()-1]].y) return;
		while((int)V[o].size()>1&&Cross(P[id]-P[V[o][(int)V[o].size()-2]],P[V[o][(int)V[o].size()-1]]-P[V[o][(int)V[o].size()-2]])<=eps) V[o].pop_back();
		V[o].push_back(id);
	}
	void Modify(int l,int r,int o,int pos) {
		Insert(o,pos);
		if(l==r) return;
		int mid=l+r>>1;
		if(pos<=mid) Modify(l,mid,L,pos); 
		else Modify(mid+1,r,R,pos);
	}
	int Find(int l,int r,int o,double k) {
		if(l==r) return l;
		int mid=l+r>>1;
		if(Slope(P[V[o][mid+1]]-P[V[o][mid]])>=k) return Find(mid+1,r,o,k);
		return Find(l,mid,o,k);
	}
	double Query(int l,int r,int o,int ql,int qr,double k) {
		if(ql<=l&&r<=qr) {
			int Lx=1,Rx=(int)V[o].size()-1,res=0;
			while(Lx<=Rx) {
				int mid=Lx+Rx>>1;
				if(P[V[o][mid]].y-P[V[o][mid]].x*k>P[V[o][mid-1]].y-P[V[o][mid-1]].x*k) res=mid,Lx=mid+1;
				else Rx=mid-1;
			}
			return P[V[o][res]].y-P[V[o][res]].x*k;
		}
		int mid=l+r>>1;
		double t=-2e18;
		if(ql<=mid) t=Query(l,mid,L,ql,qr,k);
		if(qr>mid) t=max(t,Query(mid+1,r,R,ql,qr,k));
		return t;
	}
}S1,S2;
struct Edge {
	int to,last;
	Edge () {}
	Edge (int a,int b) :to(a),last(b) {}
}edge[N<<1];
void ADD(int a,int b) {
	edge[++p]=Edge(b,head[a]); head[a]=p;
	edge[++p]=Edge(a,head[b]); head[b]=p;
}
void DFS(int u) {
	num[u]=1;
	for(int i=head[u];i;i=edge[i].last) {
		int v=edge[i].to;
		if(v==fa[u]) continue;
		fa[v]=u; dep[v]=dep[u]+1; DFS(v);
		num[u]+=num[v];
		if(num[v]>num[son[u]]) son[u]=v;
	}
}
void SFD(int u,int topv) {
	ID[u]=++TIME; top[u]=topv;
	if(!son[u]) return;
	SFD(son[u],topv);
	for(int i=head[u];i;i=edge[i].last) {
		int v=edge[i].to;
		if(!ID[v]) SFD(v,v);
	}
}
bool Check(int u,int v,double k) {
	double a=-2e18,b=-2e18;
	while(top[u]!=top[v]) {
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		a=max(a,S1.Query(1,n,1,ID[top[u]],ID[u],k));
		b=max(b,S2.Query(1,n,1,ID[top[u]],ID[u],k));
		if(a+b>=-eps) return true;
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	a=max(a,S1.Query(1,n,1,ID[u],ID[v],k));
	b=max(b,S2.Query(1,n,1,ID[u],ID[v],k));
	return a+b>=-eps;
}
bool cmp1(int a,int b) {
	return A[a]<A[b];
}
bool cmp2(int a,int b) {
	return C[a]<C[b];
}
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("9.in","r",stdin);
	freopen("GG.out","w",stdout);
#endif
	read(n);
	for(int i=1;i<=n;++i) scanf("%lf",&A[i]),rk[i]=i;
	for(int i=1;i<=n;++i) scanf("%lf",&B[i]);
	for(int i=1;i<=n;++i) scanf("%lf",&C[i]);
	for(int i=1;i<=n;++i) scanf("%lf",&D[i]);
	for(int i=1;i<n;++i) {
		int u,v; read(u,v);
		ADD(u,v);
	}
	DFS(1); SFD(1,1);
	sort(rk+1,rk+n+1,cmp1);
	for(int i=1;i<=n;++i) S1.P[ID[rk[i]]]=Point(A[rk[i]],B[rk[i]]),S1.Modify(1,n,1,ID[rk[i]]);
	sort(rk+1,rk+n+1,cmp2);
	for(int i=1;i<=n;++i) S2.P[ID[rk[i]]]=Point(C[rk[i]],D[rk[i]]),S2.Modify(1,n,1,ID[rk[i]]);
	read(Q);
	while(Q--) {
		int u,v; read(u,v);
		double l=0,r=1e8,t=53;
		while(t--) {
			double mid=(l+r)/2.0;
			if(Check(u,v,mid)) l=mid;
			else r=mid;
		}
		printf("%.4lf\n",l);
	}
	return 0;
}

