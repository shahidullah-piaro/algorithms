//https://www.spoj.com/problems/FARIDA/en/
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
typedef long long int ll;
typedef vector<long long int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    ll k=1;
    while(t--)
    {
        ll dp[10000];
        dp[0]=0;
        ll n;
        cin>>n;
        if(n==0)
        {
            cout<<"Case "<<k++<<": "<<0<<endl;
            continue;
        }
        if(n==1)
        {
            ll x;
            cin>>x;
            cout<<"Case "<<k++<<": "<<x<<endl;
            continue;
        }
        cin>>dp[1]>>dp[2];
        dp[2]=max(dp[1],dp[2]);
        for(int i=3;i<=n;i++)
        {
            ll x;
            cin>>x;
            dp[i]=max(x+dp[i-2],dp[i-1]);
        }
        cout<<"Case "<<k++<<": "<<dp[n]<<endl;
    }
    return 0;
}
