//
//  main.cpp
//  uva10130
//
//  Created by 端木竣偉 on 2018/11/2.
//  Copyright © 2018年 端木竣偉. All rights reserved.
//

#include <iostream>
#include<sstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int dp[31],ma[1005][2];
int main(int argc, const char * argv[]) {
    int a;
    cin>>a;
    while(a>0)
    {
        int acc;
        long long sum=0;
        memset(ma,0,sizeof(ma));
        memset(dp,-1,sizeof(dp));
        cin>>acc;
        for(int i=1;i<=acc;i++)
        {
            cin>>ma[i][0];
            cin>>ma[i][1];
        }
        int peo,wei;
        cin>>peo;
        for (int i=1;i<=peo;i++)
        {
            cin>>wei;
            dp[0]=0;
            for(int j=1;j<=acc;j++)
          {
            for (int k=wei; k>=0;k--)
            {
                if(dp[k]>=0)
                {
                    if((k+ma[j][1])<=wei)
                    {
                        dp[k+ma[j][1]]=max(dp[k]+ma[j][0],dp[k+ma[j][1]]);
                    }
                }
            }
          }
            int sesu=0;
            for(int i=0;i<=wei;i++)
            {
                if(sesu<dp[i])
                {
                    sesu=dp[i];
                }
            }
            sum=sum+sesu;
          memset(dp,-1,sizeof(dp));
        }
        cout<<sum<<endl;
        a--;
    }
    return 0;
}
