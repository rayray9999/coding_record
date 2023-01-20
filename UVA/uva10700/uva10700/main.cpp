//
//  main.cpp
//  uva10700
//
//  Created by ray on 2019/1/24.
//  Copyright © 2019年 ray. All rights reserved.
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
int main(int argc, const char * argv[])
{
    int n;
    string trash;
    cin>>n;
    getline(cin,trash);
    for(int i=1;i<=n;i++)
    {
        string s;
        getline(cin,s);
        long long ma=1,mi=0;
        long long s1=0,s2=0;
        vector<long long> vec;
        vec.clear();
        for(int i=0;i<s.length();i++)
        {
            if(s[i]<='9'&&s[i]>='0')
            {
                s2=s2*10+s[i]-'0';
            }
            else
            {
                if(s[i]=='+')
                {
                    s1+=s2;
                    s2=0;
                }
                else
                {
                    s1+=s2;
                    vec.push_back(s1);
                    s1=0;
                    s2=0;
                }
                
            }
        }
        s1+=s2;
        s2=0;
        vec.push_back(s1);
        s1=0;
        while(!vec.empty())
        {
            
            long long v;
            v=vec.back();
            vec.pop_back();
            ma*=v;
        }
        char c='-';
        for(int i=0;i<s.length();i++)
        {
            if(s[i]<='9'&&s[i]>='0')
            {
                s2=s2*10+s[i]-'0';
            }
            else
            {
                if(s[i]=='+')
                {
                    if(c=='*')
                    {
                        vec.push_back(s1*s2);
                        s1=0;
                    }
                    else
                    {
                        vec.push_back(s2);
                    }
                    s2=0;
                }
                else
                {
                    if(s1!=0)s1*=s2;
                    else s1=s2;
                    s2=0;
                }
                c=s[i];
            }
        }
        if(c=='+')
        {
           vec.push_back(s2);
        }
        else
        {
            if(s2!=0) s1*=s2;
            
            vec.push_back(s1);
        }
        
        while(!vec.empty())
        {
            long long v;
            v=vec.back();
            vec.pop_back();
            mi+=v;
        }
        cout<<"The maximum and minimum are "<<ma<<" and "<<mi<<"."<<endl;
    }
    return 0;
}



