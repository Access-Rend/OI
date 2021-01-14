#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
inline void read(int &x){
    int f=1; x=0; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    x= f<0? ~x+1:x;
}
int n,m;
int w[305],b[305],c[305],f[305][305];
void dfs(int x,int v){
    if(f[x][v]>=0) return;
    if(x==0||v==0) {f[x][v]=0; return;}
    dfs(b[x],v); f[x][v]=max(f[x][v],f[b[x]][v]);
    for(int i=0;i<v;++i){
        dfs(c[x],v-i-1);
        dfs(b[x],i);
        f[x][v]=max(f[x][v],f[b[x]][i]+f[c[x]][v-i-1]+w[x]);
    }
}        
int main(){
    read(n);read(m);
    int fa;
    for(int i=1;i<=n;++i){
        read(fa); read(w[i]);
        if(fa==0) fa=n+1;
        b[i]=c[fa];
        c[fa]=i;
    }
    memset(f,-1,sizeof(f));
    dfs(c[n+1],m);
    printf("%d\n",f[c[n+1]][m]);
    return 0;
}
