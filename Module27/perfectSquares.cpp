#include<bits/stdc++.h>

using namespace std;

int dp[100001],n;

int  f(int n)
{
    if(n==0)return 0;
    if(dp[n]!=100000)return dp[n];
    int  ans=100000;
    for (int i=1; i*i<=n; i++)
    {
        int j=i*i;
        if(n-j>=0)
        {
            ans=min(ans,1+f(n-j));
        }
    }
    return dp[n]=ans;
}

int main()
{
    cin>>n;
    for (int i=0; i<100001; i++)
    {
        dp[i]=100000;
    }
    int k=f(n);
    cout<<k;
    return 0;
}
