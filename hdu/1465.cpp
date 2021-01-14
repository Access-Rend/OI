/*
二项式反演公式： 
f(n)=ΣC(n, i)*g(i)
g(n)=Σ(-1)^(n-i)C(n, i)*f(i)

g(i)为恰好有i封信装错 
全部的C(n, i)*g(i)加起来正好就是所有装信的情况
总共n!种情况
于是有n! = ΣC(n, i)*g(i) (i从0到n)

反演:
在这里,f(i)即等式右边阶乘i! 
g(n)=Σ(-1)^(n-i)C(n, i)*f(i)
	=Σ(-1)^(n-i)C(n, i)*i!
q(n)即为题意所求 
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,f[30];
void ini()
{
	f[0]=1;
	for(int i=1;i<=20;i++)f[i]=f[i-1]*i;
}

void cal()
{
	long long ans=0;
	int k= (n&1)?-1:1; 
	for(int i=0;i<=n;i++)
		{
			ans += k*f[n]/f[n-i],k=-k;
		}
	printf("%lld\n",ans);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ini();
	while(~scanf("%d",&n))
	cal();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

