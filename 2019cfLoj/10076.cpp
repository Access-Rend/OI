#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
#define INF 0x3f3f3f3f
 
using namespace std;
 
const int maxn=5000+10;
int n,m,u,v,val;
int dis[maxn];
struct P
{
    int to,cost;
    bool operator < (const P & a) const
    {
        return cost>a.cost;
    }
};
 
vector<P> edge[maxn];
 
void Dijkstra()
{
    fill(dis,dis+n+2,INF);
    dis[n]=0;
    priority_queue<P> qu;
    qu.push(P{n,0});
    while(!qu.empty())
    {
        P x=qu.top();
        qu.pop();
        for(int i=0;i<edge[x.to].size();i++)
        {
            P y=edge[x.to][i];
            if(dis[y.to]>dis[x.to]+y.cost)
            {
                dis[y.to]=dis[x.to]+y.cost;
                qu.push(P{y.to,dis[y.to]});
            }
        }
    }
}
 
struct node
{
    int to,len;
    bool operator < (const node & a) const
    {
        return len+dis[to]>a.len+dis[a.to];
    }
};
 
int A_star()
{//if(dis[1]==INF) return -1;�����������·ʱҪ���ϣ���Ȼ����ѭ����
    priority_queue<node> qu;
    qu.push(node{1,0});
    int num=0;
    while(!qu.empty())//����ط��е�������ζ������1��ʼ���ϼ������ڵĵ�ı�Ȩ��Ȼ�������С����Ǵ�1��ʼ������n��չ
    {
        node a=qu.top();
        qu.pop();
        if(a.to==n) num++;
        if(num==2) return a.len;
        for(int i=0;i<edge[a.to].size();i++)
        {
            P b=edge[a.to][i];
            qu.push(node{b.to,a.len+b.cost});//��b.to����㣬Ȼ��1��b.to�ľ������a.to�ľ������ab��ߵ�Ȩֵ��
        }
    }
    return -1;
}
 
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<=n;i++)
            edge[i].clear();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&val);
            edge[u].push_back(P{v,val});
            edge[v].push_back(P{u,val});
        }
        Dijkstra();
        printf("%d\n",A_star());
    }
    return 0;
}
