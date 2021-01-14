#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<string.h>
#include<map>
#include<set>
#include<sstream>
#include<algorithm>
#include<math.h>
using namespace std;
#define local
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6+10;
char Line[N],line1[N];
const int maxn=1e6+10;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
int n,m,x,y,z,res[N],p[N];
void manache(char *line)
{
	line1[0]='$';
	line1[1]='#';
	memset(res,0,sizeof res);
	int len=strlen(line);
	int k=2;
	for(int i=0;i<len;i++)
	{
		line1[k++]=line[i];
		line1[k++]='#';
	}
	line1[k]='\n';
	int mid=0,r=0;
	for(int i=1;i<k;i++){
		p[i]=r>i?min(p[2*mid-i],r-i):1;
		
		while(line1[i+p[i]]==line1[i-p[i]])
		{
			p[i]++;
		}
		if(i+p[i]>r)
		{
			r=i+p[i];
			m=i;
		}
		int l=(i-p[i]+1+i+1)/2;
		if(line1[i]=='#')
		rep(j,l,i-1)
		{
			if(j+p[j]-1>=i)
			{
				res[2*(i-j)]++;
			}
		}
		else
		{
			rep(j,l,i)
			{
				if(j+p[j]-1>=i)
				{
					res[2*(i-j)+1]++;
				}
			}	
		}
	}
}

int main(){
	freopen("in.txt","r",stdin);
//	char line;
	while(~scanf("%s",Line)){
		manache(Line);
		int len=strlen(Line);
		rep(i,1,len){
			if(i!=1)printf(" ");
			printf("%d",res[i]);
		}
		printf("\n");
	}
	return 0;
}

