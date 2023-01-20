//
//  main.cpp
//  uva10405
//
//  Created by 端木竣偉 on 2018/10/5.
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
int main(int argc, const char * argv[])
{
    
    long long dp[51]={0},b[51]={0},sum;
    cin>>sum;
    dp[1]=2;
    b[1]=1;
    for(int i=2;i<=50;i++)
    {
        dp[i]=dp[i-1]*2;
        dp[i]=dp[i]-b[i-1];
        b[i]=dp[i-1]-b[i-1];
        
    }
    for(int i=1;i<=sum;i++)
    {
        int a;
        cin>>a;
        cout<<"Scenario #"<<i<<":"<<endl;
        cout<<dp[a]<<endl;
        cout<<endl;
    
    }
    



    return 0;
}
