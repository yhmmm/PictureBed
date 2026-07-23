#include<bits/stdc++.h>
using namespace std;

const long long N = 5e5 + 5;
long long a[N], b[N], sum[N << 2], num = 0;
long long lc[N << 2], rc[N << 2];
#define ls lc[pos]
#define rs rc[pos]
#define mid ((l + r) >> 1)

void pushup(long long pos)
{
    sum[pos] = sum[ls] + sum[rs];
}

void update (long long &pos, long long l, long long r, int qpos, int val)
{
    if(!pos)
    {
        pos = ++num;
    }
    if(l == r)
    {
        sum[pos] += val;
        return; 
    }
    if(qpos <= mid)
        update(ls, l, mid, qpos, val);
    else
        update(rs, mid + 1, r, qpos, val);
    pushup(pos);
}

long long query(long long pos, long long l, long long r, long long ql)
{
    if(!pos) return 0; 
    if(ql <= l) return sum[pos]; 
    long long res = 0;
    if(ql <= mid) res += query(ls, l, mid, ql);
    res += query(rs, mid+1, r, ql); 
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i]; 
    }
    sort(b + 1, b + n + 1);
    auto k = unique(b + 1, b + n + 1);
    long long lim = k - (b + 1);
    
    long long rt = 0; 
    long long ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        int x = lower_bound(b + 1, k, a[i]) - b;
        ans += query(rt, 1, lim, x + 1);
        update(rt, 1, lim, x, 1);
    }
    cout << ans << endl;
    return 0;
}