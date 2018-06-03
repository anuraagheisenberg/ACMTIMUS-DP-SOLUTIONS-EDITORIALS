#include<bits/stdc++.h>
using namespace std;
typedef long long lll;
lll arr[300001];
lll segtree[1200004];
void update(lll node, lll start, lll end, lll idx, lll val)
{
    if(start == end)
    {
        arr[idx] = val;
        segtree[node] = val;
    }
    else
    {
        lll mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
    }
}
lll query(lll node, lll start, lll end, lll l, lll r)
{
    if(r < start or end < l)
        return 0;
    if(l <= start and end <= r)
        return segtree[node];
    lll mid = (start + end) / 2;
    return max(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}
int main()
{
    lll tt;
    cin >> tt;
    lll ans[tt];
    memset(ans, 0, sizeof(ans));
    memset(segtree, 0, sizeof(segtree));
    memset(arr, 0, sizeof(arr));
    vector<pair<lll, lll> > vecc;
    for(lll i = 0; i < tt; i++)
    {
        lll n1, n2;
        cin >> n1 >> n2;
        vecc.push_back({n1, n2});
    }
    sort(vecc.begin(), vecc.end());
    ans[0] = 1;
    update(1, 1, 300000, vecc[0].second, ans[0]);
    for(lll i = 1; i < tt; i++)
    {
        lll zz = query(1, 1, 300000, 1, vecc[i].first - 1);
        ans[i] = zz + 1;
        update(1, 1, 300000, vecc[i].second , ans[i]);
    }
/*
    taking the best out of the previous answers upto the given time
    and updating the end time of the event with the current answer 
*/
    cout << segtree[1] << endl;
    return 0;
}
