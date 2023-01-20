//
//  main.cpp
//  toj369
//
//  Created by ray on 2018/12/9.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int li[100005],ma[100005],dp[100005];
int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    while(cin>>a)
    {
        memset(dp,-1,sizeof(dp));
        for (int i=1;i<=a;i++)
        {
            int k;
            cin>>k;
            li[k+1]=i;
        }
        for(int i=1;i<=a;i++)
        {
            int k;
            cin>>k;
            ma[i]=li[k+1];
        }
        dp[0]=0;
        int sum=0;
        for(int i=1;i<=a;i++)
        {
            for(int j=sum;j>=0;j--)
            {
                if(dp[j]<ma[i]&&dp[j]!=-1)
                {
                    if(dp[j+1]>ma[i]||dp[j+1]==-1)
                    {
                        if(sum<j+1) sum=j+1;
                        dp[j+1]=ma[i];
                        break;
                    }
                }
            }
        }
        for(int i=a;i>=0;i--)
        {
            if(dp[i]!=-1)
            {
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}
