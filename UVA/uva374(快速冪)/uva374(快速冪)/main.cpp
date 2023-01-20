//
//  main.cpp
//  uva374(快速冪)
//
//  Created by ray on 2019/1/28.
//  Copyright © 2019年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
long long mi(long long b,long long p,int mod)
{
    long long k=1;
    while(p!=0)
    {
        if(p%2!=0)
        {
            k=(k%mod)*b%mod;
        }
        p=p/2;
        b=(b%mod*b%mod)%mod;
    }
    
    return k;
}
int main(int argc, const char * argv[])
{
    long long a,b,c;
    while(cin>>a>>b>>c)
    {
        cout<<mi(a,b,c)<<endl;
    }
    return 0;
}
