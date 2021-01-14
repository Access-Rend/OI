#include<bits/stdc++.h>

using namespace std;

const int MAXN = 50010;
void swap(int &x,int &y){
	int t = x;
	x = y;
	y = t;
}
int sum = 0;
int ans[MAXN<<1][20];
int pa[MAXN];

int n,m,dfsc = 0;
int id[MAXN<<1];
int vis[MAXN<<1];
int cont = 0;
struct Edge{
	int s,t,value,nxt;
	Edge(int u,int v,int w,int nt):s(u),t(v),value(w),nxt(nt){}
	Edge(){
		s = 0;
		t = 0;
		value = 0;
		nxt = 0;
	}
};
Edge e[100010];
Edge new_e[2*MAXN];
int head[MAXN];
int tot;
int fa[MAXN];
int dp[MAXN<<1][60];
int deep[MAXN];
bool comp(const Edge& a,const Edge &b){
	return a.value<b.value;
}
void dfs(int u,int fa,int d){
	 if(deep[u])return ;
	 //id[u] = dfsc;
	//vis[dfsc] = u;
	deep[u] = d;
	for(int i = head[u];i;i = new_e[i].nxt){
		int v = new_e[i].t;
		if(v == fa)continue;
		pa[v] = i;
		dfs(v,u,d+1);
		//vis[dfsc] = u;
		//deep[dfsc++] = d;
	}
	return ;
}
int fnd(int x){
	if(fa[x] != x)fa[x] = fnd(fa[x]);
	return fa[x];
}
inline void find_deep(){
	dfsc = 1;
	dfs(1,-1,0);
}

inline void kruskal(){
	sort(e,e+tot,comp);
	int sum = 0;
	for(int i=0;i<tot;++i){
		int x = fnd(e[i].s);
		int y = fnd(e[i].t);
		if(x==y)continue;
		else{
			fa[x] = y;
			++sum;
			new_e[++cont] = Edge(e[i].s,e[i].t,e[i].value,head[e[i].s]); 
			head[e[i].s] = cont;
			new_e[++cont] = Edge(e[i].t,e[i].s,e[i].value,head[e[i].t]);
			head[e[i].t] = cont;
			if(sum == n-1)break;
		}
	}
	find_deep();
	return ;
}

inline void initlca(){
	for(int i=1;i<=n;++i){
		dp[i][0] = new_e[pa[i]].s;
		ans[i][0] = new_e[pa[i]].value;
	}
	for(int j=1;j<=17;++j){
		for(int i=1;i <= n;++i){
			dp[i][j] = dp[dp[i][j-1]][j-1];
			ans[i][j] = max(ans[dp[i][j-1]][j-1],ans[i][j-1]);
		}
	}
}
inline int lca(int u,int v){
	
	if(deep[u] < deep[v]){
		swap(u,v);
	} 
	int c = deep[u] - deep[v];
	int ret = 0;
	for(int i = 0; i <= 17; i++){
    	if(c & (1 << i)){
    		ret = max(ret,ans[u][i]);
			u = dp[u][i];
		}
 	}
 	if(u == v)return ret;
 	if(dp[u][0] == dp[v][0]){
	 	ret = max(ret,ans[u][0]);
	 	ret = max(ret,ans[v][0]);
	 	return ret;
	 }
 	for(int i = 17;i>=0;--i){
	 	if(dp[u][i]!=dp[v][i]){
		 	ret = max(ret,ans[u][i]);
		 	ret = max(ret,ans[v][i]);
		 	u = dp[u][i];
		 	v = dp[v][i];
		}
	 }
	 if(dp[u][0] == dp[v][0]){
	 	ret = max(ret,ans[u][0]);
	 	ret = max(ret,ans[v][0]);
	 	return ret;
	 }
 	return ret;
}
inline void solve(){
	int q; 
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		int u,v;
		int maxx = 0; 
		scanf("%d%d",&u,&v);
		int pt = lca(u,v);
		if(sum)cout<<endl;
		printf("%d\n",pt);
	}
	sum++;
}
inline void init1(){
	while(scanf("%d%d",&n,&m)!=EOF){
		cont = 0;
		tot= 0;
		memset(deep,0,sizeof(deep));
		memset(ans,0,sizeof(ans));
		memset(dp,0,sizeof(dp));
		memset(head,0,sizeof(head));
		for(int i=1;i<=n;++i){
			fa[i] = i;
		}
		for(int i=1;i<=m;++i){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			e[tot++] = Edge(a,b,c,head[a]);
		}
	kruskal();
	find_deep();
	initlca();
	solve();
	}
	return ;
}
int main(){
	init1();
	return 0;
} 

