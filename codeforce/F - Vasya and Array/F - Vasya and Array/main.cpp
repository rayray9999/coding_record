//
//  main.cpp
//  F - Vasya and Array
//
//  Created by ray on 2018/12/31.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
long long a[100005],dp[100005][105],sdp[100005];
bool bad[100005][100];
int main(int argc, const char * argv[])
{
    int n,k,len;
    cin>>n>>k>>len;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    for(int i=1;i<=k;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==i||a[j]==-1)
            {
                cnt++;
            }
            else
            {
                cnt=0;
            }
            
            if(cnt>=len)
            {
                bad[j][i]=true;
            }
        }
    }
    sdp[0]=1;
    if(len==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(a[i]==j||a[i]==-1)
            {
                dp[i][j]=sdp[i-1];
                if(bad[i][j])
                {
                    dp[i][j] = (dp[i][j] - (sdp[i - len] - dp[i - len][j]))%998244353;
                }
            }
            else
            {
                dp[i][j]=0;
            }
            sdp[i]+=dp[i][j]%998244353;
        }
    }
    cout<<((sdp[n]%998244353)+998244353)%998244353<<endl;
    return 0;
}
