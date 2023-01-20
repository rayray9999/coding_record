//
//  main.cpp
//  uva481
//
//  Created by ray on 2020/12/5.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;
int dp[1000005]={0};
int ans[1000005]={0};
int a[1000005]={0};
int main(int argc, const char * argv[])
{
    int len=0,x,u=0;
    while(cin>>x)
    {
        a[u]=x;
        u++;
    }
    if(u==0)
    {
        cout<<"0"<<endl;
        cout<<"-"<<endl;
    }
    else
    {
        dp[1]=a[0];
        len++;
        for(int i=1;i<u;i++)
        {
            if(dp[len]<a[i])
            {
                len++;
                dp[len]=a[i];
                ans[i]=len;
            }
            else
            {
                for(int j=len;j>0;j--)
                {
                    if(dp[j]>a[i])
                    {
                        if(a[i]>dp[j-1])
                        {
                            dp[j]=a[i];
                            ans[i]=j;
                        }
                    }
                }
            }
        }
        int k=len;
        for(int i=u-1;i>=0;i--)
        {
            if(ans[i]==k)
            {
                dp[k]=a[i];
                k--;
            }
        }
        cout<<len<<endl;
        cout<<"-"<<endl;
        for(int i=1;i<=len;i++)
        {
            cout<<dp[i]<<endl;
        }
    }
    return 0;
}
