#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
const int N=1e5+10;
int n;
struct Pedge
{
    int a,b,v;
    bool operator< (const Pedge other) const
    {
        return this->v> other.v;
    }
}P[N];
int cnt[N],f[N];
LL sum[N];
int find(int a){return f[a]=(a==f[a]?a:find(f[a]));}

void solve()
{
	while(~scanf("%d",&n))
    {
        for(int i=0;i<n-1;i++)scanf("%d%d%d",&P[i].a,&P[i].b,&P[i].v);
        sort(P,P+n-1);
        for(int i=1;i<=n;i++)sum[i]=0,f[i]=i,cnt[i]=1;
        LL res=0;
        for(int i=0;i<n-1;i++)
        {
            int fa=find(P[i].a);
            int fb=find(P[i].b);
            LL atob=(LL)cnt[fa]*P[i].v+sum[fb];
            LL btoa=(LL)cnt[fb]*P[i].v+sum[fa];
            if(atob>btoa)
            {
                f[fa]=fb;
                cnt[fb]+=cnt[fa];
                sum[fb]=atob;
            }
            else
            {
                f[fb]=fa;
                cnt[fa]+=cnt[fb];
                sum[fa]=btoa;
            }
            res=max(res,max(atob,btoa));
        }
        printf("%lld\n",res);
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
