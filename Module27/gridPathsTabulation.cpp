#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main()
{
    int n;
    cin>>n;
    char a[n+1][n+1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin>>a[i][j];
        }
    }
    int dp[n+1][n+1];

    for (int i = 1; i <= n+1; ++i)
    {
        for (int j = 1; j <= n+1; ++j)
        {
            dp[i][j] = 0;
        }
    }
    if(a[n][n]!='*')
        dp[n][n] = 1;
    for (int i = n; i != 0; i--)
    {
        for (int j = n; j != 0; j--)
        {
            if(a[i][j] == '*')
            {
                dp[i][j] = 0;
            }
            else
            {
                if(i == n and j == n)
                    continue;
                dp[i][j] += (dp[i+1][j])%MOD + (dp[i][j+1])%MOD;
            }
        }
    }

    cout<<dp[1][1];
    return 0;
}
