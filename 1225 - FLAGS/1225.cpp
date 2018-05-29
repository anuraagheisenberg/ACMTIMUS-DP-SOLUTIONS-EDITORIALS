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
    dp[i][1] = dp[i - 1][3] + dp[i - 2][3];
    // Total number of sequence of length l which ends with red will be;
    // The total number of sequences with length l - 1 which ends with white sum;
    // total number of sequence of length l - 2 which ends with white;
    // valid sequence for length 1 - W , R
    // valid sequence for length 2 - WR (if seq ends with R then l-1 ending with W), RW (if seq ends with W then l-1 ending with R)
    // valid sequence for length 3
    // WRW (if seq ends with W then l-1 ending with W)
    // WBR (if seq ends with R then l-2 ending with W)
    // RBW (if seq ends with R then l-2 ending with R)
    // RWR (if seq ends with R then l-1 ending with W)
    dp[i][3] = dp[i - 1][1] + dp[i - 2][1];
  }
  lll nn;

  cin >> nn;
  cout << dp[nn][1] + dp[nn][3] << endl;
  return 0;
}
