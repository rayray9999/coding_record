//
//  main.cpp
//  uva10702
//
//  Created by 端木竣偉 on 2018/9/28.
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
long long dp[105][1005],ma[105][105],en[105];
int main(int argc, const char * argv[])
{
    int c,s,e,t;
    while(cin>>c>>s>>e>>t)
    {
        if(c==0)
        {
            break;
        }
        memset(dp,0,sizeof(dp));
        memset(ma,0,sizeof(ma));
        memset(en,0,sizeof(en));
        for(int i=1;i<=c;i++)
        {
            for(int j=1;j<=c;j++)
            {
                cin>>ma[i][j];
            }
        }
        for(int i=1;i<=e;i++)
        {
            int ju;
            cin>>ju;
            en[ju]=1;
        }
        for(int i=1;i<=c;i++)
        {
            if(ma[s][i]!=0)
            {
                dp[i][1]=ma[s][i]+dp[s][0];
            }
        }
    
       
        for(int i=2;i<=t;i++)
        {
            for(int x=1;x<=c;x++)
            {
                for(int y=1;y<=c;y++)
                {
                    if(ma[x][y]!=0)
                    {
                        if(dp[y][i]<dp[x][i-1]+ma[x][y])
                        {
                            dp[y][i]=dp[x][i-1]+ma[x][y];
                        }
                    }
                }
            }
                
        }
        int bes=0;
        for(int i=1;i<=c;i++)
        {
            if(en[i]==1)
            {
                if(bes<dp[i][t])
                {
                    bes=dp[i][t];
                }
            }
        }
        
        cout<<bes<<endl;
        
    }
    
    
    
    
    
    
    
    
    
    return 0;
}
