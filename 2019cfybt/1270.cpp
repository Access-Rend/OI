
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
struct ss
{
    int wi;//����
    int ci;//��ֵ
    int pi;//����
} dp[300];
int f[300];
int main ()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    int V,N;
   while(scanf("%d%d",&V,&N)!=EOF)
    {
        memset(f,0,sizeof(f));
        for(int i=1; i<=N; i++)
            scanf("%d%d%d",&dp[i].wi,&dp[i].ci,&dp[i].pi);
        for(int i=1; i<=N; i++)
        {
            if(dp[i].pi==1)//01����
            {
                for(int j=V; j>=dp[i].wi; j--)
                {
                    f[j]=max(f[j-dp[i].wi]+dp[i].ci,f[j]);
                }
 
            }
            else if(dp[i].pi==0)//��ȫ����
            {
                for(int j=dp[i].wi; j<=V; j++)
                {
                    f[j]=max(f[j-dp[i].wi]+dp[i].ci,f[j]);
                }
            }
            else//���ر���
            {
                for(int j=1; j<=dp[i].pi; j++)
                {
                    for(int k=V; k-j*dp[i].wi>=0; k--)
                    {
                        if(f[k-dp[i].wi]+dp[i].ci>f[k])
                            f[k]=f[k-dp[i].wi]+dp[i].ci;
                    }
                }
            }
 
        }
        printf("%d\n",f[V]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
