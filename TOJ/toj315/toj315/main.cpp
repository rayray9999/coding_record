//
//  main.cpp
//  toj315
//
//  Created by ray on 2018/12/14.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    
    __uint128_t a ,b ,m ;
    long long t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        long long j,q,l;
        __uint128_t an=1,k;
        unsigned long long ak;
        cin>>j>>q>>l;
        a=j;
        b=q;
        m=l;
        a=a%m;
        k=a;
        while(b>0)
        {
            if(b%2!=0)
            {
                an=(an*k)%m;
            }
            
            k=(k*k)%m;
            b=b/2;
        }
        ak=an;
        cout<<ak<<endl;
    }
    
    
    return 0;
}
