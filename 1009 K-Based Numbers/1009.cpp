#include<bits/stdc++.h>
using namespace std;
typedef long long lll;
lll n, k;
lll dp[17][2];
/* Dp will contain 2 states , if the last digit is 0 or not and the number
    of digits remaining */
lll recurse(lll ld, lll rem)
{
    if(rem == 0)
        return 1;
    if(ld == 0 and dp[rem][0] != -1)
        return dp[rem][0];
    if(ld != 0 and dp[rem][1] != -1)
        return dp[rem][1];
    lll ans = 0;
    for(lll i = 0; i < k; i++)
    {
        if(ld == 0 and i == 0)
            continue;
        ans += recurse(i, rem - 1);
    }
    if(ld == 0)
        return dp[rem][0] = ans;
    else
        return dp[rem][1] = ans;
}
int main()
{
    ios::sync_with_stdio(false);
    for(lll i = 0; i <= 1; i++)
        for(lll j = 0; j < 17; j++)
            dp[j][i] = -1;
    cin >> n >> k;
    lll ans = 0;
    for(lll i = 1; i < k; i++)
    {
        ans += recurse(i, n - 1);
    }
    cout << ans << endl;
    return 0;
}
