#include<bits/stdc++.h>
using namespace std;
typedef long long lll;
int main()
{
	lll n, mmm = -10e17, flag = 0;
	cin >> n;
	lll arr[n + 1][n + 1];
	memset(arr, 0, sizeof(arr));
	for(lll i = 1; i <= n; i++)
	{
		for(lll j = 1; j <= n; j++)
			{
			cin >> arr[i][j];
      		if(arr[i][j] > 0 and flag == 0)
        		flag = 1;
      		mmm = max(mmm,arr[i][j]);
    		}
    }
  if(flag == 0)
  {
    cout<<mmm<<endl;
    return 0;
  }	
	lll cumsum[n + 1][n + 1];
	memset(cumsum, 0, sizeof(cumsum));
	for(lll i = 1; i <= n; i++)
	{
		lll ss = 0;
		for(lll j = 1; j <= n; j++)
		{
			ss += arr[i][j];
			cumsum[i][j] = ss;
		}
	}
	lll ans = -10e17;
	for(lll i = 1; i <= n; i++)
	{
		for(lll j = i; j <= n; j++)
		{
			lll arr2[n + 1];
			for(lll k = 1; k <= n; k++)
			{
				arr2[k] = cumsum[k][j] - cumsum[k][i - 1]; 

			}

			lll cumsumm = 0;
			lll maxtillnow = 0;
			for(lll k = 1; k <= n ; k++)
			{
				cumsumm += arr2[k];
				if(cumsumm <= 0)
					{
						cumsumm = 0;
					}
				else if(cumsumm > maxtillnow)
					{
						maxtillnow = cumsumm;
					}
			}
			ans = max(ans, maxtillnow);
		}
	}
	cout << ans << endl;
	return 0;
}
