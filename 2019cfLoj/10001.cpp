//2018-07-27 20:59:54
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 300001;
int n, h;
struct node{
    int st, ed, v;
}a[5001];

int ans, k, used[N];

bool cmp(node a, node b){
    return a.ed < b.ed;
}

int main(){
    scanf("%d%d", &n, &h);
    for(int i=1; i<=h; i++)
        scanf("%d%d%d", &a[i].st, &a[i].ed, &a[i].v);
    sort(a+1, a+h+1, cmp);
    
    for(int i=1; i<=h; i++){
        k = 0;
        for(int j=a[i].st; j<=a[i].ed; j++){
            if(used[j]) k++; 
        }
        if(k >= a[i].v) continue;
        for(int j=a[i].ed; j>=a[i].st; j--){
            if(!used[j]){
                used[j] = 1;
                k++;
                ans++;
                if(k >= a[i].v) break;
            }
        }
    }
        
    printf("%d\n", ans);

    return 0;
}
