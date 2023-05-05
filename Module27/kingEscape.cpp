#include<bits/stdc++.h>
using namespace std;

int n, a1, a2, b1, b2, t1, t2;

main(){
    cin>>n;

    cin>>a1>>a2>>b1>>b2>>t1>>t2;
    int flag= 0;

    if((b1<a1 && t1<a1) || (b1>a1 && t1>a1)){

        if((b2<a2 && t2<a2) || (b2>a2 && t2>a2))
            flag= 1;
    }

    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
