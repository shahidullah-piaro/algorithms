#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll isSafe(ll n, ll m, ll r, ll c, vector < vector < ll > >& matrix, vector < vector < ll > >&vis) {
    if(r >= 0 and r < n and c >=0 and c < m) {
        return (matrix[r][c] and !vis[r][c]);
    }
    else
        return 0;
}
ll traverse(ll n, ll m, ll r, ll c, vector < vector < ll > >&matrix, vector < vector < ll > >&vis) {
    static ll ro[4] = {-1,1,0,0};
    static ll co[4] = {0,0,-1,1};
    ll sum = 0;
    for(ll k = 0 ; k < 4; k++) {

        if(isSafe(n,m,r+ro[k],c+co[k],matrix,vis)) {
            vis[r+ro[k]][c+co[k]] = 1;
            sum += matrix[r+ro[k]][c+co[k]]+traverse(n,m,r+ro[k],c+co[k],matrix,vis);
        }
    }
    return sum;
}
int main()
{
    ll t;
    cin>>t;

    while(t--) {
        ll n,m,cell,maxi = 0;
        cin>>n>>m;
        vector < vector < ll > > matrix;
        vector<vector<ll>> vis(n, vector<ll> (m, 0));
        for(ll i = 0; i < n ; i++) {
            vector < ll > row;
            for(ll j = 0 ; j < m ; j++) {
                cin>>cell;
                row.push_back(cell);
            }
            matrix.push_back(row);
        }
        for(ll i = 0 ; i < n; i++) {
            for(ll j = 0 ; j < m ; j++) {

                if(matrix[i][j]!=0 and !vis[i][j]) {
                    vis[i][j] = 1;
                    ll value = traverse(n,m,i,j,matrix,vis)+matrix[i][j];
                    maxi = max(maxi,value);
                }
            }
        }
        cout<<maxi<<endl;
    }
    return 0;
 }
