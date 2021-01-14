#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1000009;
ll tree[N*4+100];
ll lazy[N*4+100];
ll a[N];
ll n,m;
inline void pushdown(ll v,ll le,ll re)
{
	if(!lazy[v]){
		return;
	}
	ll mid=(le+re)>>1;
	
	tree[v*2]+=(mid-le+1)*lazy[v];
	tree[v*2+1]+=(re-mid)*lazy[v];
	lazy[v*2]+=lazy[v];
	lazy[v*2+1]+=lazy[v];
	
	lazy[v]=0;
}
inline void build(ll le,ll re,ll v)
{
	if(le==re){
		tree[v]=a[le];
		return ;
	}
	ll mid=(le+re)>>1;
	build(le,mid,v*2);build(mid+1,re,v*2+1);
	tree[v]=tree[v*2+1]+tree[v*2];
}
inline void add(ll le,ll re,ll v,ll x,ll y,ll t)
{
	if(le>y||re<x){
		return;
	}
	if(le>=x&&re<=y){
		lazy[v]+=t;
		tree[v]+=(re-le+1)*t;
		return ;
	}pushdown(v,le,re);
	ll mid=(le+re)>>1;
	if(x<=mid){
		add(le,mid,v*2,x,y,t);
	}
	if(y>mid){
		add(mid+1,re,v*2+1,x,y,t);
	}
	tree[v]=tree[v*2]+tree[v*2+1];
}
inline ll qur(ll le,ll re,ll v,ll l,ll r)
{
	
	if(le>=l&&re<=r){
		return tree[v];
	}
	pushdown(v,le,re);
	ll mid=(le+re)>>1;
	ll ans1=0,ans2=0;
	if(l<=mid){
		ans1+=qur(le,mid,v*2,l,r);
	}
	if(r>mid){
		ans2+=qur(mid+1,re,v*2+1,l,r);
	}
	return ans1+ans2;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	build(1,n,1);
	int op;
	ll lf,rf,tf;
	while(m--){
		scanf("%d%lld%lld",&op,&lf,&rf);
		if(op==1){
			scanf("%lld",&tf);
			add(1,n,1,lf,rf,tf);
		}
		else{
			printf("%lld\n",qur(1,n,1,lf,rf));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
