//
//  main.cpp
//  uva195
//
//  Created by ray on 2020/10/29.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <stdio.h>
#include <ctype.h>
using namespace std;
string s;
char ans[100000];
int used[100000]={0};
bool cmp(char a,char b)
{
    char aa=toupper(a),bb=toupper(b);
    if(aa==bb)
    {
        return (int)a<(int)b;
    }
    else
    {
        return (int)aa<(int)bb;
    }
}
void dfs(int len)
{
    if(len==s.length())
    {
        for(int i=0;i<s.length();i++)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
    else
    {
        char last='\0';
        for(int i=0;i<s.length();i++)
        {
            if(used[i]!=1&&last!=s[i])
            {
                last=s[i];
                used[i]=1;
                ans[len]=s[i];
                dfs(len+1);
                used[i]=0;
            }
        }
    }
}
int main(int argc, const char * argv[])
{
    
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s;
        sort(s.begin(),s.end(),cmp);
        dfs(0);
    }
    return 0;
}
