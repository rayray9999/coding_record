//
//  main.cpp
//  toj332
//
//  Created by ray on 2018/12/10.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    long long m,n,sun=1,sum=1;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        long long k;
        cin>>k;
        sum=(sum*k%100000007+100000007)%100000007;
    }
    for(int i=1;i<=n;i++)
    {
        long long k;
        cin>>k;
        sun=(sun*k%100000007+100000007)%100000007;
    }
    long long nn=1,mm=1;
    while(n>0)
    {
        if(n%2!=0)
        {
            mm=mm*sum%100000007;
        }
        n=n/2;
        sum=sum*sum%100000007;
    }
    while(m>0)
    {
        if(m%2!=0)
        {
            nn=nn*sun%100000007;
        }
        m=m/2;
        sun=sun*sun%100000007;
    }
    cout<<(nn*mm%100000007+100000007)%100000007<<endl;
    
    return 0;
}

