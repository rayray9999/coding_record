//
//  main.cpp
//  uva136
//
//  Created by ray on 2021/1/8.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    long long dp[1505]={0},a2=1,a3=1,a5=1;
    dp[1]=1;
    for(int i=2;i<=1500;i++)
    {
        long long a=dp[a2]*2,b=dp[a3]*3,c=dp[a5]*5;
        while(a<=dp[i-1])
        {
            a2++;
            a=dp[a2]*2;
        }
        while(b<=dp[i-1])
        {
            a3++;
            b=dp[a3]*3;
        }
        while(c<=dp[i-1])
        {
            a5++;
            c=dp[a5]*5;
        }
        if(a<=b&&a<=c)
        {
            dp[i]=a;
            a2++;
        }
        else if(b<=a&&b<=c)
        {
            dp[i]=b;
            a3++;
        }
        else
        {
            dp[i]=c;
            a5++;
        }
    }
    
    cout<<"The 1500'th ugly number is "<<dp[1500]<<"."<<endl;
    return 0;
}
