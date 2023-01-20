//
//  main.cpp
//  toj348
//
//  Created by ray on 2018/12/9.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int gcd(long long a,long long b)
{
    if(a>b)
    {
        swap(a,b);
    }
    b=b%a;
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a);
    }
}

int main(int argc, const char * argv[])
{
    int n;
    while(cin>>n)
    {
        if(n==2)
        {
            long long a,b;
            cin>>a>>b;
            cout<<a*b/gcd(a,b)<<"\n";
        }
        else
        {
            long long a,b,c;
            cin>>a>>b>>c;
            a=a*b/gcd(a,b);
            cout<<a*c/gcd(a,c)<<"\n";
        }
    }
    
    return 0;
}
