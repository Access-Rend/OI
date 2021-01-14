#include<bits/stdc++.h>
using namespace std;
int main()
{ 
	int n,i,j,a[1001]={0},b[4]={10,20,50,100};
	cin>>n;
	a[0]=1;
	if(n%10!=0||n==0){cout<<0<<endl;return 0;}

	for(i=0;i<4;++i)
	for(j=10;j<=n;j+=10)
	{
		if(j-b[i]>=0)
		a[j]+=a[j-b[i]];
	}
	cout<<a[n]<<endl;
	return 0;
}
