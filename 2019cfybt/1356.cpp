#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long ans;
int  number[1010],i,pd,len,x,tot,j,l,n,yx[60];
char symbol[1010],s[1010];
void init()//Ԥ����ÿ������������ȼ�
{
       int m;
       m='^';
       yx[m-40]=3;
       m='*';
       yx[m-40]=2;
       m='/';
       yx[m-40]=2;
       m='+';
       yx[m-40]=1;
       m='-';
       yx[m-40]=1;
       m='(';//��������С����Ϊ�����ź�����������Ҫֱ����ջ
       yx[m]=0;
}
int mys()//������
{
       int m,ans=1;
       for(m=1;m<=number[n];m++)
         ans*=number[n-1];
       return ans;
}
void khcl()//��ջ��������Ԫ�ص������������ѹ��ջ��
{
       switch(symbol[tot])
        {
             case'+':number[n-1]+=number[n];break;
             case'-':number[n-1]-=number[n];break;
             case'*':number[n-1]*=number[n];break;
             case'/':number[n-1]/=number[n];break;
             case'^':number[n-1]=mys();break;
        }
        tot--;
        n--;
}
int main()
{
       //freopen("calc.in","r",stdin);
       //freopen("calc.out","w",stdout);
       scanf("%s",s);
       len=strlen(s);
       i=0;
       init();
       if(s[0]=='-')
         {
             n++;
             number[n]=0;
         }
       while(i<len)
       {
              x=0;
              pd=0;
              while(s[i]>=48&&s[i]<=57)//�������֣�����ջ��
              {
                x=x*10+s[i++]-48;
                pd=1;
           }
           if (pd==1)
             {
                 n++;
                 number[n]=x;
             }
              while(s[i]=='(')//������ֱ����ջ
                {
                    i++;
                    tot++;
                    symbol[tot]='(';
                }
              if(s[i]==')')//���������ż��������е�ֵ
                {
                    while(symbol[tot]!='(')
                      khcl();
                    tot--;//�����ų�ջ
                    i++;
                }
              else
               if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
               {
                    j=s[i];
                    l=symbol[tot];
                    if(yx[j-40]>yx[l-40])//��ǰ�������ȼ�����ջ��Ԫ�����ȼ���ֱ����ջ
                      {
                          tot++;
                          symbol[tot]=s[i];
                      }
                    else
                    {
                      while (yx[j-40]<=yx[l-40])//�������֮ǰ�������ȼ����ڵ��ڵ�ǰ���ŵ������
                       {
                         khcl();
                         l=symbol[tot];
                       }
                    tot++;
                      symbol[tot]=s[i];
                  }
                    i++;
               }
       }
       while(tot>0)//�ж�ջ�Ƿ�Ϊ�գ�����Ϊ�ռ�������
        khcl();
       printf("%d",number[1]);
       return 0;
}
