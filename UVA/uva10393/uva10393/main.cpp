//
//  main.cpp
//  uva10393
//
//  Created by ray on 2021/1/14.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<memory.h>
#include <set>
using namespace std;
int main(int argc, const char * argv[])
{
    string s[11]={"","qaz","wsx","edc","rfvtgb"," "," ","yhnujm","ik,","ol.","p;/"};
    int a[300]={0},f,num,no[10];
    while(cin>>f>>num)
    {
        
        vector <string> v;
        memset(a,0,sizeof(a));
        memset(no,0,sizeof(no));
        v.clear();
        for(int i=1;i<=f;i++)
        {
            int k;
            cin>>k;
            no[k]=1;
        }
        for(int i=1;i<=10;i++)
        {
            if(no[i]==0)
            {
                for(int j=0;j<s[i].length();j++)
                {
                    a[s[i][j]]=1;
                }
            }
        }
        int max=0,ans=0;
        for(int i=0;i<num;i++)
        {
            string st;
            cin>>st;
            if(st.length()>=max)
            {
                bool f=true;
                
                for(int j=0;j<st.length();j++)
                {
                    if(a[st[j]]==0)
                    {
                        
                        f=false;
                        break;
                    }
                }
                if(f)
                {
                    
                    if(st.length()==max)
                    {
                        bool ff=true;
                        for(int j=0;j<v.size();j++)
                        {
                            if(v[j]==st)
                            {
                                ff=false;
                                break;
                            }
                        }
                        if(ff)
                        {
                            v.push_back(st);
                            ans++;
                        }
                    }
                    else
                    {
                        max=st.length();
                        v.clear();
                        v.push_back(st);
                        ans=1;
                    }
                }
            }
        }
        sort(v.begin(),v.end());
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<endl;
        }
    }
    return 0;
}
