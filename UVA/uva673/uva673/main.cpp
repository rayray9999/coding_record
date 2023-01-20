//
//  main.cpp
//  uva673
//
//  Created by ray on 2021/1/18.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<stack>
#include<string>
using namespace std;
int main(int argc, const char * argv[])
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        stack<char> sta;
        bool f=true;
        getline(cin,s);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='[')
            {
                sta.push(s[i]);
            }
            else
            {
                if(s[i]==')')
                {
                    if(sta.empty()||sta.top()!='(')
                    {
                        f=false;
                        break;
                    }
                    else
                    {
                        sta.pop();
                    }
                }
                else
                {
                    if(sta.empty()||sta.top()!='[')
                    {
                        f=false;
                        break;
                    }
                    else
                    {
                        sta.pop();
                    }
                }
            }
        }
        if(f&&sta.empty())
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
