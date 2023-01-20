//
//  main.cpp
//  toj80
//
//  Created by 端木竣偉 on 2018/12/5.
//  Copyright © 2018年 端木竣偉. All rights reserved.
//

#include <iostream>
using namespace std;
int d[1005][1005],arr[1005];
int a;
int dp(int fi,int en)
{
    if(fi==en)
    {
        if(a%2!=0)
        {
            return arr[fi];
        }
        else
        {
            return 0;
        }
    }
    
    if(d[fi][en]!=0)
    {
        return d[fi][en];
    }
    else
    {
        if(a-(en-fi)%2==0)
        {
            if(d[fi][en]!=0)
            {
                d[fi][en]=min({dp(fi+1,en)+arr[fi],dp(fi,en-1)+arr[en],d[fi][en]});
            }
            else
            {
                d[fi][en]=min(dp(fi+1,en)+arr[fi],dp(fi,en+1)+arr[en]);
            }
            return d[fi][en];
        }
        else
        {
            
                d[fi][en]=max({dp(fi+1,en)+arr[fi],dp(fi,en-1)+arr[en],d[fi][en]});
            return d[fi][en];
        }
    }
    
    
}
int main(int argc, const char * argv[])
{
    int sum=0;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
        int t;
        cin>>t;
        arr[i]=t;
        sum=sum+t;
    }
    cout<<dp(1,a)<<" "<<sum-dp(1,a)<<endl;
    return 0;
}
