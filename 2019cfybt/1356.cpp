#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long ans;
int  number[1010],i,pd,len,x,tot,j,l,n,yx[60];
char symbol[1010],s[1010];
void init()//预处理每种运算符的优先级
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
       m='(';//左括号最小，因为左括号后面的运算符需要直接入栈
       yx[m]=0;
}
int mys()//幂运算
{
       int m,ans=1;
       for(m=1;m<=number[n];m++)
         ans*=number[n-1];
       return ans;
}
void khcl()//将栈顶的两个元素弹出计算后重新压入栈中
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
              while(s[i]>=48&&s[i]<=57)//处理数字，加入栈中
              {
                x=x*10+s[i++]-48;
                pd=1;
           }
           if (pd==1)
             {
                 n++;
                 number[n]=x;
             }
              while(s[i]=='(')//左括号直接入栈
                {
                    i++;
                    tot++;
                    symbol[tot]='(';
                }
              if(s[i]==')')//遇到右括号计算括号中的值
                {
                    while(symbol[tot]!='(')
                      khcl();
                    tot--;//左括号出栈
                    i++;
                }
              else
               if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
               {
                    j=s[i];
                    l=symbol[tot];
                    if(yx[j-40]>yx[l-40])//当前符号优先级大于栈顶元素优先级，直接入栈
                      {
                          tot++;
                          symbol[tot]=s[i];
                      }
                    else
                    {
                      while (yx[j-40]<=yx[l-40])//否则计算之前所有优先级大于等于当前符号的运算符
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
       while(tot>0)//判断栈是否为空，若不为空继续计算
        khcl();
       printf("%d",number[1]);
       return 0;
}
