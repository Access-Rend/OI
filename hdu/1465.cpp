/*
����ʽ���ݹ�ʽ�� 
f(n)=��C(n, i)*g(i)
g(n)=��(-1)^(n-i)C(n, i)*f(i)

g(i)Ϊǡ����i����װ�� 
ȫ����C(n, i)*g(i)���������þ�������װ�ŵ����
�ܹ�n!�����
������n! = ��C(n, i)*g(i) (i��0��n)

����:
������,f(i)����ʽ�ұ߽׳�i! 
g(n)=��(-1)^(n-i)C(n, i)*f(i)
	=��(-1)^(n-i)C(n, i)*i!
q(n)��Ϊ�������� 
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

