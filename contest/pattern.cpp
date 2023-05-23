#include <iostream>
using namespace std;
int main()
{
    int i,j,N;
    cin >> N;
    for(i=0; i<=N; i++)
    {
        for(j=1; j<=N-i; j++)
            cout<<" ";
        if(i%2!=0)
        {
            for(j=1; j<=2*i-1; j++)
                cout<<">";
        }
        else
        {
            for(j=1; j<=2*i-1; j++)
                cout<<"<";
        }
        cout<<endl;
    }
    for(i=N-1; i>=1; i--)
    {
        for(j=1; j<=N-i; j++)
            cout<<" ";
        if(i%2!=0)
        {
            for(j=1; j<=2*i-1; j++)
                cout<<">";
        }
        else
        {
            for(j=1; j<=2*i-1; j++)
                cout<<"<";
        }
        cout<<endl;;
    }
    return 0;
}
