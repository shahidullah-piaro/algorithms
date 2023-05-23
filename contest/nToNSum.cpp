#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    int T;
    cin>> T;
    while(T--)
    {
        long num1, num2;
        cin>> num1 >> num2;
        int sum = 0;
        if(num1<num2)
        {
            for (int i = num1; i <= num2; i++)
            sum = sum + i;
        }
        else
        {
            for (int i = num2; i <= num1; i++)
            sum = sum + i;
        }
        cout << sum <<endl;
    }
    return 0;
}
