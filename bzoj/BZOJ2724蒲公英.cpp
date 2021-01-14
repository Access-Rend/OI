#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define FOR(u,i) for(int i=head[u],v=E[head[u]].to;i;i=E[i].nxt,v=E[i].to)
const int N=5e5+10,inf=0x3f3f3f3f>>1;
int n,m,id,blo;
int v[N],bl[N];
int f[510][510];
map<int,int>mp;
int val[N],cnt[N];
vector<int>ve[N];
void ini(int x)
{
	memset(cnt,0,sizeof(cnt));
	int mx = 0,	res = 0;
	for(int i=(x-1)*blo+1;i<=n;i++)
	{
		cnt[v[i]]++;
		if(cnt[v[i]]>mx || (cnt[v[i]]==mx && val[v[i]]<val[res]))
			res = v[i],	mx = cnt[v[i]];
		f[x][bl[i]] = res;
	}
}
int query(int l,int r,int x){	return upper_bound(ve[x].begin(),ve[x].end(),r) - lower_bound(ve[x].begin(),ve[x].end(),l);	}
int query(int l,int r)
{
	int res,mx;
	res = f[bl[l] + 1][bl[r] - 1];
	mx = query(l,r,res);
	for(int i=l;i<=min(bl[l]*blo,r);i++)
	{
		static int t;	t = query(l,r,v[i]);
		if(t>mx || (t==mx && val[v[i]]<val[res]))	res = v[i],	mx = t;
	}
    if(bl[l]!=bl[r])
    	for(int i=(bl[r]-1)*blo+1;i<=r;i++)
        {
            int t=query(l,r,v[i]);
            if(t>mx||(t==mx&&val[v[i]]<val[res]))	res = v[i],	mx = t;
        }
    return res;
}
void solve()
{
	scanf("%d%d",&n,&m);
	blo = sqrt(n);
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		bl[i] = (i-1)/blo + 1;
		scanf("%d",&v[i]);
		if(!mp[v[i]])
		{
			mp[v[i]] = ++id;
			val[id] = v[i];
		}
		v[i] = mp[v[i]];
		ve[v[i]].push_back(i);
	}
	for(int i=1;i<=bl[n];i++)ini(i);
	for(int i=1;i<=m;i++)
	{
		static int a,b;scanf("%d%d",&a,&b);
		a = (a+ans-1)%n+1;b = (b+ans-1)%n+1;
		if(a>b)swap(a,b);
		ans = val[query(a,b)];
		printf("%d\n",ans);
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

