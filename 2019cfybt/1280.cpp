#include<iostream>
using namespace std;
int i,n,m,j,mmax,a[110][110],f[110][110],p[110][110];
int dfs(int x,int y)
{
	if(x>n)return -1;
	if(x<1)return -1;
	if(y>m)return -1;
	if(y<1)return -1;
	if(p[x][y])return f[x][y];
	p[x][y]++;
	f[x][y]=1;
	if(a[x][y]>a[x+1][y])
		f[x][y]=f[x][y]>(dfs(x+1,y)+1)?f[x][y]:(dfs(x+1,y)+1);
	if(a[x][y]>a[x-1][y])
		f[x][y]=f[x][y]>(dfs(x-1,y)+1)?f[x][y]:(dfs(x-1,y)+1);
	if(a[x][y]>a[x][y+1])
		f[x][y]=f[x][y]>(dfs(x,y+1)+1)?f[x][y]:(dfs(x,y+1)+1);
	if(a[x][y]>a[x][y-1])
		f[x][y]=f[x][y]>(dfs(x,y-1)+1)?f[x][y]:(dfs(x,y-1)+1);
	return f[x][y];
}
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)
	    for(j=1;j<=m;j++)
	        cin>>a[i][j];
	for(i=1;i<=n;i++)
	    for(j=1;j<=m;j++)
	        mmax=mmax>dfs(i,j)?mmax:dfs(i,j);
	cout<<mmax;
	return 0;
}
