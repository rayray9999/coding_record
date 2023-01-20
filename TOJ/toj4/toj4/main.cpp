//
//  main.cpp
//  toj4
//
//  Created by ray on 2019/1/1.
//  Copyright © 2019年 ray. All rights reserved.
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
#include <stdio.h>
using namespace std;
long long ch[1005],ma[1005];
bool used[1005];
int run(long long a)
{
    long long m=0;
    while(a)
    {
        if(a%2!=0) m++;
        a/=2;
    }
    return m;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,o=1;
    cin>>t;
    while(o<=t)
    {
        int n,l;
        cin>>n>>l;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            long long k=1;
            ma[i]=0;
            for(int j=1;j<=l;j++)
            {
                if(s[l-j]=='1')
                {
                    ma[i]+=k;
                }
                 k*=2;
            }
        }
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            long long k=1;
            ch[i]=0;
            for(int j=1;j<=l;j++)
            {
                if(s[l-j]=='1')
                {
                    ch[i]+=k;
                }
                k*=2;
            }
        
        }
        int sum=-1;
        for(int i=1;i<=n;i++)
        {
            long long g;
            bool tt=false;
            g=ma[1]^ch[i];
            memset(used,0,sizeof(used));
            used[i]=true;
            for(int j=2;j<=n;j++)
            {
                bool a=false;
                long long p=ma[j]^g;
                
                for(int k=1;k<=n;k++)
                {
                    if(!used[k])
                    {
                        
                        if(p==ch[k])
                        {
                            used[k]=true;
                            k=n+1;
                            a=true;
                        }
                        
                    }
                }
                
                if(!a)
                {
                    j=n+1;
                }
            
                if(j==n&&a)
                {
                    tt=true;
                    
                }
            }
            
            if(tt)
            {
                if(sum==-1||sum>run(g)) sum=run(g);
                
                if(sum==0) break;
            }
            
        }
    
        if(sum==-1)
        {
            cout<<"Case #"<<o<<": IMPOSSIBLE"<<endl;
        }
        else
        {
            cout<<"Case #"<<o<<": "<<sum<<endl;
        }
        
        
        o++;
    }
    
    return 0;
}
