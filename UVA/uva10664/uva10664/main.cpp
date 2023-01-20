//
//  main.cpp
//  uva10664
//
//  Created by 端木竣偉 on 2018/10/21.
//  Copyright © 2018年 端木竣偉. All rights reserved.
//
#include<bits/stdc++.h>
using namespace std;
bool dp[4005];
int main(int argc, const char * argv[]) {
    int a,num;
    cin>>a;
    string sstr;
    stringstream ss;
    cin.ignore();
    for(int i=1;i<=a;i++)
    {
        memset(dp,0,sizeof(dp));
        dp[0]=true;
        getline(cin,sstr);
        ss.clear();
        ss<<sstr;
        int sum=0;
        while(ss>>num)
        {
            sum=sum+num;
            for(int i=4000;i>=0;i--)
            {
                if(dp[i])
                {
                    dp[i+num]=true;
                }
            }
        }
        if(sum%2==0)
        {
            if(dp[sum/2])
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}
