#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int K = 1000;

int val[N],wt[N];

int unboundedKnapsack(int W, int wt[], int val[], int idx)
{
    if (idx == 0) {
        return (W / wt[0]) * val[0];
    }

    int notTake
        = 0 + unboundedKnapsack(W, wt, val, idx - 1);

    int take = INT_MIN;
    if (wt[idx] <= W) {
        take = val[idx]
            + unboundedKnapsack(W - wt[idx], wt, val,
                                idx);
    }
    return max(take, notTake);
}

int main()
{
    int n, cap;
    cin>>n>>cap;
    for(int i=0;i<n;i++)
        cin>>val[i];
    for(int i=0;i<n;i++)
        cin>>wt[i];

    cout << unboundedKnapsack(cap, wt, val, n-1);
    return 0;
}
