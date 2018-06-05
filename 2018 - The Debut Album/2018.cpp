#include<bits/stdc++.h>
using namespace std;
typedef long long lll;
lll n, k, m;
lll dp[50001][2];
int main()
{
    /*
    from each index we will satart and form numbers and add the answer
    like from ith index we will go on and do 1, 11, 111, 1111 , and length
    l+1, l+2 , l+3, l+4 will have dp += dp of 0 at length l
    */
    ios::sync_with_stdio(false);
    memset(dp,0,sizeof(dp));
    cin >> n >> k >> m;
    lll ans = 0;
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(lll i = 0; i < n; i++)
    {
        for(lll j = 1; j <= k and i + j <= n; j++)
            dp[i + j][0] = (dp[i + j][0] + dp[i][1]) % 1000000007 ;
        for(lll p = 1; p <= m and i + p <= n; p++)
            dp[i + p][1] = (dp[i + p][1] + dp[i][0]) % 1000000007 ;
    }
    cout << (dp[n][0] + dp[n][1]) % 1000000007 << endl;
    return 0;
}
