#include<bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
const int N=100000+2;
const int U=100001;
int n,m;
struct haha{
    int nxt,to;
}e[2*N];
int hd[N],cnt;
void add(int x,int y){
    e[++cnt].nxt=hd[x];
    e[cnt].to=y;hd[x]=cnt;
}
int fa[N][18];
int dep[N];
int ans[N];
void dfs(int x,int d){//no fa
    dep[x]=d;
    for(int i=hd[x];i;i=e[i].nxt){
        int y=e[i].to;if(y==fa[x][0]) continue;
        fa[y][0]=x;dfs(y,d+1);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int j=17;j>=0;j--){
        if(dep[fa[x][j]]>=dep[y]) x=fa[x][j];
    }
    if(x==y) return x;
    for(int j=17;j>=0;j--){
        if(fa[x][j]!=fa[y][j]) x=fa[x][j],y=fa[y][j];
    }return fa[x][0];
}

int L[N<<6],R[N<<6],mx[N<<6],id[N<<6];
int tot;
int rt[N];
void pushup(int x){
    if(L[x]&&R[x]){
        mx[x]=max(mx[L[x]],mx[R[x]]);
        id[x]=mx[L[x]]>=mx[R[x]]?id[L[x]]:id[R[x]];
    }
    else if(L[x]){
        mx[x]=mx[L[x]];
        id[x]=id[L[x]];
    }
    else if(R[x]){
        mx[x]=mx[R[x]];
        id[x]=id[R[x]];
    }
}
void upda(int &x,int l,int r,int p,int c){
    
    if(!x) x=++tot;
    //cout<<x<<" "<<l<<" "<<r<<" : "<<p<<" "<<c<<endl;
    if(l==r) {
        id[x]=l,mx[x]+=c;
        return;
    }
    if(p<=mid) upda(L[x],l,mid,p,c);
    else upda(R[x],mid+1,r,p,c);
    pushup(x);
}
int merge(int x,int y,int l,int r){
    if(!x||!y) return x|y;
    if(l==r){
        mx[x]+=mx[y];
    }
    else{
    L[x]=merge(L[x],L[y],l,mid);
    R[x]=merge(R[x],R[y],mid+1,r);
    pushup(x);
    }
    return x;
}
void cal(int x){//no fa
    //cout<<" solving "<<x<<endl;
    for(int i=hd[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa[x][0]) continue;
        cal(y);
        //cout<<" rtx rty "<<rt[x]<<" "<<rt[y]<<endl;
        rt[x]=merge(rt[x],rt[y],1,U);
        //cout<<t[rt[x]].mx<<" "<<t[rt[x]].id<<endl;
    }
    if(mx[rt[x]]>0)ans[x]=id[rt[x]];
}
int main()
{
	freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);int x,y;
    for(int i=1;i<=n-1;i++){
        scanf("%d%d",&x,&y);add(x,y);add(y,x);
    }dfs(1,1);
    dep[0]=-1;
    for(int j=1;j<=17;j++)
        for(int i=1;i<=n;i++)
             fa[i][j]=fa[fa[i][j-1]][j-1];
    int z;
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        int anc=lca(x,y);
        //cout<<" anc "<<anc<<" "<<fa[anc][0]<<endl;
        upda(rt[x],1,U,z,1);
        upda(rt[y],1,U,z,1);
        upda(rt[anc],1,U,z,-1);
        if(fa[anc][0])upda(rt[fa[anc][0]],1,U,z,-1);
        
    }
    cal(1);
    for(int i=1;i<=n;i++){
        printf("%d\n",mx[rt[i]]>0?id[rt[i]]:0);
//	printf("%d\n",ans[i]);
    }return 0;
}
