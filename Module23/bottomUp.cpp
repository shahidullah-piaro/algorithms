#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int countt = 1;
    while (n > 1)
    {
        n = n-1;
        if (n % 2 == 0)
            n = n / 2;
        else if(n % 3 == 0)
            n = n / 3;
        countt++;
    };
    cout<<countt<<endl;
    return 0;
}

