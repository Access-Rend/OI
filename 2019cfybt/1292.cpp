#include<bits/stdc++.h>
using namespace std ; 
int n , m , k ; 
int num[105][2] ; 
int dp[1005][505] ; 
int main(){
    while(~scanf("%d%d%d" , &n , &m , &k)){
        memset(dp , 0 , sizeof(dp)) ; 
        
        for(int i=1 ; i<=k ; i++){
            scanf("%d%d" , &num[i][0] , &num[i][1]) ; 
        } 

        for(int i=1 ; i<=k ; i++){
            for(int j=n ; j>=num[i][0] ; j--){
                for(int t = m ; t>=num[i][1] ; t--){
                    dp[j][t] = max(dp[j][t] , dp[j-num[i][0]][t-num[i][1]] + 1 ) ; 
                }
            }
        } 

        int min_num = 0 ; 
        for(int i=0 ; i<=m ; i++){
            if(dp[n][i] == dp[n][m]){
                min_num = i ; 
                break ; 
            }
        } 

        printf("%d %d\n" , dp[n][m] , m - min_num) ; 
        
        
    }
    return 0 ; 
}
