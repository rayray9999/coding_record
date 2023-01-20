//
//  main.cpp
//  uva10474
//
//  Created by ray on 2020/11/14.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <memory.h>
using namespace std;
int main(int argc, const char * argv[])
{
    int arr[10005]={0},n,x,cas=1,ask[10005]={0},list[10005],ans[10005];
    while(cin>>n>>x)
    {
        memset(list,0,sizeof(list));
        memset(ans,0,sizeof(ans));
        if(n==0&&x==0)break;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        
        for(int i=0;i<x;i++)
        {
            cin>>ask[i];
            list[ask[i]]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(list[arr[i]]==1&&ans[arr[i]]==0)
            {
                ans[arr[i]]=i+1;
            }
        }
        cout<<"CASE# "<<cas<<":"<<endl;
        cas++;
        for(int i=0;i<x;i++)
        {
            if(ans[ask[i]]!=0)
            {
                cout<<ask[i]<<" found at "<<ans[ask[i]]<<endl;
            }
            else
            {
                cout<<ask[i]<<" not found"<<endl;
            }
        }
    }
    
    return 0;
}
