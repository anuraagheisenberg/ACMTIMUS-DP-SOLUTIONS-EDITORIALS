#include<bits/stdc++.h>
using namespace std;
typedef long long lll;
int main()
{
	// easiest question of the the problem set
	lll n,m;
	cin >> n >> m;
	lll dp1[n + 1][m + 1];
	double ans[n + 1][m + 1];
	lll kk;
	memset(dp1,0,sizeof(dp1));
	memset(ans,0,sizeof(ans));
	cin >> kk;
	for(lll i = 0; i < kk; i++)
		{
			lll e, q;
			cin >> e >> q;
			dp1[e - 1][q - 1] = 1;
		}
	for(lll i = 0; i <= n; i++)
		{
			for(lll j = 0; j <= m; j++)
				{
					if(dp1[i - 1][j - 1] == 1)
							ans[i][j] = ans[i - 1][j - 1] + sqrt(2);
					else
						{
							if(i - 1 >= 0 and j - 1 >= 0)
								ans[i][j] = min(ans[i - 1][j], ans[i][j-1]) + 1;
							else if(i - 1 >= 0)
								ans[i][j] = ans[i - 1][j] + 1;
							else if(j - 1 >= 0)
								ans[i][j] = ans[i][j - 1] + 1;
							else
								ans[i][j] = 0;
						}
				}
		}

	cout << round(ans[n][m] * 100) << endl;
	return 0;
}
