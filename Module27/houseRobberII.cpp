class Solution {
public:
int f(int i, vector<int>& v, vector<int>& dp){
    if(i==0){return v[0];}
    if(i<0){return 0;}
    if(dp[i]!=-1){return dp[i];}
    int rb=v[i]+f(i-2, v, dp);
    int nrb=f(i-1, v, dp);
    return dp[i]=max(rb, nrb);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return nums[0];}
        vector<int>v1(nums.begin(), nums.begin()+nums.size()-1), v2(nums.begin()+1, nums.end());
        vector<int>dp1(n-1, -1), dp2(n-1, -1);
        return max(f(n-2, v1, dp1), f(n-2, v2, dp2));
    }
};
