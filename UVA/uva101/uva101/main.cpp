//
//  main.cpp
//  uva101
//
//  Created by ray on 2020/11/19.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
int main(int argc, const char * argv[])
{
    int n;
    while(cin>>n)
    {
        vector<int> v[25];
        int pla[25];
        for(int i=0;i<n;i++)
        {
            v[i].push_back(i);
            pla[i]=i;
        }
        string s;
        while(cin>>s)
        {
            if(s=="move")
            {
                int a,b;
                cin>>a>>s>>b;
                if(a==b||pla[a]==pla[b])continue;
                if(s=="onto")
                {
                    while(v[pla[a]].back()!=a)
                    {
                        int q=v[pla[a]].back();
                        v[q].push_back(q);
                        v[pla[a]].pop_back();
                        pla[q]=q;
                    }
                    while(v[pla[b]].back()!=b)
                    {
                        int q=v[pla[b]].back();
                        v[q].push_back(q);
                        v[pla[b]].pop_back();
                        pla[q]=q;
                    }
                     v[pla[b]].push_back(a);
                     v[pla[a]].pop_back();
                     pla[a]=pla[b];
                }
                else
                {
                    while(v[pla[a]].back()!=a)
                    {
                        int q=v[pla[a]].back();
                        v[q].push_back(q);
                        v[pla[a]].pop_back();
                        pla[q]=q;
                    }
                    v[pla[b]].push_back(a);
                    v[pla[a]].pop_back();
                    pla[a]=pla[b];
                }
            }
            else if(s=="pile")
            {
                int a,b;
                cin>>a>>s>>b;
                if(a==b||pla[a]==pla[b])continue;
                if(s=="onto")
                {
                    while(v[pla[b]].back()!=b)
                    {
                        int q=v[pla[b]].back();
                        v[q].push_back(q);
                        v[pla[b]].pop_back();
                        pla[q]=q;
                    }
                    bool f=false;
                    for(int i=0;i<v[pla[a]].size();i++)
                    {
                        if(v[pla[a]][i]==a)f=true;
                        if(f)
                        {
                            v[pla[b]].push_back(v[pla[a]][i]);
                        }
                    }
                    while(v[pla[a]].back()!=a)
                    {
                        int q=v[pla[a]].back();
                        v[pla[a]].pop_back();
                        pla[q]=pla[b];
                    }
                    v[pla[a]].pop_back();
                    pla[a]=pla[b];
                }
                else
                {
                    bool f=false;
                    for(int i=0;i<v[pla[a]].size();i++)
                    {
                        if(v[pla[a]][i]==a)f=true;
                        if(f)
                        {
                            v[pla[b]].push_back(v[pla[a]][i]);
                        }
                    }
                    while(v[pla[a]].back()!=a)
                    {
                        int q=v[pla[a]].back();
                        v[pla[a]].pop_back();
                        pla[q]=pla[b];
                    }
                    v[pla[a]].pop_back();
                    pla[a]=pla[b];
                }
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    cout<<i<<":";
                    for(int j=0;j<v[i].size();j++)
                    {
                        cout<<" "<<v[i][j];
                    }
                    cout<<endl;
                }
                break;
            }
        }
    }
    
    return 0;
}
