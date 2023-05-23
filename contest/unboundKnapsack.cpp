#include <bits/stdc++.h>

using namespace std;

int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector
<int>>& dp){

    if(ind == 0){
        return ((int)(W/wt[0])) * val[0];
    }

    if(dp[ind][W]!=-1)
        return dp[ind][W];

    int notTaken = 0 + knapsackUtil(wt,val,ind-1,W,dp);

    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt,val,ind,W-wt[ind],dp);

    return dp[ind][W] = max(notTaken,taken);
}


int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {

    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return knapsackUtil(wt, val, n-1, W, dp);
}

int main() {

    int n, cap, a;
    cin >> n >> cap;
    vector<int>val(n);
    vector<int>wt(n);
    for(int i=0 ; i<n ; i++)
    {
        cin>>a;
        val.push_back(a);
    }
    for(int i=0 ; i<n ; i++)
    {
        cin>>a;
        wt.push_back(a);
    }
  //vector<int> wt = {4,3,5,2,7};
  //vector<int> val = {3,4,5,2,10};
  //int W=10;

  //int n = wt.size();

  cout<<unboundedKnapsack(n,cap,val,wt);
}
