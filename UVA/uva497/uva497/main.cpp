//
//  main.cpp
//  uva497
//
//  Created by 端木竣偉 on 2018/11/6.
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
#include<sstream>
#include <algorithm>
using namespace std;
int dp[10000],ma[10000];
int main(int argc, const char * argv[])
{
    int a;
    cin>>a;
    cin.ignore();
    for(int ti=1;ti<=a;ti++)
    {
        string tes;
        stringstream ss;
        int bigg=0;
        int roc;
        memset(dp,0,sizeof(dp));
        memset(ma,0,sizeof(ma));
        while(getline(cin,tes))
        {
            if(tes.length()==0)
            {
                break;
            }
            ss<<tes;
            ss>>roc;
            if(bigg<roc)
            {
                bigg=roc;
            }
            int lar=0,poi=0;
            bool fla=false;
            for(int i=roc;i>=1;i--)
            {
                if(dp[i]>lar)
                {
                    lar=dp[i];
                    fla=true;
                      poi=i;
                    
                }
            }
            if(dp[roc]<lar+1)
            {
                dp[roc]=lar+1;
                if(fla==true)
                {
                ma[roc]=poi;
                }
            }
        }
        int poi;
        int lar=0;
        for(int i=1;i<=bigg;i++)
        {
            if(lar<dp[i])
            {
                lar=dp[i];
                poi=i;
            }
        }
        cout<<"Max hits: "<<lar<<endl;
        for(int i=lar;i>=1;i--)
        {
            cout<<poi<<endl;
            poi=ma[poi];
        }
        cout<<endl;
    }
    return 0;
}
