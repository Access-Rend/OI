#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
    int t; //������ͨ��Ľڵ�
    int apple; //��i����֦��ƻ����
    int next; //��i���ߵ���һ����
};
node e[2*101];
int dp[101][101];
int head[101],n,q,tot=0;
void add(int x,int y,int z)  //�ڽӱ����
{
    e[++tot].t=y;
    e[tot].apple=z;
    e[tot].next=head[x];
    head[x]=tot;
}
void dfs(int f,int fa,int apple) 
{
    int son[101]={0},cnt=0; 
    bool flag=false;
    for(int xun=head[f];xun;xun=e[xun].next)
    {
        if(e[xun].t!=fa)
        {
            flag=true;
            son[++cnt]=xun;
            dfs(e[xun].t,f,e[xun].apple);
        }
    }
    if(!flag) 
    {
        return;
    }
    for(int i=1;i<=q;i++) 
    {
        for(int j=0;j<=i;j++)
        {
            int t1=0;
            if(j-1>=0) t1+=e[son[1]].apple; 
            if(i-j-1>=0) t1+=e[son[2]].apple;
            if(j!=0)
                dp[f][i]=max(dp[f][i],dp[e[son[1]].t][j-1]+t1+dp[e[son[2]].t][i-j-1]); 
            else 
                dp[f][i]=max(dp[f][i],dp[e[son[2]].t][i-j-1]+t1);
        }
    }
}
int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n-1;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0,0);
    printf("%d",dp[1][q]); 
    return 0;
}
