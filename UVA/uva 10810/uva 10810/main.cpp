//
//  main.cpp
//  uva 10810
//
//  Created by ray on 2021/1/13.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <stdio.h>
using namespace std;
int bit[500005]={0},u[500005]={0},g[500005]={0};
void add(int i,int len)
{
    while(i<=len)
    {
        bit[i]++;
        i+=i&-i;
    }
}
long long sum(int i)
{
    long long s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
int main(int argc, const char * argv[])
{
    int k,len;
    while(cin>>len)
    {
        if(len==0)break;
        memset(bit,0,sizeof(bit));
        memset(u,0,sizeof(u));
        memset(g,0,sizeof(g));
        for(int i=0;i<len;i++)
        {
            cin>>g[i];
            u[i]=g[i];
        }
        sort(u,u+len);
        int l=unique(u,u+len)-u;
        for(int i=0;i<len;i++)
        g[i]=lower_bound(u,u+l,g[i])-u+1;
        long long ans=0;
        for(long long i=0;i<len;i++)
        {
            add(g[i],len);
            ans+=(i+1-sum(g[i]));
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
