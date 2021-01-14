#include <iostream>
#include <string.h>
using namespace std;
int a[1000]; 
int length[1000]; 
int pre[1000]; 
int ans[1000]; 
int main()
{
	memset(a,0,sizeof(a));
	memset(length,0,sizeof(length));
	memset(pre,0,sizeof(pre));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		length[i]=1;
	}
	int l,k;
	for(int i=2;i<=n;i++)
	{
		l=0,k=0;
		for(int j=1;j<i;j++)
		{
			if((a[i]>=a[j])&&length[j]>l)
			{
				l=length[j];	
				k=j;	
			}
		}
		if(l>0)
		{
			length[i]=l+1;
			pre[i]=k;
		}
	}
	l=1;
	for(int i=1;i<=n;i++) if(length[i]>length[l]) l=i;
	cout<<"max="<<length[l]<<endl;
	k=1;
	while(l!=0)
	{
	ans[k++]=a[l];
	l=pre[l];
	}
	for(int i=k-1;i>=1;i--)
	{
	if(i!=k-1) cout<<" ";
	cout<<ans[i];
	}
	return 0;
}
