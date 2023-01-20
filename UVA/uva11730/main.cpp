
//
//  main.cpp
//  uva11730
//
//  Created by 端木竣偉 on 2018/9/23.
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
int pri[1001]={0};
int main(int argc, const char * argv[])
{
    int s,t;
    bool fl=false;
    pri[2]=1;
    for (int i=3; i<=1000; i+=2)
    {
        fl=false;
        for (int j=3;j<=i/2 ; j+=2)
        {
            if(i%j==0)
            {
                fl=true;
            }
        }
        if(!fl)
        {
            pri[i]=1;
        }
    }
    int tim=0;
    while(cin>>s>>t)
    {
        queue<int> q1,q2;
        q1 = queue<int>();
        q2 = queue<int>();
        int ss,tt;
        bool ca=false;
        tim++;
        if(s==0&&t==0)
        {
            break;
        }
        q1.push(s);
        q2.push(0);
        while(!q1.empty())
        {
            ss=q1.front();
            q1.pop();
            tt=q2.front();
            q2.pop();
            if(pri[ss]==0)
            {
                
                for(int i=2;i<=ss/2;i++)
                {
                    if(pri[i]==1)
                    {
                        if(ss%pri[i]==0)
                        {
                            if((ss+i)<=t)
                            {
                                
                            q1.push(ss+i);
                            q2.push(tt+1);
                            if(ss+i==t)
                            {
                                tt++;
                                ca=true;
                                break;
                            }
                                
                            }
                            
                        }
                    }
                }
            }
            if(ca)
            {
                break;
            }
        }
        if(ca)
        {
            cout<<"Case "<<tim<<": "<<tt<<endl;
        }
        else
        {
            cout<<"Case "<<tim<<": -1"<<endl;
        }
    }
    
    return 0;
}
