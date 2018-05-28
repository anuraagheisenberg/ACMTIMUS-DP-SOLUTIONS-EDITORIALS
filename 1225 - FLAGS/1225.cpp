#include<bits/stdc++.h>
using namespace std;
typedef long long lll;
int main()
{
  lll dp[46][4];
  memset(dp, 0, sizeof(dp));
  // Let us consider a state where a number can be formed of length L and symbol l(color)
  dp[1][1] = 1;
  dp[1][3] = 1;
  // 1 represents color white and 3 represents color red;
  for(lll i = 2; i <= 45; i++)
  {
    dp[i][1] = dp[i - 1][3] + dp[i - 2][1];
    // Total number of seqence of length l which ends with red is
    // th total number of sequence of length l - 2 which ends with blue;
    dp[i][3] = dp[i - 1][1] + dp[i - 2][3];
  }
  lll nn;

  cin >> nn;
  cout << dp[nn][1] + dp[nn][3] << endl;
  return 0;
}
