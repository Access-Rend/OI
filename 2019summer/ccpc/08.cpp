#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long n,u, a[N], b[N];
struct lyz {
    long long x, y;
} c[N];
long long ans[N];

bool cmp(lyz x, lyz y) { return x.x < y.x; }
void solve()
{
	memset(c,0,sizeof(c));memset(ans,0,sizeof(ans));
	cin >> n >> u;
    for (int i = 1; i <= n; i++) a[i] = u;
    for (int k = 1; k <= n; k++) scanf("%lld",&b[k]);
    for (int i = 1; i <= n; i++) {
        c[i].x = min(a[i], b[i]);
        c[i].y = i;
    }
    sort(c + 1, c + 1 + n, cmp);
    int t = 1, k = n;
    for (int i = 1; i <= n; i++) {
        if (c[i].x == a[c[i].y])
            ans[t++] = c[i].y;
        else
            ans[k--] = c[i].y;
    }
    k = 0, t = 0;
    for (int i = 1; i <= n; i++) {
        k += a[ans[i]];
        t = max(t, k);
        t += b[ans[i]];
    }
    cout << t << endl;
}
int main() {
    freopen("in.txt","r",stdin);
    int T;scanf("%d",&T);
    while(T--)solve();
    return 0;
}
