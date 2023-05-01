#include<bits/stdc++.h>
using namespace std;

int tribonacci(int n)
{
    if (n <= 2) return n == 0 ? 0 : 1;
    int a = 0, b = 1, c = 1, res;
    for (int i = 3; i <= n; i++)
    {
        res = a + b + c;
        a = b;
        b = c;
        c = res;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    cout<<tribonacci(n)<<endl;
    return 0;
}

