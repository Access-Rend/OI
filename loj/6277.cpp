#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[51000],ba[51000];
int block,pos[51000];
void update(int l,int r,int c)
{
    for(int i=l;i<=min(pos[l]*block,r);i++)a[i]+=c;
    if(pos[l]!=pos[r])
        for(int i=(pos[r]-1)*block+1;i<=r;i++)
            a[i]+=c;
    for(int i=pos[l]+1;i<=pos[r]-1;i++)ba[i]+=c;
}
int main()
{
    scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    block=sqrt(n);
    for(int i=1;i<=n;i++)pos[i]=(i-1)/block+1;
    for(int i=1;i<=n;i++)
    {
        int l,r,c,opt;
        scanf("%d%d%d%d",&opt,&l,&r,&c);
        if(opt==0)update(l,r,c);
        else printf("%d\n",a[r]+ba[pos[r]]);
    }
    return 0;
}
