#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int M=1010;
struct Rubbish{
    int t,v,h;
    bool operator < (const Rubbish &rhs) const {
        return t<rhs.t;
    }
}a[M];
int dp[2][M],n,m;
int read(){
    int x=0,f=1;char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
    while ('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
int main(){
    m=read(),n=read();
    for (int i=1;i<=n;i++)
        a[i].t=read(),a[i].v=read(),a[i].h=read();
    sort(a+1,a+n+1);
    memset(dp,~0x3f,sizeof(dp));
    dp[0][0]=10;a[0].t=0;
    int res=-INF;
    for (int i=1;i<=n;i++){
        int cur=i&1,pre=cur^1;
        memset(dp[cur],~0x3f,sizeof(dp[cur]));
        for (int j=m;j>=0;j--){
            if (dp[pre][j]<a[i].t-a[i-1].t)continue;
            if (j+a[i].h>=m){
                printf("%d",a[i].t);
                return 0;
            }
            dp[cur][j+a[i].h]=max(dp[cur][j+a[i].h],dp[pre][j]-(a[i].t-a[i-1].t));
            dp[cur][j]=max(dp[pre][j]+a[i].v-(a[i].t-a[i-1].t),dp[cur][j]);
        }
        res=max(res,dp[cur][0]+a[i].t);
    }
    printf("%d",res);
    return 0;
}
