//
//  main.cpp
//  toj9
//
//  Created by ray on 2019/1/23.
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
using namespace std;


int an[10005],ma[10005],sur[10005],surr[10005];
vector<int> vec[10005],dis[10005];
int main()
{
    typedef pair<int,int> pii;
    queue<pii> q,qq;
    int t,yyy=1;
    cin>>t;
    while(yyy<=t)
    {
        int n,m,s,dee=-1;
        cin>>n>>m>>s;
        memset(ma,-1,sizeof(ma));
        memset(sur,0,sizeof(sur));
        memset(surr,0,sizeof(surr));
        for(int i=0;i<n;i++)
        {
            vec[i].clear();
            dis[i].clear();
        }
        for(int i=0;i<n;i++)
        {
            cin>>an[i];
            if(dee==-1||dee>an[i]) dee=an[i];
        }
        
        if(an[s]==dee)
        {
            cout<<"Case #"<<yyy<<": 0"<<endl;
            yyy++;
            continue;
        }
        for(int i=1;i<=m;i++)
        {
            int j,k;
            cin>>j>>k;
            if(an[j]>an[k]) swap(j,k);
            vec[j].push_back(k);
            vec[k].push_back(j);
            if(an[j]==an[k])
            {
                if(ma[j]==-1)
                {
                        ma[j]=k;
                        dis[j].push_back(k);
                }
                
            }
            if(an[k]-an[j]>=an[k]-an[ma[k]]||ma[k]==-1)
            {
                if(an[k]-an[j]==an[k]-an[ma[k]])
                {
                    dis[k].push_back(j);
                }
                else
                {
                    if(!dis[k].empty()) dis[k].clear();
                    ma[k]=j;
                    dis[k].push_back(j);
                }
            }
        }
        
        
        
        int min=0;
        bool t=true;
        if(!qq.empty()) qq.pop();
        qq.push(make_pair(s,0));
        while(!qq.empty())
        {
            int i,j;
            i=qq.front().first;
            j=qq.front().second;
            qq.pop();
            while(!dis[i].empty())
            {
                int v=dis[i].back();
                dis[i].pop_back();
                if(!surr[v])
                {
                    surr[v]=1;
                    qq.push(make_pair(v,j+1));
                    if(an[v]==dee)
                    {
                        t=0;
                        min=j+1;
                        break;
                    }
                }
                
            }
            if(!t) break;
        }
        if(t) min=0;
        bool f=false;
        int ti=0;
        q.push(make_pair(s,0));
        sur[s]=1;
        while(!f&&!q.empty())
        {
            
            int i,j;
            i=q.front().first;
            j=q.front().second;
            q.pop();
            while(!vec[i].empty())
            {
                int v=vec[i].back();
                vec[i].pop_back();
                if(!sur[v])
                {
                    sur[v]=1;
                    q.push(make_pair(v,j+6));
                    if(an[v]==dee)
                    {
                        
                        f=true;
                        ti=j+6;
                        break;
                    }
                }
            }
            
        }
        if(!q.empty()) q.pop();
        
        if(!f)
        {
            cout<<"Case #"<<yyy<<": Call 119!"<<endl;
        }
        else
        {
            cout<<"Case #"<<yyy<<": "<<abs(ti-min)<<endl;
        }
        yyy++;
        
        while(!q.empty()) q.pop();
        
    }
    
    
    
    return 0;
}
