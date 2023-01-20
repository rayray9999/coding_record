//
//  main.cpp
//  toj441
//
//  Created by 端木竣偉 on 2018/11/22.
//  Copyright © 2018年 端木竣偉. All rights reserved.
//

#include <iostream>
using namespace std;
long long p=1000000007;
long long mi(long long b)
{
    int wo=p-2,an=1;
    while(wo>0)
    {
        if(wo%2!=0)
        {
            an=b*an%p;
        }
        b=b*b%p;
        wo=wo/2;
    }
    return an;
}
int main(int argc, const char * argv[])
{
    long long mo=1,so,n,m,goo,d,nn,mm;
    cin>>n>>m;
    for(long long i=1;i<=n+m;i++)
    {
        mo=mo*i%p;
        if(i==n)
        {
            nn=mo;
        }
        if(i==(m-1))
        {
            
                mm=mo;
        }
    }
    if(m==1)
    {
        mm=1;
    }
    so=nn*(mm*m%p)%p;
    goo=mo*mi(so)%p;
    so=(nn*(n+1)%p)*mm%p;
    d=mo*mi(so)%p;
    cout<<(goo-d+p)%p<<endl;
    return 0;
}
