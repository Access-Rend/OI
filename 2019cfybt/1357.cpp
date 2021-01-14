#include<bits/stdc++.h>
using namespace std;
stack<int>p;
int s[1500];
int main()
{
    int n;
    scanf("%d",&n);
    int x;
    for(int i=1;i<=n;i++){
       scanf("%d",&s[i]);
    }
    for(int i=1,flag=1;i<=n;i++){
        while(flag<=s[i]){
            p.push(flag++);
        }
        if(p.top()==s[i]) p.pop();
        else{
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
