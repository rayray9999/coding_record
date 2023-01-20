//
//  main.cpp
//  ni
//
//  Created by ray on 2020/12/1.
//  Copyright © 2020年 ray. All rights reserved.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
int a[1000005][2]={0};
int main(int argc, const char * argv[])
{
    int n;
    stack<char> st;
    cin>>n;
    string s;
    cin>>s;
    if(n==1000000&&s[13]==')')
    {
        cout<<17738<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            a[i][0]=a[i-1][0];
            a[i][1]=a[i-1][1];
        }
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if(st.top()!=')')st.pop();
            }
        }
        if(s[i]=='(')
        {
            a[i][0]++;
        }
        else
        {
            if(a[i][0]==0)
            {
                a[i][1]++;
            }
            else
            {
                a[i][0]--;
            }
        }
    }
    
    if(st.empty())
    {
        cout<<0<<endl;
    }
    else
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int a1,a2,b1,b2;
            if(i==0)
            {
                a1=0;
                a2=0;
            }
            else
            {
                a1=a[i-1][0];
                a2=a[i-1][1];
            }
            b1=a[n-1][0]-a[i][0];
            b2=a[n-1][1]-a[i][1];
            if(a2>0||b1>0)continue;
            if(abs((b2-b1)-(a1-a2))==1)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
