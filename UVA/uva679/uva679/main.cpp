//
//  main.cpp
//  uva679
//
//  Created by 端木竣偉 on 2018/10/26.
//  Copyright © 2018年 端木竣偉. All rights reserved.
//

#include <iostream>
int dp[7495],a[5]={1,5,10,25,50};
using namespace std;
int main(int argc, const char * argv[])
{
    int s;
    dp[0]=1;
    for(int i=0;i<=4;i++)
    {
        for(int j=a[i];j<=7489;j++)
        {
            dp[j]+=dp[j-a[i]];
        }
    }
    while(cin>>s)
    {
        cout<<dp[s]<<endl;
    }
    return 0;
}
