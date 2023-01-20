//
//  main.cpp
//  uva124
//
//  Created by ray on 2021/1/15.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<vector>
#include<memory.h>
#include<stdlib.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
vector <int>v[26];
vector <char> ans;
int used[26]={0};
queue <char> q;
bool cmp(char a,char b)
{
    int a1=a-'a',b1=b-'a';
    return a1<b1;
}
void dfs(vector <char>ele,int x)
{
    if(x==ele.size())
    {
        for(int i=0;i<ans.size();i++)cout<<ans[i];
        cout<<endl;
    }
    else
    {
        for(int i=0;i<ele.size();i++)
        {
            if(used[ele[i]-'a']==0)
            {
                bool f=true;
                for(int j=0;j<v[ele[i]-'a'].size();j++)
                {
                    if(used[v[ele[i]-'a'][j]]==0)
                    {
                        f=false;
                        break;
                    }
                }
                if(f)
                {
                    used[ele[i]-'a']=1;
                    ans.push_back(ele[i]);
                    dfs(ele,x+1);
                    ans.pop_back();
                    used[ele[i]-'a']=0;
                }
            }
        }
    }
}
int main(int argc, const char * argv[])
{
    string s;
    bool f=false;
    while(getline(cin,s))
    {
        memset(used,0,sizeof(used));
        if(!f)
        {
            f=true;
        }
        else
        {
            cout<<endl;
        }
        vector <char> ele;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                ele.push_back(s[i]);
            }
           
        }
        sort(ele.begin(),ele.end(),cmp);
        
        getline(cin,s);
        int c=-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                if(c==-1)
                {
                    c=s[i]-'a';
                }
                else
                {
                    v[s[i]-'a'].push_back(c);
                    
                    c=-1;
                }
            }
        }
        dfs(ele,0);
        for(int i=0;i<ele.size();i++)v[ele[i]-'a'].clear();
        
    }
    return 0;
}
