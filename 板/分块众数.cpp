#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=1e5+10,inf=0x3f3f3f3f>>1;
int n,m,id,block;
int a[N],bl[N];
map<int,int>mp;
int val[N],cnt[N];
int f[510][510];
vector<int>vec[N];
void ini(int x)//cnt just be used in here 
{
	memset(cnt,0,sizeof(cnt));
	int num = 0,	tm = 0;
	for(int i=(x-1)*block+1;i<=n;i++)
	{
		cnt[a[i]]++;
		if(cnt[a[i]]>tm || (cnt[a[i]]==tm && val[a[i]]<val[num]))
			num = a[i],	tm = cnt[a[i]];
		f[x][bl[i]] = num;
	}
}
int query(int l,int r,int x)//x's times
{
	return upper_bound(vec[x].begin(),vec[x].end(),r)
		-	lower_bound(vec[x].begin(),vec[x].end(),l);
}
//summary: maxtime_num must in whole blocks or in the tail&head 
int query(int l,int r)//maxtime num
{
	int num,tm;
	num = f[bl[l]+1][bl[r]-1];	tm = query(l,r,num);
	for(int i=l;i<=min(r,bl[l]*block);i++)
	{
		static int t;	t = query(l,r,a[i]);
		if(t>tm || (t==tm && val[a[i]] < val[num]))	num = a[i],	tm = t;
	}
	if(bl[l]!=bl[r])
		for(int i=(bl[r]-1)*block+1;i<=r;i++)
		{
			int t = query(l,r,a[i]);
			if(t>tm || (t==tm && val[a[i]] < val[num]))	num = a[i],	tm = t;
		}
	return tm;//can be returned num or tm
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		bl[i] = (i-1)/block + 1; 
		scanf("%d",&a[i]);
		if(!mp[a[i]])
		{
			mp[a[i]] = ++id;
			val[id] = a[i];
		}
		a[i] = mp[a[i]];
		vec[a[i]].push_back(i);
	}
	for(int i=1;i<=bl[n];i++)ini(i);
	for(int i=1;i<=m;i++)
	{
		static int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

