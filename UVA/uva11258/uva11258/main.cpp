//
//  main.cpp
//  uva11258
//
//  Created by 端木竣偉 on 2018/10/17.
//  Copyright © 2018年 端木竣偉. All rights reserved.
//

#include <iostream>
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
long long dp[505];
int main()
{
    long long a,lun,big;
    string str;
    cin>>a;
    big=2147483647;
    for (int i=1;i<=a;i++)
    {
        cin>>str;
        lun=str.length();
        memset(dp,0, sizeof(dp));
        dp[0]=0;
        dp[1]=str[0]-'0';
        for(int dl=2;dl<=lun;dl++)
        {
            long long sum=0,ba=1;
            for(int j=1;j<=10;j++)
            {
                sum=sum+(str[dl-j]-'0')*ba;
                ba=ba*10;
                if(dl-j<0||sum>big)
                {
                    break;
                }
                if(dp[dl]<dp[dl-j]+sum)
                {
                    dp[dl]=dp[dl-j]+sum;
                }
            }
        }
        cout<<dp[lun]<<endl;
    }
    return 0;
}
