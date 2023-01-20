//
//  main.cpp
//  uva10015
//
//  Created by ray on 2020/10/5.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int pri[3555],num[100000]={0},pp=0,live[3502];
    num[1]=1;
    for(long long i=2;i<50000;i++)
    {
        if(num[i]==1)continue;
        for(long long j=i;(i*j)<=100000;j++)
        {
            num[i*j]=1;
        }
    }
    
    for(int i=1;i<=100000;i++)
    {
        if(pp>3503)break;
        if(num[i]==0)
        {
            pp++;
            pri[pp]=i;
        }
    }
    
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        int k=0;
        for(int i=1;i<n;i++)
        {
            k=(k+pri[n-i])%(i+1);
        }
        cout<<k+1<<endl;
    }
    
    
    
    
    return 0;
}
